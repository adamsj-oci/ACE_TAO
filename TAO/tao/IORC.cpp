/* -*- C++ -*- */
// $Id$

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO and the TAO IDL Compiler have been developed by the Center for
// Distributed Object Computing at Washington University, St. Louis.
//
// Information about TAO is available at:
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/IORC.h"

#if !defined (__ACE_INLINE__)
#include "IORC.i"
#endif /* !defined INLINE */

#include "tao/IORS.h"
#include "tao/Stub.h"
#include "tao/Invocation.h"

ACE_RCSID(tao, IORC, "$Id$")

TAO_IOP::TAO_IOR_Manipulation_ptr TAO_IOP::TAO_IOR_Manipulation::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &ACE_TRY_ENV
  )
{
  if (CORBA::is_nil (obj))
    return TAO_IOP::TAO_IOR_Manipulation::_nil ();
  CORBA::Boolean check =
    !obj->_is_a ("IDL:TAO_IOP/TAO_IOR_Manipulation:1.0", ACE_TRY_ENV);
  ACE_CHECK_RETURN (TAO_IOP::TAO_IOR_Manipulation::_nil ());
  if (check)
    return TAO_IOP::TAO_IOR_Manipulation::_nil ();
  void* servant = 0;
  if (!obj->_is_collocated ()
      || !obj->_servant()
      || (servant = obj->_servant ()->_downcast ("IDL:TAO_IOP/TAO_IOR_Manipulation:1.0")) == 0)
      // This can only be colocated
      ACE_THROW_RETURN (CORBA::MARSHAL (), TAO_IOP::TAO_IOR_Manipulation::_nil ());

  TAO_IOP::TAO_IOR_Manipulation_ptr retval =
    TAO_IOP::TAO_IOR_Manipulation::_nil ();

  ACE_NEW_RETURN (
      retval,
      POA_TAO_IOP::_tao_collocated_TAO_IOR_Manipulation (
          ACE_reinterpret_cast (POA_TAO_IOP::TAO_IOR_Manipulation_ptr, 
                                servant),
          0
        ),
      TAO_IOP::TAO_IOR_Manipulation::_nil ()
    );

  return retval;
}

TAO_IOP::TAO_IOR_Manipulation_ptr
TAO_IOP::TAO_IOR_Manipulation::_duplicate (TAO_IOP::TAO_IOR_Manipulation_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();
  return obj;
}

// default constructor
TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList::EmptyProfileList (void)
  : CORBA_UserException (TAO_IOP::TAO_IOR_Manipulation::_tc_EmptyProfileList)
{
}

// destructor - all members are of self managing types
TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList::~EmptyProfileList (void)
{
}

// copy constructor
TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList::EmptyProfileList (const TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
  }

// assignment operator
TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList&
TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList::operator= (const TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList_ptr
TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:TAO_IOP/TAO_IOR_Manipulation/EmptyProfileList:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList_ptr, exc);
  else
    return 0;
}


void TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList,
                  0);

  return retval;
}

