//==================================================================
/**
 *  @file  CCD_Handler.cpp
 *
 *  $Id$
 *
 *  @author Emre Turkay  <turkaye@dre.vanderbilt.edu>
 */
//=====================================================================

#ifndef CCD_HANDLER_C
#define CCD_HANDLER_C

#include "tao/Exception.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"

#include "Property_Handler.h"
#include "CompIntrDesc_Handler.h"
#include "DT_Handler.h"
#include <iostream>

using std::cerr;
using std::endl;

namespace CIAO
{
  namespace Config_Handler
  {
    CCD_Handler::CCD_Handler (DOMDocument* doc, unsigned long filter)
      : // traverse_ (doc),
        root_ (doc->getDocumentElement()),
        filter_ (filter),
        iter_ (doc->createNodeIterator (this->root_,
					this->filter_,
					0,
					true)),
        release_ (true)
    {}

    CCD_Handler::CCD_Handler (DOMNodeIterator* iter, bool release)
      : // traverse_ (0),
	root_ (0), filter_ (0), iter_ (iter), release_ (release)
    {}


    CCD_Handler::~CCD_Handler()
    {
      if (this->release_)
        this->iter_->release();
    }

    /// handle the package configuration and populate it
    void CCD_Handler::process_ComponentInterfaceDescription
      (::Deployment::ComponentInterfaceDescription &ccd)
    {
      for (DOMNode* node = this->iter_->nextNode();
           node != 0;
           node = this->iter_->nextNode())
        {
          XStr node_name (node->getNodeName());
          if (node_name == XStr (ACE_TEXT ("label")))
            {
              // Fetch the text node which contains the "label"
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_label (text->getNodeValue(), ccd);
            }
          else if (node_name == XStr (ACE_TEXT ("UUID")))
            {
              // Fetch the text node which contains the "UUID"
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_UUID (text->getNodeValue(), ccd);
            }
          else if (node_name == XStr (ACE_TEXT ("specificType")))
            {
              // Fetch the text node which contains the "specificType"
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_specificType (text->getNodeValue(), ccd);
            }
          else if (node_name == XStr (ACE_TEXT ("supportedType")))
            {
              // Fetch the text node which contains the "supportedType"
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_supportedType (text->getNodeValue(), ccd);
            }
          else if (node_name == XStr (ACE_TEXT ("configProperty")))
            {
              this->process_config_property_element (node,
                                                     this->doc_,
                                                     this->iter_,
                                                     ccd);
            }
          else if (node_name == XStr (ACE_TEXT ("infoProperty")))
            {
              this->process_info_property_element (node,
                                                   this->doc_,
                                                   this->iter_,
                                                   ccd);
            }
          else if (node_name == XStr (ACE_TEXT ("property")))
            {
              this->process_property_element (node, this->doc_,
                                          this->iter_,
                                          ccd);
            }
          else if (node_name == XStr (ACE_TEXT ("port")))
            {
              this->process_port_element (node, this->doc_,
                                          this->iter_,
                                          ccd);
            }
          else
            {
              // ??? How did we get here ???
              ACE_THROW (CORBA::INTERNAL());
            }
        }
      return;
    }

    /// handle label attribute
    void CCD_Handler::process_label
      (const XMLCh* name, ::Deployment::ComponentInterfaceDescription &ccd)
    {
      if (name)
        {
          ccd.label = XMLString::transcode (name);
        }
    }

    /// handle UUID attribute
    void CCD_Handler::process_UUID
      (const XMLCh* name, ::Deployment::ComponentInterfaceDescription &ccd)
    {
      if (name)
        {
          ccd.UUID = XMLString::transcode (name);
        }
    }

    /// handle specificType attribute
    void CCD_Handler::process_specificType
      (const XMLCh* name, ::Deployment::ComponentInterfaceDescription &ccd)
    {
      if (name)
        {
          ccd.specificType = XMLString::transcode (name);
        }
    }

