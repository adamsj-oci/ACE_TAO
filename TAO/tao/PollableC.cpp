/* -*- C++ -*- */
//
// $Id$
//
// ================================================================
//
// = LIBRARY
//   TAO
//
// = FILENAME
//   PollableC.cpp
//
// = DESCRIPTION
//   Generated from Pollable.pidl
//   The code was generated by the IDL compiler and then hand-crafted
//   to reduce the includes interdependencies.
//
// ================================================================

#include "tao/PollableC.h"

#if defined (TAO_HAS_CORBA_MESSAGING) && defined (TAO_HAS_AMI_POLLER)

#include "tao/POA_CORBA.h"
#include "tao/Stub.h"
#include "tao/Invocation.h"
#include "tao/Any.h"

#if !defined (__ACE_INLINE__)
#include "tao/PollableC.i"
#endif /* !defined INLINE */

ACE_RCSID(tao, PollableC, "$Id$")

CORBA_Pollable_ptr CORBA_Pollable::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_Pollable::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:omg.org/CORBA/Pollable:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA_Pollable::_nil ());
  if (is_a == 0)
    return CORBA_Pollable::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/Pollable:1.0");
  if (servant == 0)
    {
      CORBA_Pollable_ptr rval = CORBA_Pollable::_nil ();

      ACE_NEW_RETURN (rval,
                      CORBA_Pollable (stub),
                      CORBA_Pollable::_nil ());

      return rval;
    }

  CORBA_Pollable_ptr retval = CORBA_Pollable::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_Pollable (
          ACE_reinterpret_cast (POA_CORBA::Pollable_ptr,
                                servant),
          stub
        ),
      CORBA_Pollable::_nil ()
    );

  return retval;
}

CORBA_Pollable_ptr CORBA_Pollable::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &env
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_Pollable::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/Pollable:1.0");
  if (servant == 0)
    {
      CORBA_Pollable_ptr rval = CORBA_Pollable::_nil ();

      ACE_NEW_RETURN (rval,
                      CORBA_Pollable (stub),
                      CORBA_Pollable::_nil ());

      return rval;
    }

  CORBA_Pollable_ptr retval = CORBA_Pollable::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_Pollable (
          ACE_reinterpret_cast (POA_CORBA::Pollable_ptr,
                                servant),
          stub
        ),
      CORBA_Pollable::_nil ()
    );

  return retval;
}

CORBA::Boolean CORBA_Pollable::is_ready (
    CORBA::ULong timeout,
    CORBA::Environment &ACE_TRY_ENV
  )
{
    CORBA::Boolean _tao_retval = 0;

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "is_ready",
      istub->orb_core ()
    );


  for (;;)
  {
    ACE_TRY_ENV.clear ();
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    CORBA::Short flag = TAO::SYNC_WITH_TARGET;

    _tao_call.prepare_header (ACE_static_cast (CORBA::Octet, flag),
                              ACE_TRY_ENV);
    ACE_CHECK_RETURN (_tao_retval);

    TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
    if (!(
          (_tao_out << timeout)
      ))
      ACE_THROW_RETURN (CORBA::MARSHAL (), _tao_retval);

    int _invoke_status =
      _tao_call.invoke (0, 0, ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);

    }
    break;

  }
  TAO_InputCDR &_tao_in = _tao_call.inp_stream ();
  if (!(
        (_tao_in >> CORBA::Any::to_boolean (_tao_retval))
    ))
    ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);
  return _tao_retval;
}

CORBA_PollableSet_ptr CORBA_Pollable::create_pollable_set (
    CORBA::Environment &ACE_TRY_ENV
  )
{
    CORBA_PollableSet_ptr _tao_retval = CORBA_PollableSet::_nil ();

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "create_pollable_set",
      istub->orb_core ()
    );


  for (;;)
  {
    ACE_TRY_ENV.clear ();
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    CORBA::Short flag = TAO::SYNC_WITH_TARGET;

    _tao_call.prepare_header (ACE_static_cast (CORBA::Octet, flag),
                              ACE_TRY_ENV);
    ACE_CHECK_RETURN (_tao_retval);

    int _invoke_status =
      _tao_call.invoke (0, 0, ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);

    }
    break;

  }
  TAO_InputCDR &_tao_in = _tao_call.inp_stream ();
  if (!(
        (_tao_in >> _tao_retval)
    ))
    ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);
  return _tao_retval;
}