static const CORBA::Long _oc_TAO_IOP_TAO_IOR_Manipulation_EmptyProfileList[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  54, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f525f), ACE_NTOHL (0x4d616e69), ACE_NTOHL (0x70756c61), ACE_NTOHL (0x74696f6e), ACE_NTOHL (0x2f456d70), ACE_NTOHL (0x74795072), ACE_NTOHL (0x6f66696c), ACE_NTOHL (0x654c6973), ACE_NTOHL (0x743a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:TAO_IOP/TAO_IOR_Manipulation/EmptyProfileList:1.0
  17, ACE_NTOHL (0x456d7074), ACE_NTOHL (0x7950726f), ACE_NTOHL (0x66696c65), ACE_NTOHL (0x4c697374), ACE_NTOHL (0x0),  // name = EmptyProfileList
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_EmptyProfileList (CORBA::tk_except, sizeof (_oc_TAO_IOP_TAO_IOR_Manipulation_EmptyProfileList), (char *) &_oc_TAO_IOP_TAO_IOR_Manipulation_EmptyProfileList, 0, sizeof (TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList));
CORBA::TypeCode_ptr TAO_IOP::TAO_IOR_Manipulation::_tc_EmptyProfileList = &_tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_EmptyProfileList;

// default constructor
TAO_IOP::TAO_IOR_Manipulation::NotFound::NotFound (void)
  : CORBA_UserException (TAO_IOP::TAO_IOR_Manipulation::_tc_NotFound)
{
}

// destructor - all members are of self managing types
TAO_IOP::TAO_IOR_Manipulation::NotFound::~NotFound (void)
{
}

// copy constructor
TAO_IOP::TAO_IOR_Manipulation::NotFound::NotFound (const TAO_IOP::TAO_IOR_Manipulation::NotFound &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
  }

// assignment operator
TAO_IOP::TAO_IOR_Manipulation::NotFound&
TAO_IOP::TAO_IOR_Manipulation::NotFound::operator= (const TAO_IOP::TAO_IOR_Manipulation::NotFound &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
TAO_IOP::TAO_IOR_Manipulation::NotFound_ptr
TAO_IOP::TAO_IOR_Manipulation::NotFound::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:TAO_IOP/TAO_IOR_Manipulation/NotFound:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (TAO_IOP::TAO_IOR_Manipulation::NotFound_ptr, exc);
  else
    return 0;
}


void TAO_IOP::TAO_IOR_Manipulation::NotFound::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *TAO_IOP::TAO_IOR_Manipulation::NotFound::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  TAO_IOP::TAO_IOR_Manipulation::NotFound,
                  0);

  return retval;
}

static const CORBA::Long _oc_TAO_IOP_TAO_IOR_Manipulation_NotFound[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  46, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f525f), ACE_NTOHL (0x4d616e69), ACE_NTOHL (0x70756c61), ACE_NTOHL (0x74696f6e), ACE_NTOHL (0x2f4e6f74), ACE_NTOHL (0x466f756e), ACE_NTOHL (0x643a312e), ACE_NTOHL (0x30000000),  // repository ID = IDL:TAO_IOP/TAO_IOR_Manipulation/NotFound:1.0
  9, ACE_NTOHL (0x4e6f7446), ACE_NTOHL (0x6f756e64), ACE_NTOHL (0x0),  // name = NotFound
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_NotFound (CORBA::tk_except, sizeof (_oc_TAO_IOP_TAO_IOR_Manipulation_NotFound), (char *) &_oc_TAO_IOP_TAO_IOR_Manipulation_NotFound, 0, sizeof (TAO_IOP::TAO_IOR_Manipulation::NotFound));
CORBA::TypeCode_ptr TAO_IOP::TAO_IOR_Manipulation::_tc_NotFound = &_tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_NotFound;

// default constructor
TAO_IOP::TAO_IOR_Manipulation::Duplicate::Duplicate (void)
  : CORBA_UserException (TAO_IOP::TAO_IOR_Manipulation::_tc_Duplicate)
{
}

// destructor - all members are of self managing types
TAO_IOP::TAO_IOR_Manipulation::Duplicate::~Duplicate (void)
{
}

// copy constructor
TAO_IOP::TAO_IOR_Manipulation::Duplicate::Duplicate (const TAO_IOP::TAO_IOR_Manipulation::Duplicate &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
  }

// assignment operator
TAO_IOP::TAO_IOR_Manipulation::Duplicate&
TAO_IOP::TAO_IOR_Manipulation::Duplicate::operator= (const TAO_IOP::TAO_IOR_Manipulation::Duplicate &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
TAO_IOP::TAO_IOR_Manipulation::Duplicate_ptr
TAO_IOP::TAO_IOR_Manipulation::Duplicate::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:TAO_IOP/TAO_IOR_Manipulation/Duplicate:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (TAO_IOP::TAO_IOR_Manipulation::Duplicate_ptr, exc);
  else
    return 0;
}


void TAO_IOP::TAO_IOR_Manipulation::Duplicate::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *TAO_IOP::TAO_IOR_Manipulation::Duplicate::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  TAO_IOP::TAO_IOR_Manipulation::Duplicate,
                  0);

  return retval;
}