    /// handle supportedType attribute
    void CCD_Handler::process_supportedType
      (const XMLCh* name, ::Deployment::ComponentInterfaceDescription &ccd)
    {
      if (name)
        {
	  // increase the length of the sequence
	  CORBA::ULong i (ccd.supportedType.length ());
	  ccd.supportedType.length (i + 1);

	  // push back the last item
          ccd.supportedType[i] = XMLString::transcode (name);
        }
    }

    // handle config property element
    void CCD_Handler::process_config_property_element (DOMNode* node,
          DOMDocument* doc,
          DOMNodeIterator* iter,
          Deployment::ComponentInterfaceDescription& ccd)
    {
      if (node->hasAttributes ())
        {
          DOMNamedNodeMap* named_node_map = node->getAttributes ();
          int length = named_node_map->getLength ();
          CORBA::ULong i (ccd.configProperty.length ());
          ccd.configProperty.length (i + 1);
          if (length == 1)
            {
              Property_Handler::process_Property
                 (iter, ccd.configProperty[i]);
            }
          else if (length > 1)
            {
              this->process_attributes_for_property
                (named_node_map, doc,
                 iter, i, ccd.configProperty[i]);
            }
        }
    }

    // handle property element
    void CCD_Handler::process_property_element (DOMNode* node,
          DOMDocument* doc,
          DOMNodeIterator* iter,
          Deployment::ComponentInterfaceDescription& ccd)
    {
      if (node->hasAttributes ())
        {
          DOMNamedNodeMap* named_node_map = node->getAttributes ();
          int length = named_node_map->getLength ();
          CORBA::ULong i (ccd.property.length ());
          ccd.property.length (i + 1);
          if (length == 1)
            {
              this->process_comp_property
                 (doc, iter, ccd.property[i]);
            }
          else if (length > 1)
            {
              this->process_attributes_for_comp_property
                (named_node_map, doc,
                 iter, i, ccd.property[i]);
            }
        }
    }

    // handle info property element
    void CCD_Handler::process_info_property_element (DOMNode* node,
          DOMDocument* doc,
          DOMNodeIterator* iter,
          Deployment::ComponentInterfaceDescription& ccd)
    {
      if (node->hasAttributes ())
        {
          DOMNamedNodeMap* named_node_map = node->getAttributes ();
          int length = named_node_map->getLength ();
          CORBA::ULong i (ccd.infoProperty.length ());
          ccd.infoProperty.length (i + 1);
          if (length == 1)
            {
              Property_Handler::process_Property
                 (iter, ccd.infoProperty[i]);
            }
          else if (length > 1)
            {
              this->process_attributes_for_property
                (named_node_map, doc,
                 iter, i, ccd.infoProperty[i]);
            }
        }
    }

    // handle component port desc element
    void CCD_Handler::process_port_element (DOMNode* node,
          DOMDocument* doc,
          DOMNodeIterator* iter,
          Deployment::ComponentInterfaceDescription& ccd)
    {
      if (node->hasAttributes ())
        {
          DOMNamedNodeMap* named_node_map = node->getAttributes ();
          int length = named_node_map->getLength ();
          CORBA::ULong i (ccd.port.length ());
          ccd.port.length (i + 1);
          if (length == 1)
            {
              this->process_port
                 (doc, iter, ccd.port[i]);
            }
          else if (length > 1)
            {
              this->process_attributes_for_port
                (named_node_map, doc,
                 iter, i, ccd.port[i]);
            }
        }
    }

    /// process component property element
    void CCD_Handler::process_comp_property (DOMDocument*,
           DOMNodeIterator* iter,
           Deployment::ComponentPropertyDescription& property)
    {
      for (DOMNode* node = iter->nextNode();
           node != 0;
           node = iter->nextNode ())
        {
          XStr node_name (node->getNodeName());
          if (node_name == XStr (ACE_TEXT ("name")))
            {
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_pro_name (text->getNodeValue(), property);
            }
          else if (node_name == XStr (ACE_TEXT ("type")))
            {
              int argc = 0;
              char ** argv = 0;
              CORBA::ORB_ptr orb = CORBA::ORB_init (argc, argv, "");
              DT_Handler::process_DataType (iter, property.type.in (),
                                            orb);
            }
          else
            {
              iter->previousNode();
              return;
            }
        }
    }