CORBA::Boolean CORBA_Pollable::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Pollable:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV); // remote call
}

const char* CORBA_Pollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/Pollable:1.0";
}

CORBA::DIIPollable_ptr CORBA::DIIPollable::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA::DIIPollable::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:omg.org/CORBA/DIIPollable:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA::DIIPollable::_nil ());
  if (is_a == 0)
    return CORBA::DIIPollable::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/DIIPollable:1.0");
  if (servant == 0)
    {
      CORBA::DIIPollable_ptr rval = CORBA_Pollable::_nil ();

      ACE_NEW_RETURN (rval,
                      CORBA::DIIPollable (stub),
                      CORBA::DIIPollable::_nil ());

      return rval;
    }

  CORBA::DIIPollable_ptr retval = CORBA::DIIPollable::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_DIIPollable (
          ACE_reinterpret_cast (POA_CORBA::DIIPollable_ptr,
                                servant),
          stub
        ),
      CORBA::DIIPollable::_nil ()
    );

  return retval;
}

CORBA::DIIPollable_ptr CORBA::DIIPollable::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &env
  )
{
  if (CORBA::is_nil (obj))
    return CORBA::DIIPollable::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/DIIPollable:1.0");
  if (servant == 0)
    {
      CORBA::DIIPollable_ptr rval = CORBA_Pollable::_nil ();

      ACE_NEW_RETURN (rval,
                      CORBA::DIIPollable (stub),
                      CORBA::DIIPollable::_nil ());

      return rval;
    }

  CORBA::DIIPollable_ptr retval = CORBA::DIIPollable::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_DIIPollable (
          ACE_reinterpret_cast (POA_CORBA::DIIPollable_ptr,
                                servant),
          stub
        ),
      CORBA::DIIPollable::_nil ()
    );

  return retval;
}

CORBA::Boolean CORBA::DIIPollable::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/DIIPollable:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Pollable:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV); // remote call
}

const char* CORBA::DIIPollable::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/DIIPollable:1.0";
}

CORBA_PollableSet_ptr CORBA_PollableSet::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_PollableSet::_nil ();
  CORBA::Boolean is_a = obj->_is_a ("IDL:omg.org/CORBA/PollableSet:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (CORBA_PollableSet::_nil ());
  if (is_a == 0)
    return CORBA_PollableSet::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/PollableSet:1.0");
  if (servant == 0)
    {
      CORBA_PollableSet_ptr rval = CORBA_PollableSet::_nil ();

      ACE_NEW_RETURN (rval,
                      CORBA_PollableSet (stub),
                      CORBA_PollableSet::_nil ());

      return rval;
    }

  CORBA_PollableSet_ptr retval = CORBA_PollableSet::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_PollableSet (
          ACE_reinterpret_cast (POA_CORBA::PollableSet_ptr,
                                servant),
          stub
        ),
      CORBA_PollableSet::_nil ()
    );

  return retval;
}

CORBA_PollableSet_ptr CORBA_PollableSet::_unchecked_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &env
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_PollableSet::_nil ();
  TAO_Stub* stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  void* servant = 0;
  if (obj->_is_collocated () && obj->_servant() != 0)
    servant = obj->_servant()->_downcast ("IDL:omg.org/CORBA/PollableSet:1.0");
  if (servant == 0)
    {
      CORBA_PollableSet_ptr rval = CORBA_PollableSet::_nil ();

      ACE_NEW_RETURN (rval,
                      CORBA_PollableSet (stub),
                      CORBA_PollableSet::_nil ());

      return rval;
    }

  CORBA_PollableSet_ptr retval = CORBA_PollableSet::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_CORBA::_tao_collocated_PollableSet (
          ACE_reinterpret_cast (POA_CORBA::PollableSet_ptr,
                                servant),
          stub
        ),
      CORBA_PollableSet::_nil ()
    );

  return retval;
}

