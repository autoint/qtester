using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QTester.Backend.Common
{
    static class constants
    {
        public const string XML_START_TAG = "<";
        public const string XML_END_TAG = "<";
        public const string XML_ESCAPE_TAG = "/";

        public const string XML_TYPE_PLAYLIST_START_TAG = "QTESTER_PLAYLIST";
        public const string XML_TYPE_PLAYLIST_END_TAG = XML_ESCAPE_TAG + XML_TYPE_PLAYLIST_START_TAG;

        public const string XML_HEADER_SECTION_START_TAG = "HEADER";
        public const string XML_HEADER_SECTION_END_TAG = XML_ESCAPE_TAG + XML_HEADER_SECTION_START_TAG;

        public const string XML_VERSION_START_TAG = "VERSION";
        public const string XML_VERSION_END_TAG = XML_ESCAPE_TAG + XML_VERSION_START_TAG;

        public const string XML_VERSION_VALUE = "QTester_V_2_0";

        public const string XML_BODY_SECTION_START_TAG = "BODY";
        public const string XML_BODY_SECTION_END_TAG = XML_ESCAPE_TAG + XML_BODY_SECTION_START_TAG;

        public const string XML_CONFIGURATION_START_TAG = "CONFIGURATION";
        public const string XML_CONFIGURATION_END_TAG = XML_ESCAPE_TAG + XML_CONFIGURATION_START_TAG;

        public const string XML_OPTIONS_START_TAG = "OPTIONS";
        public const string XML_OPTIONS_END_TAG = XML_ESCAPE_TAG + XML_OPTIONS_START_TAG;

        public const string XML_TITLE_START_TAG = "VIDEOS";
        public const string XML_TITLE_END_TAG = XML_ESCAPE_TAG + XML_TITLE_START_TAG;

        public const string XML_VIDEOS_START_TAG = "VIDEOS";
        public const string XML_VIDEOS_END_TAG = XML_ESCAPE_TAG + XML_VIDEOS_START_TAG;
    }
}