    void CCD_Handler::process_pro_name (const XMLCh* name,
       Deployment::ComponentPropertyDescription& property)
    {
      if (name)
        {
          property.name = XMLString::transcode (name);
        }
    }

    void CCD_Handler::process_attributes_for_comp_property
         (DOMNamedNodeMap* named_node_map,
          DOMDocument* doc,
          DOMNodeIterator* iter,
          int value,
          Deployment::ComponentPropertyDescription& property)
    {
      int length = named_node_map->getLength ();

      for (int j = 0; j < length; j++)
        {
          DOMNode* attribute_node = named_node_map->item (j);
          XStr strattrnodename
             (attribute_node->getNodeName ());
          ACE_TString aceattrnodevalue =  XMLString::transcode
             (attribute_node->getNodeValue ());

          if (strattrnodename == XStr (ACE_TEXT ("xmi:id")))
            {
              this->process_comp_property
                 (doc, iter, property);
              id_map_.bind (aceattrnodevalue, value);
            }
          else if (strattrnodename == XStr (ACE_TEXT ("href")))
            {
              XMLURL xml_url (aceattrnodevalue.c_str ());
              XMLURL result (aceattrnodevalue.c_str ());
              std::string url_string = aceattrnodevalue.c_str ();
              ACE_TString doc_path =
               XMLString::transcode ( doc->getDocumentURI ());
              result.makeRelativeTo
                 (XMLString::transcode (doc_path.c_str ()));
              ACE_TString final_url =
               XMLString::transcode (result.getURLText ());

              DOMDocument* href_doc;

              if (xml_url.isRelative ())
                {
                  href_doc = this->create_document
                       (final_url.c_str ());
                }
              else
                {
                  href_doc = this->create_document
                       (url_string.c_str ());
                }

              DOMDocumentTraversal* traverse (href_doc);
              DOMNode* root = (href_doc->getDocumentElement ());
              unsigned long filter = DOMNodeFilter::SHOW_ELEMENT |
                                     DOMNodeFilter::SHOW_TEXT;
              DOMNodeIterator* href_iter = traverse->createNodeIterator
                                              (root,
                                               filter,
                                               0,
                                               true);
              href_iter->nextNode ();
              this->process_comp_property
                 (href_doc, href_iter, property);
            }
        }

      return;
    }

    /// process port element
    void CCD_Handler::process_port (DOMDocument*,
           DOMNodeIterator* iter,
           Deployment::ComponentPortDescription& port)
    {
      for (DOMNode* node = iter->nextNode();
           node != 0;
           node = iter->nextNode ())
        {
          XStr node_name (node->getNodeName());
          if (node_name == XStr (ACE_TEXT ("name")))
            {
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_port_name (text->getNodeValue(), port);
            }
          else if (node_name == XStr (ACE_TEXT ("specificType")))
            {
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_port_name (text->getNodeValue(), port);
            }
          else if (node_name == XStr (ACE_TEXT ("supportedType")))
            {
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_port_type (text->getNodeValue(), port);
            }
          else if (node_name == XStr (ACE_TEXT ("provider")))
            {
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_port_provider (text->getNodeValue(), port);
            }
          else if (node_name == XStr (ACE_TEXT ("exclusiveProvider")))
            {
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_port_exprovider (text->getNodeValue(), port);
            }
          else if (node_name == XStr (ACE_TEXT ("exclusiveUser")))
            {
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_port_exuser (text->getNodeValue(), port);
            }
          else if (node_name == XStr (ACE_TEXT ("optional")))
            {
              node = this->iter_->nextNode();
              DOMText* text = ACE_reinterpret_cast (DOMText*, node);
              this->process_port_optional (text->getNodeValue(), port);
            }
          else
            {
              iter->previousNode();
              return;
            }
        }
    }

    void CCD_Handler::process_port_name (const XMLCh* name,
       Deployment::ComponentPortDescription& port)
    {
      if (name)
        {
          port.name = XMLString::transcode (name);
        }
    }