// default constructor
CORBA_PollableSet::NoPossiblePollable::NoPossiblePollable (void)
  : CORBA_UserException (CORBA_PollableSet::_tc_NoPossiblePollable)
{
}

// destructor - all members are of self managing types
CORBA_PollableSet::NoPossiblePollable::~NoPossiblePollable (void)
{
}

// copy constructor
CORBA_PollableSet::NoPossiblePollable::NoPossiblePollable (const CORBA_PollableSet::NoPossiblePollable &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
  }

// assignment operator
CORBA_PollableSet::NoPossiblePollable&
CORBA_PollableSet::NoPossiblePollable::operator= (const CORBA_PollableSet::NoPossiblePollable &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_PollableSet::NoPossiblePollable_ptr
CORBA_PollableSet::NoPossiblePollable::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/PollableSet/NoPossiblePollable:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_PollableSet::NoPossiblePollable_ptr, exc);
  else
    return 0;
}


void CORBA_PollableSet::NoPossiblePollable::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_PollableSet::NoPossiblePollable::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  CORBA_PollableSet::NoPossiblePollable
                  0);

  return retval;
}

static const CORBA::Long _oc_CORBA_PollableSet_NoPossiblePollable[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  53, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x434f5242), ACE_NTOHL (0x412f506f), ACE_NTOHL (0x6c6c6162), ACE_NTOHL (0x6c655365), ACE_NTOHL (0x742f4e6f), ACE_NTOHL (0x506f7373), ACE_NTOHL (0x69626c65), ACE_NTOHL (0x506f6c6c), ACE_NTOHL (0x61626c65), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/PollableSet/NoPossiblePollable:1.0
  19, ACE_NTOHL (0x4e6f506f), ACE_NTOHL (0x73736962), ACE_NTOHL (0x6c65506f), ACE_NTOHL (0x6c6c6162), ACE_NTOHL (0x6c650000),  // name = NoPossiblePollable
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_PollableSet_NoPossiblePollable (CORBA::tk_except, sizeof (_oc_CORBA_PollableSet_NoPossiblePollable), (char *) &_oc_CORBA_PollableSet_NoPossiblePollable, 0, sizeof (CORBA_PollableSet::NoPossiblePollable));
CORBA::TypeCode_ptr CORBA_PollableSet::_tc_NoPossiblePollable = &_tc_TAO_tc_CORBA_PollableSet_NoPossiblePollable;

// default constructor
CORBA_PollableSet::UnknownPollable::UnknownPollable (void)
  : CORBA_UserException (CORBA_PollableSet::_tc_UnknownPollable)
{
}

// destructor - all members are of self managing types
CORBA_PollableSet::UnknownPollable::~UnknownPollable (void)
{
}

// copy constructor
CORBA_PollableSet::UnknownPollable::UnknownPollable (const CORBA_PollableSet::UnknownPollable &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
  }

// assignment operator
CORBA_PollableSet::UnknownPollable&
CORBA_PollableSet::UnknownPollable::operator= (const CORBA_PollableSet::UnknownPollable &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
CORBA_PollableSet::UnknownPollable_ptr
CORBA_PollableSet::UnknownPollable::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:omg.org/CORBA/PollableSet/UnknownPollable:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (CORBA_PollableSet::UnknownPollable_ptr, exc);
  else
    return 0;
}


void CORBA_PollableSet::UnknownPollable::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *CORBA_PollableSet::UnknownPollable::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  CORBA_PollableSet::UnknownPollable
                  0);

  return retval;
}

