using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml;
using QTester.Backend.Common;

namespace QTester.Backend.Common
{
    class XMLWrapper
    {
        public XMLWrapper(String _FileName, String _XmlTitleTag)
        {
            XmlFileName = _FileName;
            XmlTitleTag = _XmlTitleTag;

            xmlDoc = new XmlDocument();

            if (File.Exists(XmlFileName))
            {
                xmlDoc.Load(XmlFileName);

                XmlElement elmNew = xmlDoc.GetElementById(constants.XML_TYPE_PLAYLIST_START_TAG);
                //String theTitleString = elmNew.GetAttribute(
                //if (elmNew.
            }
            else
            {
                XmlElement elmNew = xmlDoc.CreateElement("Title");
                XmlText txtFileFormat = xmlDoc.CreateTextNode(XmlTitleTag);
                xmlDoc.AppendChild(elmNew);
                xmlDoc.LastChild.AppendChild(txtFileFormat);
                xmlDoc.Save(XmlFileName);                
            }
        }

        public void FindElement()
        {
        }

        public void NextElement()
        {
        }

        public void DeleteElement()
        {
        }

        public void AddElement(String _NewElement, int _Location)
        {
        }

        public void save()
        {
            xmlDoc.Save(XmlFileName);
        }

        private const int TAIL = -1;
        private const int FRONT = 0;

        private XmlDocument xmlDoc;// = new XmlDocument();
        private String XmlFileName;
        private String XmlTitleTag;
    }
}
