// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#include "Messaging_PolicyValueC.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode_Static.h"
#include "tao/Sequence_TypeCode_Static.h"
#include "tao/String_TypeCode_Static.h"
#include "tao/Struct_TypeCode_Static.h"
#include "tao/TypeCode_Struct_Field.h"
#include "tao/Recursive_Type_TypeCode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/struct_typecode.cpp:87



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937

static TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const _tao_fields_Messaging_PolicyValue[] =
  {
    { "ptype", &CORBA::_tc_PolicyType },
    { "pvalue", &CORBA::_tc_OctetSeq }
    
  };
static TAO::TypeCode::Struct<char const *,
                      CORBA::TypeCode_ptr const *,
                      TAO::TypeCode::Struct_Field<char const *, CORBA::TypeCode_ptr const *> const *,
                      TAO::Null_RefCount_Policy>
  _tao_tc_Messaging_PolicyValue (
    CORBA::tk_struct,
    "IDL:omg.org/Messaging/PolicyValue:1.0",
    "PolicyValue",
    _tao_fields_Messaging_PolicyValue,
    2);
  
namespace Messaging
{
  ::CORBA::TypeCode_ptr const _tc_PolicyValue =
    &_tao_tc_Messaging_PolicyValue;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:937


#ifndef _TAO_TYPECODE_Messaging_PolicyValueSeq_GUARD
#define _TAO_TYPECODE_Messaging_PolicyValueSeq_GUARD
namespace TAO
{
  namespace TypeCode
  {
    TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
      Messaging_PolicyValueSeq_0 (
        CORBA::tk_sequence,
        &Messaging::_tc_PolicyValue,
        0U);
      
    ::CORBA::TypeCode_ptr const tc_Messaging_PolicyValueSeq_0 =
      &Messaging_PolicyValueSeq_0;
    
  }
}


#endif /* _TAO_TYPECODE_Messaging_PolicyValueSeq_GUARD */

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_Messaging_PolicyValueSeq (
    CORBA::tk_alias,
    "IDL:omg.org/Messaging/PolicyValueSeq:1.0",
    "PolicyValueSeq",
    &TAO::TypeCode::tc_Messaging_PolicyValueSeq_0);
  
namespace Messaging
{
  ::CORBA::TypeCode_ptr const _tc_PolicyValueSeq =
    &_tao_tc_Messaging_PolicyValueSeq;
}



// TAO_IDL - Generated from 
// be\be_visitor_structure/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Messaging::PolicyValue &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValue>::insert_copy (
      _tao_any,
      Messaging::PolicyValue::_tao_any_destructor,
      Messaging::_tc_PolicyValue,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Messaging::PolicyValue *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValue>::insert (
      _tao_any,
      Messaging::PolicyValue::_tao_any_destructor,
      Messaging::_tc_PolicyValue,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::PolicyValue *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const Messaging::PolicyValue *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Messaging::PolicyValue *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Messaging::PolicyValue>::extract (
        _tao_any,
        Messaging::PolicyValue::_tao_any_destructor,
        Messaging::_tc_PolicyValue,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/any_op_cs.cpp:54


// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const Messaging::PolicyValueSeq &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValueSeq>::insert_copy (
      _tao_any,
      Messaging::PolicyValueSeq::_tao_any_destructor,
      TAO::TypeCode::tc_Messaging_PolicyValueSeq_0,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    Messaging::PolicyValueSeq *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<Messaging::PolicyValueSeq>::insert (
      _tao_any,
      Messaging::PolicyValueSeq::_tao_any_destructor,
      TAO::TypeCode::tc_Messaging_PolicyValueSeq_0,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    Messaging::PolicyValueSeq *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const Messaging::PolicyValueSeq *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const Messaging::PolicyValueSeq *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<Messaging::PolicyValueSeq>::extract (
        _tao_any,
        Messaging::PolicyValueSeq::_tao_any_destructor,
        TAO::TypeCode::tc_Messaging_PolicyValueSeq_0,
        _tao_elem
      );
}
