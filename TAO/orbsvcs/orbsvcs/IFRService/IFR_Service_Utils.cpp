// $Id$

#include "IFR_Service_Utils.h"
#include "orbsvcs/orbsvcs/IFRService/ComponentRepository_i.h"
#include "orbsvcs/orbsvcs/IFRService/Servant_Locator.h"
#include "orbsvcs/orbsvcs/IFRService/Options.h"
#include "orbsvcs/orbsvcs/IFRService/IFR_ComponentsS.h"
#include "orbsvcs/IOR_Multicast.h"
#include "tao/IORTable/IORTable.h"
#include "tao/ORB_Core.h"
#include "tao/default_ports.h"
#include "ace/Auto_Ptr.h"

ACE_RCSID (IFR_Service,
           IFR_Service,
           "$Id$")

TAO_IFR_Server::TAO_IFR_Server (void)
  : servant_locator_impl_ (0),
    ior_multicast_ (0),
    config_ (0),
    repo_impl_ (0),
    repository_ (CORBA_Repository::_nil ())
{
}

TAO_IFR_Server::~TAO_IFR_Server (void)
{
  // Get reactor instance from TAO.
  ACE_Reactor *reactor = this->orb_->orb_core ()->reactor ();

  if ( this->ior_multicast_ )
  {
    // Remove event handler for the ior multicast.
    if (reactor->remove_handler (this->ior_multicast_,
                                 ACE_Event_Handler::READ_MASK)
         == -1)
      {
        ACE_DEBUG ((
            LM_DEBUG,
            ACE_TEXT ("Interface Repository: cannot remove handler\n")
          ));
      }
  }

  CORBA::release (this->repository_);
  delete this->config_;
  delete this->ior_multicast_;
}

