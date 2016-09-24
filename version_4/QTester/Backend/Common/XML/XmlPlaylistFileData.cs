using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml;

namespace QTester.Backend.Common.XML
{
    class XmlPlaylistFileData : IXmlFileData
    {
        public XmlPlaylistFileData(string _FileName)
        {
            xmlDoc = new XmlDocument();

            if (File.Exists(_FileName))
            {
                xmlDoc.Load(_FileName);
            }
            else
            {
                XmlElement elmNew = xmlDoc.CreateElement("Title");
                //XmlText txtFileFormat = xmlDoc.CreateTextNode(XmlTitleTag);
                //xmlDoc.AppendChild(elmNew);
                //xmlDoc.LastChild.AppendChild(txtFileFormat);
                //xmlDoc.Save(XmlFileName);
            }

        }

        public string getTagValue(string _TheTag)
        {
            return _TheTag;
        }

        public void setTagValue(string _TheTag, string _TheValue)
        {

        }

        private XmlDocument xmlDoc;// = new XmlDocument();
    }
}