    void CCD_Handler::process_port_type (const XMLCh* type,
       Deployment::ComponentPortDescription& port)
    {
      if (type)
        {
          port.specificType = XMLString::transcode (type);
        }
    }

    void CCD_Handler::process_port_provider (const XMLCh* provider,
       Deployment::ComponentPortDescription& port)
    {
      XStr true_val ("true");
      XStr true_cap_val ("TRUE");
      XStr value (provider);

      if (value == true_val || value == true_cap_val)
        {
          port.provider = 1;
        }
      else
        {
          port.provider = 0;
        }
    }

    void CCD_Handler::process_port_exprovider (const XMLCh* provider,
       Deployment::ComponentPortDescription& port)
    {
      XStr true_val ("true");
      XStr true_cap_val ("TRUE");
      XStr value (provider);

      if (value == true_val || value == true_cap_val)
        {
          port.exclusiveProvider = 1;
        }
      else
        {
          port.exclusiveProvider = 0;
        }
    }

    void CCD_Handler::process_port_exuser (const XMLCh* user,
       Deployment::ComponentPortDescription& port)
    {
      XStr true_val ("true");
      XStr true_cap_val ("TRUE");
      XStr value (user);

      if (value == true_val || value == true_cap_val)
        {
          port.exclusiveUser = 1;
        }
      else
        {
          port.exclusiveUser = 0;
        }
    }

    void CCD_Handler::process_port_optional (const XMLCh* optional,
       Deployment::ComponentPortDescription& port)
    {
      XStr true_val ("true");
      XStr true_cap_val ("TRUE");
      XStr value (optional);

      if (value == true_val || value == true_cap_val)
        {
          port.optional = 1;
        }
      else
        {
          port.optional = 0;
        }
    }

    void CCD_Handler::process_attributes_for_port
         (DOMNamedNodeMap* named_node_map,
          DOMDocument* doc,
          DOMNodeIterator* iter,
          int value,
          Deployment::ComponentPortDescription& port)
    {
      int length = named_node_map->getLength ();

      for (int j = 0; j < length; j++)
        {
          DOMNode* attribute_node = named_node_map->item (j);
          XStr strattrnodename
             (attribute_node->getNodeName ());
          ACE_TString aceattrnodevalue =  XMLString::transcode
             (attribute_node->getNodeValue ());

          if (strattrnodename == XStr (ACE_TEXT ("xmi:id")))
            {
              this->process_port
                 (doc, iter, port);
              id_map_.bind (aceattrnodevalue, value);
            }
          else if (strattrnodename == XStr (ACE_TEXT ("href")))
            {
              XMLURL xml_url (aceattrnodevalue.c_str ());
              XMLURL result (aceattrnodevalue.c_str ());
              std::string url_string = aceattrnodevalue.c_str ();
              ACE_TString doc_path =
               XMLString::transcode ( doc->getDocumentURI ());
              result.makeRelativeTo
                 (XMLString::transcode (doc_path.c_str ()));
              ACE_TString final_url =
               XMLString::transcode (result.getURLText ());

              DOMDocument* href_doc;

              if (xml_url.isRelative ())
                {
                  href_doc = this->create_document
                       (final_url.c_str ());
                }
              else
                {
                  href_doc = this->create_document
                       (url_string.c_str ());
                }

              DOMDocumentTraversal* traverse (href_doc);
              DOMNode* root = (href_doc->getDocumentElement ());
              unsigned long filter = DOMNodeFilter::SHOW_ELEMENT |
                                     DOMNodeFilter::SHOW_TEXT;
              DOMNodeIterator* href_iter = traverse->createNodeIterator
                                              (root,
                                               filter,
                                               0,
                                               true);
              href_iter->nextNode ();
              this->process_port
                 (href_doc, href_iter, port);
            }
        }

      return;
    }

