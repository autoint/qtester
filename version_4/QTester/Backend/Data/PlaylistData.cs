using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QTester.Backend.Data
{
    public class PlaylistData
    {
        String mPlaylistName;
        String mAuthor;
        String mPassword;
        DateTime mCreateDate;
        DateTime mLastSavedDate;
        String mNotes;
        UInt16 mNumberOfInputs;
        struct inputDataType
        {
            String label;
            Char key;

            public inputDataType(String label, Char key)
            {
                this.label = label;
                this.key = key;
            }
        }
        List<inputDataType> mInputData;
        List<String> mVideoList;
        String mExportName;
        String mLastExportPath;

       
        public PlaylistData()
        {
            mInputData = new List<inputDataType>(4);
            mVideoList = new List<string>(0);
            mExportName = "";
            mLastExportPath = "";
        }

        public void UpdateConfiguration(String playlistName, String author,
                                        String password, DateTime createDate,
                                        DateTime lastSavedDate, String notes)
        {
            mPlaylistName = playlistName;
            mAuthor = author;
            mPassword = password;
            mCreateDate = createDate;
            mLastSavedDate = lastSavedDate;
            mNotes = notes;

        }

        public void UpdateCommand(UInt16 numberOfInputs,
                                    String label1, String key1,
                                    String label2, String key2,
                                    String label3, String key3,
                                    String label4, String key4)
        {
            mNumberOfInputs = numberOfInputs;
            mInputData.Clear();
            for (int i = 0; i < numberOfInputs; ++i)
            {
                switch (i)
                {
                    case 0:
                        mInputData.Add(new inputDataType(label1, (key1.ToCharArray())[0]));
                        break;
                    case 1:
                        mInputData.Add(new inputDataType(label2, (key2.ToCharArray())[0]));
                        break;
                    case 2:
                        mInputData.Add(new inputDataType(label3, (key3.ToCharArray())[0]));
                        break;
                    case 3:
                        mInputData.Add(new inputDataType(label4, (key4.ToCharArray())[0]));
                        break;
                    default:
                        break;
                }
            }
        }

        public void UpdateVideoList(List<String> videoList)
        {
            mVideoList = videoList;
        }

        public List<String> getVideoList()
        {
            return mVideoList;
        }

        public void UpdateExport(String exportPlaylistPathName)
        {
            mLastExportPath = exportPlaylistPathName;
        }
    }
}