int
TAO_IFR_Server::init_with_orb (int argc,
                            ACE_TCHAR *argv [],
                            CORBA::ORB_ptr orb,
                            int use_multicast_server)
{
  ACE_DECLARE_NEW_CORBA_ENV;
  ACE_TRY
    {
      // Duplicate the ORB.
      this->orb_ = CORBA::ORB::_duplicate (orb);

      // Get the POA from the ORB.
      CORBA::Object_var poa_object =
        orb->resolve_initial_references ("RootPOA" 
                                         ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (poa_object.in ()))
        {
          ACE_ERROR_RETURN ((
              LM_ERROR,
              ACE_LIB_TEXT ("(%P|%t) Unable to initialize the POA.\n")
            ),
            -1
          );
        }
      this->root_poa_ =
        PortableServer::POA::_narrow (poa_object.in ()
                                      ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      int retval = OPTIONS::instance()->parse_args (argc,
                                                    argv);

      if (retval != 0)
        return retval;

      retval = this->create_poas (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (retval != 0)
        return retval;

      retval = this->open_config (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (retval != 0)
        return retval;

      retval = this->create_repository (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (retval != 0)
        return retval;

      retval = this->create_locator (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (retval != 0)
        return retval;

      if (use_multicast_server)
      {
        retval = this->init_multicast_server (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_TRY_CHECK;

        if (retval != 0)
          return retval;
      }
      ACE_DEBUG ((LM_DEBUG,
                  "The IFR IOR is: <%s>\n",
                  this->ifr_ior_.in ()));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "IFR_Service::init");

      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);
  return 0;
}

int
TAO_IFR_Server::fini (void)
{
  ACE_TRY_NEW_ENV
    {
      this->root_poa_->destroy (1,
                                1
                                ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "TAO_IFR_Server::fini");
      ACE_RE_THROW;
    }
  ACE_ENDTRY;
  return 0;
}

int
TAO_IFR_Server::create_poas (ACE_ENV_SINGLE_ARG_DECL)
{
  PortableServer::POAManager_var poa_manager =
    this->root_poa_->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  poa_manager->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  CORBA::PolicyList policies (4);
  policies.length (1);

  // So the Repository's POA can survive a crash.
  policies[0] =
    this->root_poa_->create_lifespan_policy (PortableServer::PERSISTENT
                                             ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  ACE_TString repo_name = "repoPOA";

  this->repo_poa_ =
    this->root_poa_->create_POA (repo_name.c_str (),
                                 poa_manager.in (),
                                 policies
                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  policies.length (4);

  // So we can create object ids based on the DefinitionKind.
  policies[1] =
    this->root_poa_->create_id_assignment_policy (
                         PortableServer::USER_ID
                         ACE_ENV_ARG_PARAMETER
                       );
  ACE_CHECK_RETURN (-1);

  // We'll use a servant manager.
  policies[2] =
    this->root_poa_->create_request_processing_policy (
                         PortableServer::USE_SERVANT_MANAGER
                         ACE_ENV_ARG_PARAMETER
                       );
  ACE_CHECK_RETURN (-1);

  // Specifically, we'll use a servant locator.
  policies[3] =
    this->root_poa_->create_servant_retention_policy (
                         PortableServer::NON_RETAIN
                         ACE_ENV_ARG_PARAMETER
                       );
  ACE_CHECK_RETURN (-1);

  ACE_TString name = "ir_objectPOA";

  this->ir_object_poa_ =
    this->root_poa_->create_POA (name.c_str (),
                                 poa_manager.in (),
                                 policies
                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  // Destroy the policy objects as they have been passed to
  // create_POA and no longer needed.
  CORBA::ULong length = policies.length ();

  for (CORBA::ULong i = 0; i < length; ++i)
    {
      CORBA::Policy_ptr policy = policies[i];
      policy->destroy (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_CHECK_RETURN (-1);
    }

  return 0;
}

int
TAO_IFR_Server::create_locator (ACE_ENV_SINGLE_ARG_DECL)
{
  ACE_NEW_THROW_EX (this->servant_locator_impl_,
                    IFR_ServantLocator (this->repo_impl_),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (-1);

  this->ir_object_poa_->set_servant_manager (this->servant_locator_impl_
                                             ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  return 0;
}

int
TAO_IFR_Server::open_config (ACE_ENV_SINGLE_ARG_DECL)
{
  if (OPTIONS::instance ()->using_registry ())
    {
#if defined (ACE_WIN32)
      HKEY root =
        ACE_Configuration_Win32Registry::resolve_key (
            HKEY_LOCAL_MACHINE,
            "Software\\TAO\\IFR"
          );

      ACE_NEW_THROW_EX (this->config_,
                        ACE_Configuration_Win32Registry (root),
                        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN (-1);
#endif /* ACE_WIN32 */

      return 0;
    }
  else
    {
      ACE_Configuration_Heap *heap = 0;
      ACE_NEW_THROW_EX (heap,
                        ACE_Configuration_Heap,
                        CORBA::NO_MEMORY ());
      ACE_CHECK_RETURN (-1);

      if (OPTIONS::instance ()->persistent ())
        {
          const char *filename = OPTIONS::instance ()->persistent_file ();

          if (heap->open (filename))
            {
              ACE_ERROR_RETURN ((
                  LM_ERROR,
                  ACE_TEXT ("Error:: Opening persistent heap file '%s'\n"),
                  filename
                ),
                -1
              );
            }
        }
      else
        {
          heap->open ();
        }

      this->config_ = heap;

      return 0;
    }
}

int
TAO_IFR_Server::create_repository (ACE_ENV_SINGLE_ARG_DECL)
{
  TAO_ComponentRepository_i *impl = 0;
  ACE_NEW_THROW_EX (
      impl,
      TAO_ComponentRepository_i (
          this->orb_.in (),
          this->ir_object_poa_.in (),
          this->config_
        ),
      CORBA::NO_MEMORY ()
    );
  ACE_CHECK_RETURN (-1);

  auto_ptr<TAO_ComponentRepository_i> safety (impl);

  POA_IR::ComponentRepository_tie<TAO_ComponentRepository_i> *impl_tie = 0;
  ACE_NEW_THROW_EX (
      impl_tie,
      POA_IR::ComponentRepository_tie<TAO_ComponentRepository_i> (
          impl,
          this->repo_poa_.in (),
          1
        ),
      CORBA::NO_MEMORY ()
    );
  ACE_CHECK_RETURN (-1);

  PortableServer::ServantBase_var tie_safety (impl_tie);
  safety.release ();

  this->repo_impl_ = impl;

  PortableServer::ObjectId_var repo_oid =
    this->repo_poa_->activate_object (impl_tie
                                      ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  this->repository_ = impl_tie->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);


  impl->repo_objref (this->repository_);

  // Save and output the IOR string.
  this->ifr_ior_ =
    this->orb_->object_to_string (this->repository_
                                  ACE_ENV_ARG_PARAMETER);

  ACE_CHECK_RETURN (-1);

  CORBA::Object_var table_object =
    this->orb_->resolve_initial_references ("IORTable" 
                                            ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  IORTable::Table_var adapter =
    IORTable::Table::_narrow (table_object.in () 
                              ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (-1);

  if (CORBA::is_nil (adapter.in ()))
    {
      ACE_ERROR_RETURN ((LM_ERROR, "Nil IORTable\n"), -1);
    }
  else
    {
      adapter->bind ("InterfaceRepository",
                     this->ifr_ior_.in ()
                     ACE_ENV_ARG_PARAMETER);
      ACE_CHECK_RETURN (-1);
    }

  // Add the repository to the ORB's table of initialized object references.
  this->orb_->register_initial_reference ("InterfaceRepository", 
                                          this->repository_ 
                                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN(-1);

  FILE *output_file_ =
    ACE_OS::fopen (OPTIONS::instance()->ior_output_file (),
                   "w");

  ACE_OS::fprintf (output_file_,
                   "%s",
                   this->ifr_ior_.in ());

  ACE_OS::fclose (output_file_);

  return 0;
}

// Install ior multicast handler.
int
TAO_IFR_Server::init_multicast_server (ACE_ENV_SINGLE_ARG_DECL)
{
  // Get reactor instance from TAO.
  ACE_Reactor *reactor = this->orb_->orb_core ()->reactor ();

#if defined (ACE_HAS_IP_MULTICAST)

  // See if the -ORBMulticastDiscoveryEndpoint option was specified.
  ACE_CString mde (
      TAO_ORB_Core_instance ()->orb_params ()->mcast_discovery_endpoint ()
    );

  // First, see if the user has given us a multicast port number
  // on the command-line;
  u_short port =
    TAO_ORB_Core_instance ()->orb_params ()->service_port (
                                                 INTERFACEREPOSERVICE
                                               );

  if (port == 0)
    {
      // Check environment var. for multicast port.
      const char *port_number =
        ACE_OS::getenv ("InterfaceRepoServicePort");

      if (port_number != 0)
        port = ACE_OS::atoi (port_number);
    }

  // Port wasn't specified on the command-line or in environment -
  // use the default.
  if (port == 0)
    port = TAO_DEFAULT_INTERFACEREPO_SERVER_REQUEST_PORT;

  // Instantiate a handler which will handle client requests for
  // the IFR ior, received on the multicast port.
  ACE_NEW_THROW_EX (this->ior_multicast_,
                    TAO_IOR_Multicast (),
                    CORBA::NO_MEMORY ());
  ACE_CHECK_RETURN (-1);

  if (mde.length () != 0)
    {
      if (this->ior_multicast_->init (this->ifr_ior_.in (),
                                      mde.c_str (),
                                      TAO_SERVICEID_INTERFACEREPOSERVICE)
           == -1)
        {
          ACE_ERROR_RETURN ((
              LM_ERROR,
              ACE_TEXT ("Interface Repository: cannot initialize ")
              ACE_TEXT ("multicast event handler\n")
            ),
            -1
          );
        }
    }
  else
    {
      if (this->ior_multicast_->init (this->ifr_ior_.in (),
                                      port,
                                      ACE_DEFAULT_MULTICAST_ADDR,
                                      TAO_SERVICEID_INTERFACEREPOSERVICE)
           == -1)
        {
          ACE_ERROR_RETURN ((
              LM_ERROR,
              ACE_TEXT ("Interface Repository: cannot initialize ")
              ACE_TEXT ("multicast event handler\n")
            ),
            -1
          );
        }
    }

  // Register event handler for the ior multicast.
  if (reactor->register_handler (this->ior_multicast_,
                                 ACE_Event_Handler::READ_MASK)
       == -1)
    {
      ACE_ERROR_RETURN ((
          LM_ERROR,
          ACE_TEXT ("Interface Repository: cannot register ")
          ACE_TEXT ("multicast event handler\n")
        ),
        -1
      );
    }

#endif /* ACE_HAS_IP_MULTICAST */

  return 0;
}