    void CCD_Handler::process_attributes_for_property
         (DOMNamedNodeMap* named_node_map,
          DOMDocument* doc,
          DOMNodeIterator* iter,
          int value,
          Deployment::Property& ccd_property)
    {
      int length = named_node_map->getLength ();

      for (int j = 0; j < length; j++)
        {
          DOMNode* attribute_node = named_node_map->item (j);
          XStr strattrnodename
             (attribute_node->getNodeName ());
          ACE_TString aceattrnodevalue =  XMLString::transcode
             (attribute_node->getNodeValue ());

          if (strattrnodename == XStr (ACE_TEXT ("xmi:id")))
            {
              Property_Handler::process_Property (iter,
                                                  ccd_property);
              id_map_.bind (aceattrnodevalue, value);
            }
          else if (strattrnodename == XStr (ACE_TEXT ("href")))
            {
              XMLURL xml_url (aceattrnodevalue.c_str ());
              XMLURL result (aceattrnodevalue.c_str ());
              std::string url_string = aceattrnodevalue.c_str ();
              ACE_TString doc_path =
               XMLString::transcode ( doc->getDocumentURI ());
              result.makeRelativeTo
                 (XMLString::transcode (doc_path.c_str ()));
              ACE_TString final_url =
               XMLString::transcode (result.getURLText ());

              DOMDocument* href_doc;

              if (xml_url.isRelative ())
                {
                  href_doc = this->create_document
                       (final_url.c_str ());
                }
              else
                {
                  href_doc = this->create_document
                       (url_string.c_str ());
                }

              DOMDocumentTraversal* traverse (href_doc);
              DOMNode* root = (href_doc->getDocumentElement ());
              unsigned long filter = DOMNodeFilter::SHOW_ELEMENT |
                                     DOMNodeFilter::SHOW_TEXT;
              DOMNodeIterator* href_iter = traverse->createNodeIterator
                                              (root,
                                               filter,
                                               0,
                                               true);
              href_iter->nextNode ();
              Property_Handler::process_Property (href_iter,
                                                  ccd_property);
            }
        }

      return;
    }

    DOMDocument* CCD_Handler::create_document (const char *url)
    {

      xercesc::XMLPlatformUtils::Initialize();
      static const XMLCh gLS[] = { xercesc::chLatin_L,
                                   xercesc::chLatin_S,
                                   xercesc::chNull };

      DOMImplementation* impl
        = DOMImplementationRegistry::getDOMImplementation(gLS);

      DOMBuilder* parser =
        ((DOMImplementationLS*)impl)->createDOMBuilder
              (DOMImplementationLS::MODE_SYNCHRONOUS, 0);

      // Discard comment nodes in the document
      parser->setFeature (XMLUni::fgDOMComments, false);

      // Disable datatype normalization. The XML 1.0 attribute value
      // normalization always occurs though.
      parser->setFeature (XMLUni::fgDOMDatatypeNormalization, true);

      // Do not create EntityReference nodes in the DOM tree. No
      // EntityReference nodes will be created, only the nodes
      // corresponding to their fully expanded sustitution text will be
      // created.
      parser->setFeature (XMLUni::fgDOMEntities, false);

      // Perform Namespace processing.
      parser->setFeature (XMLUni::fgDOMNamespaces, true);

      // Perform Validation
      parser->setFeature (XMLUni::fgDOMValidation, true);

      // Do not include ignorable whitespace in the DOM tree.
      parser->setFeature (XMLUni::fgDOMWhitespaceInElementContent, false);

      // Enable the parser's schema support.
      parser->setFeature (XMLUni::fgXercesSchema, true);

      // Enable full schema constraint checking, including checking which
      // may be time-consuming or memory intensive. Currently, particle
      // unique attribution constraint checking and particle derivation
      // restriction checking are controlled by this option.
      parser->setFeature (XMLUni::fgXercesSchemaFullChecking, true);

      // The parser will treat validation error as fatal and will exit.
      parser->setFeature (XMLUni::fgXercesValidationErrorAsFatal, true);


      DOMDocument* doc = parser->parseURI (url);
      ACE_TString root_node_name;
      root_node_name = XMLString::transcode
          (doc->getDocumentElement ()->getNodeName ());

      return doc;
    }

  }
}

#endif /* CCD_HANDLER_C */