static const CORBA::Long _oc_CORBA_PollableSet_UnknownPollable[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  50, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x434f5242), ACE_NTOHL (0x412f506f), ACE_NTOHL (0x6c6c6162), ACE_NTOHL (0x6c655365), ACE_NTOHL (0x742f556e), ACE_NTOHL (0x6b6e6f77), ACE_NTOHL (0x6e506f6c), ACE_NTOHL (0x6c61626c), ACE_NTOHL (0x653a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/PollableSet/UnknownPollable:1.0
  16, ACE_NTOHL (0x556e6b6e), ACE_NTOHL (0x6f776e50), ACE_NTOHL (0x6f6c6c61), ACE_NTOHL (0x626c6500),  // name = UnknownPollable
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_CORBA_PollableSet_UnknownPollable (CORBA::tk_except, sizeof (_oc_CORBA_PollableSet_UnknownPollable), (char *) &_oc_CORBA_PollableSet_UnknownPollable, 0, sizeof (CORBA_PollableSet::UnknownPollable));
CORBA::TypeCode_ptr CORBA_PollableSet::_tc_UnknownPollable = &_tc_TAO_tc_CORBA_PollableSet_UnknownPollable;

CORBA::DIIPollable_ptr CORBA_PollableSet::create_dii_pollable (
    CORBA::Environment &ACE_TRY_ENV
  )
{
    CORBA::DIIPollable_ptr _tao_retval = CORBA::DIIPollable::_nil ();

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "create_dii_pollable",
      istub->orb_core ()
    );


  for (;;)
  {
    ACE_TRY_ENV.clear ();
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    CORBA::Short flag = TAO::SYNC_WITH_TARGET;

    _tao_call.prepare_header (ACE_static_cast (CORBA::Octet, flag),
                              ACE_TRY_ENV);
    ACE_CHECK_RETURN (_tao_retval);

    int _invoke_status =
      _tao_call.invoke (0, 0, ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);

    }
    break;

  }
  TAO_InputCDR &_tao_in = _tao_call.inp_stream ();
  if (!(
        (_tao_in >> _tao_retval)
    ))
    ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);
  return _tao_retval;
}

void CORBA_PollableSet::add_pollable (
    CORBA_Pollable_ptr potential,
    CORBA::Environment &ACE_TRY_ENV
  )
{

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW (CORBA::INTERNAL ());


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "add_pollable",
      istub->orb_core ()
    );


  for (;;)
  {
    ACE_TRY_ENV.clear ();
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK;

    CORBA::Short flag = TAO::SYNC_WITH_TARGET;

    _tao_call.prepare_header (ACE_static_cast (CORBA::Octet, flag),
                              ACE_TRY_ENV);
    ACE_CHECK;

    TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
    if (!(
          (_tao_out << potential)
      ))
      ACE_THROW (CORBA::MARSHAL ());

    int _invoke_status =
      _tao_call.invoke (0, 0, ACE_TRY_ENV);
        ACE_CHECK;

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES));

    }
    break;

  }

}

CORBA_Pollable_ptr CORBA_PollableSet::poll (
    CORBA::ULong timeout,
    CORBA::Environment &ACE_TRY_ENV
  )
{
    static TAO_Exception_Data _tao_CORBA_PollableSet_poll_exceptiondata [] =
  {
    {CORBA_PollableSet::_tc_NoPossiblePollable, CORBA_PollableSet::NoPossiblePollable::_alloc}
  };

  CORBA_Pollable_ptr _tao_retval = CORBA_Pollable::_nil ();

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "poll",
      istub->orb_core ()
    );


  for (;;)
  {
    ACE_TRY_ENV.clear ();
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    CORBA::Short flag = TAO::SYNC_WITH_TARGET;

    _tao_call.prepare_header (ACE_static_cast (CORBA::Octet, flag),
                              ACE_TRY_ENV);
    ACE_CHECK_RETURN (_tao_retval);

    TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
    if (!(
          (_tao_out << timeout)
      ))
      ACE_THROW_RETURN (CORBA::MARSHAL (), _tao_retval);

    int _invoke_status =
      _tao_call.invoke (_tao_CORBA_PollableSet_poll_exceptiondata, 1, ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);

    }
    break;

  }
  TAO_InputCDR &_tao_in = _tao_call.inp_stream ();
  if (!(
        (_tao_in >> _tao_retval)
    ))
    ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);
  return _tao_retval;
}

