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

// TAO_IDL - Generated from
// be\be_codegen.cpp:291


#include "PI_ForwardC.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"
#include "tao/Null_RefCount_Policy.h"
#include "tao/TypeCode_Constants.h"
#include "tao/Alias_TypeCode_Static.h"
#include "tao/String_TypeCode_Static.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ServerId (
    CORBA::tk_alias,
    "IDL:omg.org/PortableInterceptor/ServerId:1.0",
    "ServerId",
    &CORBA::_tc_string);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ServerId =
    &_tao_tc_PortableInterceptor_ServerId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ORBId (
    CORBA::tk_alias,
    "IDL:omg.org/PortableInterceptor/ORBId:1.0",
    "ORBId",
    &CORBA::_tc_string);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ORBId =
    &_tao_tc_PortableInterceptor_ORBId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_AdapterName (
    CORBA::tk_alias,
    "IDL:omg.org/PortableInterceptor/AdapterName:1.0",
    "AdapterName",
    &CORBA::_tc_StringSeq);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_AdapterName =
    &_tao_tc_PortableInterceptor_AdapterName;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ObjectId (
    CORBA::tk_alias,
    "IDL:omg.org/PortableInterceptor/ObjectId:1.0",
    "ObjectId",
    &CORBA::_tc_OctetSeq);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ObjectId =
    &_tao_tc_PortableInterceptor_ObjectId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_AdapterManagerId (
    CORBA::tk_alias,
    "IDL:omg.org/PortableInterceptor/AdapterManagerId:1.0",
    "AdapterManagerId",
    &CORBA::_tc_long);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_AdapterManagerId =
    &_tao_tc_PortableInterceptor_AdapterManagerId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_AdapterState (
    CORBA::tk_alias,
    "IDL:omg.org/PortableInterceptor/AdapterState:1.0",
    "AdapterState",
    &CORBA::_tc_short);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_AdapterState =
    &_tao_tc_PortableInterceptor_AdapterState;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_SlotId (
    CORBA::tk_alias,
    "IDL:omg.org/PortableInterceptor/SlotId:1.0",
    "SlotId",
    &CORBA::_tc_ulong);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_SlotId =
    &_tao_tc_PortableInterceptor_SlotId;
}



// TAO_IDL - Generated from
// be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_PortableInterceptor_ReplyStatus (
    CORBA::tk_alias,
    "IDL:omg.org/PortableInterceptor/ReplyStatus:1.0",
    "ReplyStatus",
    &CORBA::_tc_short);
  
namespace PortableInterceptor
{
  ::CORBA::TypeCode_ptr const _tc_ReplyStatus =
    &_tao_tc_PortableInterceptor_ReplyStatus;
}