static const CORBA::Long _oc_TAO_IOP_TAO_IOR_Manipulation_Duplicate[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  47, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f525f), ACE_NTOHL (0x4d616e69), ACE_NTOHL (0x70756c61), ACE_NTOHL (0x74696f6e), ACE_NTOHL (0x2f447570), ACE_NTOHL (0x6c696361), ACE_NTOHL (0x74653a31), ACE_NTOHL (0x2e300000),  // repository ID = IDL:TAO_IOP/TAO_IOR_Manipulation/Duplicate:1.0
  10, ACE_NTOHL (0x4475706c), ACE_NTOHL (0x69636174), ACE_NTOHL (0x65000000),  // name = Duplicate
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_Duplicate (CORBA::tk_except, sizeof (_oc_TAO_IOP_TAO_IOR_Manipulation_Duplicate), (char *) &_oc_TAO_IOP_TAO_IOR_Manipulation_Duplicate, 0, sizeof (TAO_IOP::TAO_IOR_Manipulation::Duplicate));
CORBA::TypeCode_ptr TAO_IOP::TAO_IOR_Manipulation::_tc_Duplicate = &_tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_Duplicate;

// default constructor
TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR::Invalid_IOR (void)
  : CORBA_UserException (TAO_IOP::TAO_IOR_Manipulation::_tc_Invalid_IOR)
{
}

// destructor - all members are of self managing types
TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR::~Invalid_IOR (void)
{
}

// copy constructor
TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR::Invalid_IOR (const TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR &_tao_excp)
  : CORBA_UserException (_tao_excp._type ())
{
  }

// assignment operator
TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR&
TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR::operator= (const TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR &_tao_excp)
{

  this->CORBA_UserException::operator= (_tao_excp);
  return *this;
}

// narrow
TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR_ptr
TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR::_narrow (CORBA::Exception *exc)
{
  if (!ACE_OS::strcmp ("IDL:TAO_IOP/TAO_IOR_Manipulation/Invalid_IOR:1.0", exc->_id ())) // same type
    return ACE_dynamic_cast (TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR_ptr, exc);
  else
    return 0;
}


void TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR::_raise ()
{
  TAO_RAISE(*this);
}

// TAO extension - the _alloc method
CORBA::Exception *TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR::_alloc (void)
{
  CORBA::Exception *retval = 0;

  ACE_NEW_RETURN (retval,
                  TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR,
                  0);

  return retval;
}

static const CORBA::Long _oc_TAO_IOP_TAO_IOR_Manipulation_Invalid_IOR[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  49, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f525f), ACE_NTOHL (0x4d616e69), ACE_NTOHL (0x70756c61), ACE_NTOHL (0x74696f6e), ACE_NTOHL (0x2f496e76), ACE_NTOHL (0x616c6964), ACE_NTOHL (0x5f494f52), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:TAO_IOP/TAO_IOR_Manipulation/Invalid_IOR:1.0
  12, ACE_NTOHL (0x496e7661), ACE_NTOHL (0x6c69645f), ACE_NTOHL (0x494f5200),  // name = Invalid_IOR
  0, // member count
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_Invalid_IOR (CORBA::tk_except, sizeof (_oc_TAO_IOP_TAO_IOR_Manipulation_Invalid_IOR), (char *) &_oc_TAO_IOP_TAO_IOR_Manipulation_Invalid_IOR, 0, sizeof (TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR));
CORBA::TypeCode_ptr TAO_IOP::TAO_IOR_Manipulation::_tc_Invalid_IOR = &_tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_Invalid_IOR;


#if !defined (_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CS_)
#define _TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CS_

// *************************************************************
// TAO_IOP::TAO_IOR_Manipulation::IORList
// *************************************************************

TAO_IOP::TAO_IOR_Manipulation::IORList::IORList (void)
{}
TAO_IOP::TAO_IOR_Manipulation::IORList::IORList (CORBA::ULong max) // uses max size
  :
  TAO_Unbounded_Object_Sequence<CORBA::Object,CORBA::Object_var> (max)
{}
TAO_IOP::TAO_IOR_Manipulation::IORList::IORList (CORBA::ULong max, CORBA::ULong length, CORBA::Object_ptr *buffer, CORBA::Boolean release)
  :
  TAO_Unbounded_Object_Sequence<CORBA::Object,CORBA::Object_var> (max, length, buffer, release)
{}
TAO_IOP::TAO_IOR_Manipulation::IORList::IORList (const IORList &seq) // copy ctor
  :
  TAO_Unbounded_Object_Sequence<CORBA::Object,CORBA::Object_var> (seq)
{}
TAO_IOP::TAO_IOR_Manipulation::IORList::~IORList (void) // dtor
{}