void CORBA_PollableSet::remove (
    CORBA_Pollable_ptr potential,
    CORBA::Environment &ACE_TRY_ENV
  )
{
    static TAO_Exception_Data _tao_CORBA_PollableSet_remove_exceptiondata [] =
  {
    {CORBA_PollableSet::_tc_UnknownPollable, CORBA_PollableSet::UnknownPollable::_alloc}
  };


  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW (CORBA::INTERNAL ());


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "remove",
      istub->orb_core ()
    );


  for (;;)
  {
    ACE_TRY_ENV.clear ();
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK;

    CORBA::Short flag = TAO::SYNC_WITH_TARGET;

    _tao_call.prepare_header (ACE_static_cast (CORBA::Octet, flag),
                              ACE_TRY_ENV);
    ACE_CHECK;

    TAO_OutputCDR &_tao_out = _tao_call.out_stream ();
    if (!(
          (_tao_out << potential)
      ))
      ACE_THROW (CORBA::MARSHAL ());

    int _invoke_status =
      _tao_call.invoke (_tao_CORBA_PollableSet_remove_exceptiondata, 1, ACE_TRY_ENV);
        ACE_CHECK;

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES));

    }
    break;

  }

}

CORBA::UShort CORBA_PollableSet::number_left (
    CORBA::Environment &ACE_TRY_ENV
  )
{
    CORBA::UShort _tao_retval = 0;

  TAO_Stub *istub = this->_stubobj ();
  if (istub == 0)
    ACE_THROW_RETURN (CORBA::INTERNAL (), _tao_retval);


  TAO_GIOP_Twoway_Invocation _tao_call (
      istub,
      "number_left",
      istub->orb_core ()
    );


  for (;;)
  {
    ACE_TRY_ENV.clear ();
    _tao_call.start (ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    CORBA::Short flag = TAO::SYNC_WITH_TARGET;

    _tao_call.prepare_header (ACE_static_cast (CORBA::Octet, flag),
                              ACE_TRY_ENV);
    ACE_CHECK_RETURN (_tao_retval);

    int _invoke_status =
      _tao_call.invoke (0, 0, ACE_TRY_ENV);
        ACE_CHECK_RETURN (_tao_retval);

    if (_invoke_status == TAO_INVOKE_RESTART)
      continue;
    // if (_invoke_status == TAO_INVOKE_EXCEPTION)
      // cannot happen
    if (_invoke_status != TAO_INVOKE_OK)
    {
      ACE_THROW_RETURN (CORBA::UNKNOWN (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);

    }
    break;

  }
  TAO_InputCDR &_tao_in = _tao_call.inp_stream ();
  if (!(
        (_tao_in >> _tao_retval)
    ))
    ACE_THROW_RETURN (CORBA::MARSHAL (TAO_DEFAULT_MINOR_CODE, CORBA::COMPLETED_YES), _tao_retval);
  return _tao_retval;
}

CORBA::Boolean CORBA_PollableSet::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/PollableSet:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV); // remote call
}

const char* CORBA_PollableSet::_interface_repository_id (void) const
{
  return "IDL:omg.org/CORBA/PollableSet:1.0";
}

