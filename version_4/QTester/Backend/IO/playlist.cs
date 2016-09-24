using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using QTester.Backend.Common;

namespace QTester.Backend
{
    class playlist
    {
        public playlist(String _FileName)
        {
            XmlData = new XMLWrapper(_FileName, constants.XML_TITLE_START_TAG);
        }

        
        private XMLWrapper XmlData;
        
    }
}