#endif /* end #if !defined */

static const CORBA::Long _oc_TAO_IOP_TAO_IOR_Manipulation_IORList[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  45, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f525f), ACE_NTOHL (0x4d616e69), ACE_NTOHL (0x70756c61), ACE_NTOHL (0x74696f6e), ACE_NTOHL (0x2f494f52), ACE_NTOHL (0x4c697374), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:TAO_IOP/TAO_IOR_Manipulation/IORList:1.0
  8, ACE_NTOHL (0x494f524c), ACE_NTOHL (0x69737400),  // name = IORList
  CORBA::tk_sequence, // typecode kind
  68, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_objref,
    52, // encapsulation length
      TAO_ENCAP_BYTE_ORDER, // byte order
      29, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x434f5242), ACE_NTOHL (0x412f4f62), ACE_NTOHL (0x6a656374), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/Object:1.0
      7, ACE_NTOHL (0x4f626a65), ACE_NTOHL (0x63740000),  // name = Object

    0,

};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_IORList (CORBA::tk_alias, sizeof (_oc_TAO_IOP_TAO_IOR_Manipulation_IORList), (char *) &_oc_TAO_IOP_TAO_IOR_Manipulation_IORList, 0, sizeof (TAO_IOP::TAO_IOR_Manipulation::IORList));
CORBA::TypeCode_ptr TAO_IOP::TAO_IOR_Manipulation::_tc_IORList = &_tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation_IORList;

CORBA::Boolean TAO_IOP::TAO_IOR_Manipulation::_is_a (const CORBA::Char *value, CORBA::Environment &ACE_TRY_ENV)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:TAO_IOP/TAO_IOR_Manipulation:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, "IDL:omg.org/CORBA/Object:1.0")))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, ACE_TRY_ENV);
}

const char* TAO_IOP::TAO_IOR_Manipulation::_interface_repository_id (void) const
{
  return "IDL:TAO_IOP/TAO_IOR_Manipulation:1.0";
}

