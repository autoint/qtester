using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace XML_Concepts.XML
{
    interface IXmlFileData
    {

        string getTagValue(string _TheTag);
        void setTagValue(string _TheTag, string _TheValue);
    }
}