void operator<<= (CORBA::Any &_tao_any, CORBA_Pollable_ptr _tao_elem)
{
  CORBA::Object_ptr *_tao_obj_ptr = 0;
  ACE_TRY_NEW_ENV
  {
    ACE_NEW (_tao_obj_ptr, CORBA::Object_ptr);
    *_tao_obj_ptr = CORBA_Pollable::_duplicate (_tao_elem);
    _tao_any.replace (CORBA::_tc_Pollable, _tao_obj_ptr, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_obj_ptr;
  }
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_Pollable_ptr &_tao_elem)
{
  CORBA::Object_ptr *tmp = 0;
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA_Pollable::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_Pollable, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    TAO_InputCDR stream (_tao_any._tao_get_cdr ());
    CORBA::Object_var _tao_obj_var;
    ACE_NEW_RETURN (tmp, CORBA::Object_ptr, 0);
    if (stream.decode (CORBA::_tc_Pollable, &_tao_obj_var.out (), 0, ACE_TRY_ENV)
       == CORBA::TypeCode::TRAVERSE_CONTINUE)
    {
      _tao_elem = CORBA_Pollable::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      *tmp = (CORBA::Object_ptr) _tao_elem;  // any owns the object
      ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_Pollable, tmp, 1, ACE_TRY_ENV);
      ACE_TRY_CHECK;
      return 1;
    }
    // failure
  }
  ACE_CATCHANY
  {
    delete tmp;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<CORBA_Pollable,CORBA_Pollable_var>;
  template class TAO_Object_Manager<CORBA_Pollable,CORBA_Pollable_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Field_T<CORBA_Pollable,CORBA_Pollable_var>
#  pragma instantiate TAO_Object_Manager<CORBA_Pollable,CORBA_Pollable_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

void operator<<= (CORBA::Any &_tao_any, CORBA::DIIPollable_ptr _tao_elem)
{
  CORBA::Object_ptr *_tao_obj_ptr = 0;
  ACE_TRY_NEW_ENV
  {
    ACE_NEW (_tao_obj_ptr, CORBA::Object_ptr);
    *_tao_obj_ptr = CORBA::DIIPollable::_duplicate (_tao_elem);
    _tao_any.replace (CORBA::_tc_DIIPollable, _tao_obj_ptr, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_obj_ptr;
  }
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA::DIIPollable_ptr &_tao_elem)
{
  CORBA::Object_ptr *tmp = 0;
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA::DIIPollable::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_DIIPollable, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    TAO_InputCDR stream (_tao_any._tao_get_cdr ());
    CORBA::Object_var _tao_obj_var;
    ACE_NEW_RETURN (tmp, CORBA::Object_ptr, 0);
    if (stream.decode (CORBA::_tc_DIIPollable, &_tao_obj_var.out (), 0, ACE_TRY_ENV)
       == CORBA::TypeCode::TRAVERSE_CONTINUE)
    {
      _tao_elem = CORBA::DIIPollable::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      *tmp = (CORBA::Object_ptr) _tao_elem;  // any owns the object
      ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_DIIPollable, tmp, 1, ACE_TRY_ENV);
      ACE_TRY_CHECK;
      return 1;
    }
    // failure
  }
  ACE_CATCHANY
  {
    delete tmp;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<CORBA::DIIPollable,CORBA::DIIPollable_var>;
  template class TAO_Object_Manager<CORBA::DIIPollable,CORBA::DIIPollable_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Field_T<CORBA::DIIPollable,CORBA::DIIPollable_var>
#  pragma instantiate TAO_Object_Manager<CORBA::DIIPollable,CORBA::DIIPollable_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

void operator<<= (CORBA::Any &_tao_any, CORBA_PollableSet_ptr _tao_elem)
{
  CORBA::Object_ptr *_tao_obj_ptr = 0;
  ACE_TRY_NEW_ENV
  {
    ACE_NEW (_tao_obj_ptr, CORBA::Object_ptr);
    *_tao_obj_ptr = CORBA_PollableSet::_duplicate (_tao_elem);
    _tao_any.replace (CORBA::_tc_PollableSet, _tao_obj_ptr, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_obj_ptr;
  }
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_PollableSet_ptr &_tao_elem)
{
  CORBA::Object_ptr *tmp = 0;
  ACE_TRY_NEW_ENV
  {
    _tao_elem = CORBA_PollableSet::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA::_tc_PollableSet, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    TAO_InputCDR stream (_tao_any._tao_get_cdr ());
    CORBA::Object_var _tao_obj_var;
    ACE_NEW_RETURN (tmp, CORBA::Object_ptr, 0);
    if (stream.decode (CORBA::_tc_PollableSet, &_tao_obj_var.out (), 0, ACE_TRY_ENV)
       == CORBA::TypeCode::TRAVERSE_CONTINUE)
    {
      _tao_elem = CORBA_PollableSet::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      *tmp = (CORBA::Object_ptr) _tao_elem;  // any owns the object
      ((CORBA::Any *)&_tao_any)->replace (CORBA::_tc_PollableSet, tmp, 1, ACE_TRY_ENV);
      ACE_TRY_CHECK;
      return 1;
    }
    // failure
  }
  ACE_CATCHANY
  {
    delete tmp;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
  template class TAO_Object_Field_T<CORBA_PollableSet,CORBA_PollableSet_var>;
  template class TAO_Object_Manager<CORBA_PollableSet,CORBA_PollableSet_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Field_T<CORBA_PollableSet,CORBA_PollableSet_var>
#  pragma instantiate TAO_Object_Manager<CORBA_PollableSet,CORBA_PollableSet_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

void operator<<= (CORBA::Any &_tao_any, const CORBA_PollableSet::NoPossiblePollable &_tao_elem) // copying
{
  CORBA_PollableSet::NoPossiblePollable *_tao_any_val = 0;
  ACE_NEW (_tao_any_val,
           CORBA_PollableSet::NoPossiblePollable (_tao_elem));
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA_PollableSet::_tc_NoPossiblePollable, _tao_any_val, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, CORBA_PollableSet::NoPossiblePollable *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA_PollableSet::_tc_NoPossiblePollable, _tao_elem, 1, ACE_TRY_ENV); // consume it
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_PollableSet::NoPossiblePollable *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA_PollableSet::_tc_NoPossiblePollable, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA_PollableSet::NoPossiblePollable *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA_PollableSet::NoPossiblePollable, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (CORBA_PollableSet::_tc_NoPossiblePollable, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (CORBA_PollableSet::_tc_NoPossiblePollable, _tao_elem, 1, ACE_TRY_ENV);
        ACE_TRY_CHECK;
        return 1;
      }
      else
      {
        delete _tao_elem;
      }
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

void operator<<= (CORBA::Any &_tao_any, const CORBA_PollableSet::UnknownPollable &_tao_elem) // copying
{
  CORBA_PollableSet::UnknownPollable *_tao_any_val = 0;
  ACE_NEW (_tao_any_val,
           CORBA_PollableSet::UnknownPollable (_tao_elem));
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA_PollableSet::_tc_UnknownPollable, _tao_any_val, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, CORBA_PollableSet::UnknownPollable *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (CORBA_PollableSet::_tc_UnknownPollable, _tao_elem, 1, ACE_TRY_ENV); // consume it
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, CORBA_PollableSet::UnknownPollable *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (CORBA_PollableSet::_tc_UnknownPollable, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (CORBA_PollableSet::UnknownPollable *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, CORBA_PollableSet::UnknownPollable, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (CORBA_PollableSet::_tc_UnknownPollable, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (CORBA_PollableSet::_tc_UnknownPollable, _tao_elem, 1, ACE_TRY_ENV);
        ACE_TRY_CHECK;
        return 1;
      }
      else
      {
        delete _tao_elem;
      }
    }
  }
  ACE_CATCHANY
  {
    delete _tao_elem;
    return 0;
  }
  ACE_ENDTRY;
  return 0;
}

// ****************************************************************

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA_Pollable_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA_Pollable_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    if ((strm >> obj.inout ()) == 0)
      return 0;
    // narrow to the right type
    _tao_objref =
      CORBA_Pollable::_narrow (
          obj.in (),
          ACE_TRY_ENV
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA_DIIPollable_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA_DIIPollable_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    if ((strm >> obj.inout ()) == 0)
      return 0;
    // narrow to the right type
    _tao_objref =
      CORBA_DIIPollable::_narrow (
          obj.in (),
          ACE_TRY_ENV
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const CORBA_PollableSet_ptr _tao_objref
  )
{
  CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    CORBA_PollableSet_ptr &_tao_objref
  )
{
  ACE_TRY_NEW_ENV
  {
    CORBA::Object_var obj;
    if ((strm >> obj.inout ()) == 0)
      return 0;
    // narrow to the right type
    _tao_objref =
      CORBA_PollableSet::_narrow (
          obj.in (),
          ACE_TRY_ENV
        );
    ACE_TRY_CHECK;
    return 1;
  }
  ACE_CATCHANY
  {
    // do nothing
  }
  ACE_ENDTRY;
  return 0;
}

#endif /* TAO_HAS_CORBA_MESSAGING && TAO_HAS_AMI_POLLER */