static const CORBA::Long _oc_TAO_IOP_TAO_IOR_Manipulation[] =
{
  TAO_ENCAP_BYTE_ORDER, // byte order
  41, ACE_NTOHL (0x49444c3a), ACE_NTOHL (0x6f6d672e), ACE_NTOHL (0x6f72672f), ACE_NTOHL (0x494f502f), ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f525f), ACE_NTOHL (0x6d616e69), ACE_NTOHL (0x70756c61), ACE_NTOHL (0x74696f6e), ACE_NTOHL (0x3a312e30), ACE_NTOHL (0x0),  // repository ID = IDL:TAO_IOP/TAO_IOR_Manipulation:1.0
  21, ACE_NTOHL (0x54414f5f), ACE_NTOHL (0x494f525f), ACE_NTOHL (0x6d616e69), ACE_NTOHL (0x70756c61), ACE_NTOHL (0x74696f6e), ACE_NTOHL (0x0),  // name = TAO_IOR_Manipulation
};
static CORBA::TypeCode _tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation (CORBA::tk_objref, sizeof (_oc_TAO_IOP_TAO_IOR_Manipulation), (char *) &_oc_TAO_IOP_TAO_IOR_Manipulation, 0, sizeof (TAO_IOP::TAO_IOR_Manipulation));
TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO_IOP)
TAO_NAMESPACE_DEFINE (CORBA::TypeCode_ptr, _tc_TAO_IOR_Manipulation, &_tc_TAO_tc_TAO_IOP_TAO_IOR_Manipulation)
TAO_NAMESPACE_END
void operator<<= (CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation_ptr _tao_elem)
{
  CORBA::Object_ptr *_tao_obj_ptr = 0;
  ACE_TRY_NEW_ENV
  {
    ACE_NEW (_tao_obj_ptr, CORBA::Object_ptr);
    *_tao_obj_ptr = TAO_IOP::TAO_IOR_Manipulation::_duplicate (_tao_elem);
    _tao_any.replace (TAO_IOP::_tc_TAO_IOR_Manipulation, _tao_obj_ptr, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_obj_ptr;
  }
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation_ptr &_tao_elem)
{
  CORBA::Object_ptr *tmp = 0;
  ACE_TRY_NEW_ENV
  {
    _tao_elem = TAO_IOP::TAO_IOR_Manipulation::_nil ();
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (TAO_IOP::_tc_TAO_IOR_Manipulation, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    TAO_InputCDR stream (_tao_any._tao_get_cdr ());
    CORBA::Object_var _tao_obj_var;
    ACE_NEW_RETURN (tmp, CORBA::Object_ptr, 0);
    if (stream.decode (TAO_IOP::_tc_TAO_IOR_Manipulation, &_tao_obj_var.out (), 0, ACE_TRY_ENV)
       == CORBA::TypeCode::TRAVERSE_CONTINUE)
    {
      _tao_elem = TAO_IOP::TAO_IOR_Manipulation::_narrow (_tao_obj_var.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;
      *tmp = (CORBA::Object_ptr) _tao_elem;  // any owns the object
      ((CORBA::Any *)&_tao_any)->replace (TAO_IOP::_tc_TAO_IOR_Manipulation, tmp, 1, ACE_TRY_ENV);
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
  template class TAO_Object_Field_T<TAO_IOP::TAO_IOR_Manipulation,TAO_IOP::TAO_IOR_Manipulation_var>;
  template class TAO_Object_Manager<TAO_IOP::TAO_IOR_Manipulation,TAO_IOP::TAO_IOR_Manipulation_var>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#  pragma instantiate TAO_Object_Field_T<TAO_IOP::TAO_IOR_Manipulation,TAO_IOP::TAO_IOR_Manipulation_var>
#  pragma instantiate TAO_Object_Manager<TAO_IOP::TAO_IOR_Manipulation,TAO_IOP::TAO_IOR_Manipulation_var>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

void operator<<= (CORBA::Any &_tao_any, const TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList &_tao_elem) // copying
{
  TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList *_tao_any_val = new TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList (_tao_elem);
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_EmptyProfileList, _tao_any_val, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_EmptyProfileList, _tao_elem, 1, ACE_TRY_ENV); // consume it
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (TAO_IOP::TAO_IOR_Manipulation::_tc_EmptyProfileList, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, TAO_IOP::TAO_IOR_Manipulation::EmptyProfileList, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (TAO_IOP::TAO_IOR_Manipulation::_tc_EmptyProfileList, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (TAO_IOP::TAO_IOR_Manipulation::_tc_EmptyProfileList, _tao_elem, 1, ACE_TRY_ENV);
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

void operator<<= (CORBA::Any &_tao_any, const TAO_IOP::TAO_IOR_Manipulation::NotFound &_tao_elem) // copying
{
  TAO_IOP::TAO_IOR_Manipulation::NotFound *_tao_any_val = new TAO_IOP::TAO_IOR_Manipulation::NotFound (_tao_elem);
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_NotFound, _tao_any_val, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::NotFound *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_NotFound, _tao_elem, 1, ACE_TRY_ENV); // consume it
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::NotFound *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (TAO_IOP::TAO_IOR_Manipulation::_tc_NotFound, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::TAO_IOR_Manipulation::NotFound *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, TAO_IOP::TAO_IOR_Manipulation::NotFound, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (TAO_IOP::TAO_IOR_Manipulation::_tc_NotFound, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (TAO_IOP::TAO_IOR_Manipulation::_tc_NotFound, _tao_elem, 1, ACE_TRY_ENV);
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

void operator<<= (CORBA::Any &_tao_any, const TAO_IOP::TAO_IOR_Manipulation::Duplicate &_tao_elem) // copying
{
  TAO_IOP::TAO_IOR_Manipulation::Duplicate *_tao_any_val = new TAO_IOP::TAO_IOR_Manipulation::Duplicate (_tao_elem);
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_Duplicate, _tao_any_val, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::Duplicate *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_Duplicate, _tao_elem, 1, ACE_TRY_ENV); // consume it
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::Duplicate *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (TAO_IOP::TAO_IOR_Manipulation::_tc_Duplicate, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::TAO_IOR_Manipulation::Duplicate *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, TAO_IOP::TAO_IOR_Manipulation::Duplicate, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (TAO_IOP::TAO_IOR_Manipulation::_tc_Duplicate, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (TAO_IOP::TAO_IOR_Manipulation::_tc_Duplicate, _tao_elem, 1, ACE_TRY_ENV);
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

void operator<<= (CORBA::Any &_tao_any, const TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR &_tao_elem) // copying
{
  TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR *_tao_any_val = new TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR (_tao_elem);
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_Invalid_IOR, _tao_any_val, 1, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_Invalid_IOR, _tao_elem, 1, ACE_TRY_ENV); // consume it
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (TAO_IOP::TAO_IOR_Manipulation::_tc_Invalid_IOR, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, TAO_IOP::TAO_IOR_Manipulation::Invalid_IOR, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (TAO_IOP::TAO_IOR_Manipulation::_tc_Invalid_IOR, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (TAO_IOP::TAO_IOR_Manipulation::_tc_Invalid_IOR, _tao_elem, 1, ACE_TRY_ENV);
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

void operator<<= (
    CORBA::Any &_tao_any,
    const TAO_IOP::TAO_IOR_Manipulation::IORList &_tao_elem
  ) // copying
{
  TAO_IOP::TAO_IOR_Manipulation::IORList *_tao_any_val;
  ACE_NEW (_tao_any_val, TAO_IOP::TAO_IOR_Manipulation::IORList (_tao_elem));
  if (!_tao_any_val) return;
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_IORList, _tao_any_val, 1, ACE_TRY_ENV); // copy the value
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY
  {
    delete _tao_any_val;
  }
  ACE_ENDTRY;
}

void operator<<= (CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::IORList *_tao_elem) // non copying
{
  ACE_TRY_NEW_ENV
  {
    _tao_any.replace (TAO_IOP::TAO_IOR_Manipulation::_tc_IORList, _tao_elem, 0, ACE_TRY_ENV);
    ACE_TRY_CHECK;
  }
  ACE_CATCHANY {}
  ACE_ENDTRY;
}

CORBA::Boolean operator>>= (const CORBA::Any &_tao_any, TAO_IOP::TAO_IOR_Manipulation::IORList *&_tao_elem)
{
  ACE_TRY_NEW_ENV
  {
    CORBA::TypeCode_var type = _tao_any.type ();
    if (!type->equal (TAO_IOP::TAO_IOR_Manipulation::_tc_IORList, ACE_TRY_ENV)) return 0; // not equal
    ACE_TRY_CHECK;
    if (_tao_any.any_owns_data ())
    {
      _tao_elem = (TAO_IOP::TAO_IOR_Manipulation::IORList *)_tao_any.value ();
      return 1;
    }
    else
    {
      ACE_NEW_RETURN (_tao_elem, TAO_IOP::TAO_IOR_Manipulation::IORList, 0);
      TAO_InputCDR stream (_tao_any._tao_get_cdr ());
      if (stream.decode (TAO_IOP::TAO_IOR_Manipulation::_tc_IORList, _tao_elem, 0, ACE_TRY_ENV)
        == CORBA::TypeCode::TRAVERSE_CONTINUE)
      {
        ((CORBA::Any *)&_tao_any)->replace (TAO_IOP::TAO_IOR_Manipulation::_tc_IORList, _tao_elem, 1, ACE_TRY_ENV);
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

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO_IOP::TAO_IOR_Manipulation::IORList &_tao_sequence
  )
{
  if (strm << _tao_sequence.length ())
  {
    // encode all elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm << _tao_sequence[i].in ());
    return _tao_marshal_flag;
  }
  return 0; // error
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAO_IOP::TAO_IOR_Manipulation::IORList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  if (strm >> _tao_seq_len)
  {
    // set the length of the sequence
    _tao_sequence.length (_tao_seq_len);
    // retrieve all the elements
    CORBA::Boolean _tao_marshal_flag = 1;
    for (CORBA::ULong i = 0; i < _tao_sequence.length () && _tao_marshal_flag; i++)
      _tao_marshal_flag = (strm >> _tao_sequence[i].out ());
    return _tao_marshal_flag;
  }
  return 0; // error
}
