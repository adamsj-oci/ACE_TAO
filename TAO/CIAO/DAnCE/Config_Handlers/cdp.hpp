/* $Id$
 * This code was generated by the XML Schema Compiler.
 *
 * Changes made to this code will most likely be overwritten
 * when the handlers are recompiled.
 * 
 * If you find errors or feel that there are bugfixes to be made,
 * please contact the current XSC maintainer:
 *             Will Otte <wotte@dre.vanderbilt.edu>
 */


// Fixes the VC6 warning 4786.
#include "vc6-4786.h"
 
// Fix for Borland compilers, which seem to have a broken
// <string> include.
#ifdef __BORLANDC__
# include <string.h>
#endif

#include "Config_Handlers_Export.h"
#ifndef CDP_HPP
#define CDP_HPP

// Forward declarations.
//
namespace CIAO
{
  namespace Config_Handlers
  {
    class DeploymentPlan;
  }
}

#include <memory>
#include <vector>
#include "XMLSchema/Types.hpp"

#include "ccd.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    class Config_Handlers_Export DeploymentPlan : public ::XSCRT::Type
    {
      //@@ VC6 anathema
      typedef ::XSCRT::Type Base__;

      // label
      // 
      public:
      bool label_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& label () const;
      ::XMLSchema::string< ACE_TCHAR >& label ();
      void label (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > label_;

      // UUID
      // 
      public:
      bool UUID_p () const;
      ::XMLSchema::string< ACE_TCHAR > const& UUID () const;
      ::XMLSchema::string< ACE_TCHAR >& UUID ();
      void UUID (::XMLSchema::string< ACE_TCHAR > const& );

      protected:
      ::std::auto_ptr< ::XMLSchema::string< ACE_TCHAR > > UUID_;

      // realizes
      // 
      public:
      bool realizes_p () const;
      ::CIAO::Config_Handlers::ComponentInterfaceDescription const& realizes () const;
      ::CIAO::Config_Handlers::ComponentInterfaceDescription& realizes ();
      void realizes (::CIAO::Config_Handlers::ComponentInterfaceDescription const& );

      protected:
      ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentInterfaceDescription > realizes_;

      // implementation
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::MonolithicDeploymentDescription >::iterator implementation_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::MonolithicDeploymentDescription >::const_iterator implementation_const_iterator;
      implementation_iterator begin_implementation ();
      implementation_iterator end_implementation ();
      implementation_const_iterator begin_implementation () const;
      implementation_const_iterator end_implementation () const;
      void add_implementation (::CIAO::Config_Handlers::MonolithicDeploymentDescription const& );

      protected:
      ::std::vector< ::CIAO::Config_Handlers::MonolithicDeploymentDescription > implementation_;

      // instance
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::InstanceDeploymentDescription >::iterator instance_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::InstanceDeploymentDescription >::const_iterator instance_const_iterator;
      instance_iterator begin_instance ();
      instance_iterator end_instance ();
      instance_const_iterator begin_instance () const;
      instance_const_iterator end_instance () const;
      void add_instance (::CIAO::Config_Handlers::InstanceDeploymentDescription const& );

      protected:
      ::std::vector< ::CIAO::Config_Handlers::InstanceDeploymentDescription > instance_;

      // connection
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::PlanConnectionDescription >::iterator connection_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::PlanConnectionDescription >::const_iterator connection_const_iterator;
      connection_iterator begin_connection ();
      connection_iterator end_connection ();
      connection_const_iterator begin_connection () const;
      connection_const_iterator end_connection () const;
      void add_connection (::CIAO::Config_Handlers::PlanConnectionDescription const& );

      protected:
      ::std::vector< ::CIAO::Config_Handlers::PlanConnectionDescription > connection_;

      // dependsOn
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::ImplementationDependency >::iterator dependsOn_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::ImplementationDependency >::const_iterator dependsOn_const_iterator;
      dependsOn_iterator begin_dependsOn ();
      dependsOn_iterator end_dependsOn ();
      dependsOn_const_iterator begin_dependsOn () const;
      dependsOn_const_iterator end_dependsOn () const;
      void add_dependsOn (::CIAO::Config_Handlers::ImplementationDependency const& );

      protected:
      ::std::vector< ::CIAO::Config_Handlers::ImplementationDependency > dependsOn_;

      // artifact
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::ArtifactDeploymentDescription >::iterator artifact_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::ArtifactDeploymentDescription >::const_iterator artifact_const_iterator;
      artifact_iterator begin_artifact ();
      artifact_iterator end_artifact ();
      artifact_const_iterator begin_artifact () const;
      artifact_const_iterator end_artifact () const;
      void add_artifact (::CIAO::Config_Handlers::ArtifactDeploymentDescription const& );

      protected:
      ::std::vector< ::CIAO::Config_Handlers::ArtifactDeploymentDescription > artifact_;

      // infoProperty
      // 
      public:
      typedef ::std::vector< ::CIAO::Config_Handlers::Property >::iterator infoProperty_iterator;
      typedef ::std::vector< ::CIAO::Config_Handlers::Property >::const_iterator infoProperty_const_iterator;
      infoProperty_iterator begin_infoProperty ();
      infoProperty_iterator end_infoProperty ();
      infoProperty_const_iterator begin_infoProperty () const;
      infoProperty_const_iterator end_infoProperty () const;
      void add_infoProperty (::CIAO::Config_Handlers::Property const& );

      protected:
      ::std::vector< ::CIAO::Config_Handlers::Property > infoProperty_;

      public:
      DeploymentPlan (::CIAO::Config_Handlers::ComponentInterfaceDescription const& realizes__);

      DeploymentPlan (::XSCRT::XML::Element< ACE_TCHAR > const&);
      DeploymentPlan (DeploymentPlan const& s);

      DeploymentPlan&
      operator= (DeploymentPlan const& s);

      private:
      char regulator__;
    };
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#endif // CDP_HPP
