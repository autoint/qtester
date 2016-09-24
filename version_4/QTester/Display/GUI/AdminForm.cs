using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using QTester.Display.Common;
using QTester.Backend.Data;
using QTester.Backend.Common.XML;


namespace QTester.Display
{
    public partial class AdminForm : Form
    {
        private Int32 activeTabIndex;
        private PlaylistData playlistData;

        public AdminForm()
        {
            InitializeComponent();
            activeTabIndex = 0;
            playlistData = new PlaylistData();
        }

        public AdminForm(PlaylistData _playlistData)
        {
            playlistData = _playlistData;
            InitializeComponent();
            activeTabIndex = 0;
        }

        public void saveTab(Int32 tabIndex)
        {
            switch (tabIndex)
            {
                case 0:          
                        playlistData.UpdateConfiguration(this.textBoxPlayListName.Text.ToString(),
                                                        this.textBoxAuthorName.Text.ToString(),
                                                        this.textBoxPassword.Text.ToString(),
                                                        this.dateTimePickerCreated.Value,
                                                        this.dateTimePicker1.Value,
                                                        this.textBoxNotes.Text.ToString());                 
                        break;
                case 1:
                    playlistData.UpdateCommand(/*UInt16.Parse(this.domainUpDownInputs.Text),*/0,
                                                this.textBoxLabel1.Text.ToString(),
                                                this.textBoxKeyStroke1.Text.ToString(),
                                                this.textBoxLabel2.Text.ToString(),
                                                this.textBoxKeyStroke2.Text.ToString(),
                                                this.textBoxLabel3.Text.ToString(),
                                                this.textBoxKeyStroke3.Text.ToString(),
                                                this.textBoxLabel4.Text.ToString(),
                                                this.textBoxKeyStroke4.Text.ToString());
                    break;
                case 2:
                    //this.listView1.
                    //playlistData.UpdateVideoList();
                    break;
                case 3:
                    
                    break;
                case 4:                    
                    playlistData.UpdateExport(this.textBoxExportPlaylistPathName.Text);
                    break;
            }

        }

        public void saveForm()
        {

        }


        private void domainUpDown1_SelectedItemChanged(object sender, EventArgs e)
        {
            switch (domainUpDownInputs.Text.ToString())
            {
                case "4":
                    labelOption4.Visible = true;
                    textBoxLabel4.Visible = true;
                    textBoxKeyStroke4.Visible = true;
                    labelOption3.Visible = true;
                    textBoxLabel3.Visible = true;
                    textBoxKeyStroke3.Visible = true;
                    labelOption2.Visible = true;
                    textBoxLabel2.Visible = true;
                    textBoxKeyStroke2.Visible = true;
                    labelOption1.Visible = true;
                    textBoxLabel1.Visible = true;
                    textBoxKeyStroke1.Visible = true;
                    break;
                case "3":
                    labelOption4.Visible = false;
                    textBoxLabel4.Visible = false;
                    textBoxKeyStroke4.Visible = false;
                    labelOption3.Visible = true;
                    textBoxLabel3.Visible = true;
                    textBoxKeyStroke3.Visible = true;
                    labelOption2.Visible = true;
                    textBoxLabel2.Visible = true;
                    textBoxKeyStroke2.Visible = true;
                    labelOption1.Visible = true;
                    textBoxLabel1.Visible = true;
                    textBoxKeyStroke1.Visible = true;
                    break;
                case "2":
                    labelOption4.Visible = false;
                    textBoxLabel4.Visible = false;
                    textBoxKeyStroke4.Visible = false;
                    labelOption3.Visible = false;
                    textBoxLabel3.Visible = false;
                    textBoxKeyStroke3.Visible = false;
                    labelOption2.Visible = true;
                    textBoxLabel2.Visible = true;
                    textBoxKeyStroke2.Visible = true;
                    labelOption1.Visible = true;
                    textBoxLabel1.Visible = true;
                    textBoxKeyStroke1.Visible = true;
                    break;
                case "1":
                    labelOption4.Visible = false;
                    textBoxLabel4.Visible = false;
                    textBoxKeyStroke4.Visible = false;
                    labelOption3.Visible = false;
                    textBoxLabel3.Visible = false;
                    textBoxKeyStroke3.Visible = false;
                    labelOption2.Visible = false;
                    textBoxLabel2.Visible = false;
                    textBoxKeyStroke2.Visible = false;
                    labelOption1.Visible = true;
                    textBoxLabel1.Visible = true;
                    textBoxKeyStroke1.Visible = true;
                    break;
                default:
                    labelOption4.Visible = false;
                    textBoxLabel4.Visible = false;
                    textBoxKeyStroke4.Visible = false;
                    labelOption3.Visible = false;
                    textBoxLabel3.Visible = false;
                    textBoxKeyStroke3.Visible = false;
                    labelOption2.Visible = false;
                    textBoxLabel2.Visible = false;
                    textBoxKeyStroke2.Visible = false;
                    labelOption1.Visible = false;
                    textBoxLabel1.Visible = false;
                    textBoxKeyStroke1.Visible = false;
                    break;
            }
            
        }

        private void listView1_MouseDown(object sender, MouseEventArgs e)
        {

        }

        private void addToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string[] s = new string[3];
            s[0] = "Name";            
            s[1] = "Type";
            s[2] = "Path to Video";
            listView1.Items.Add(new ListViewItem(s));
            
        }

        private void removeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            listView1.Items.Remove(listView1.GetListviewItemSelected());
        }

        private void moveUpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ListViewItem itemToBeMoved = listView1.GetListviewItemSelected();
            int currentIndex = listView1.Items.IndexOf(itemToBeMoved);
            if (currentIndex > 0)
            {
                --currentIndex;
                listView1.Items.Remove(itemToBeMoved);
                listView1.Items.Insert(currentIndex, itemToBeMoved);
            }
        }

        private void moveDownToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ListViewItem itemToBeMoved = listView1.GetListviewItemSelected();
            int currentIndex = listView1.Items.IndexOf(itemToBeMoved);
            if (++currentIndex < listView1.Items.Count)
            {
                listView1.Items.Remove(itemToBeMoved);
                listView1.Items.Insert(currentIndex, itemToBeMoved);
            }
        }

        private void listView1_DoubleClick(object sender, EventArgs e)
        {
            // Pack valid options into 
            listView1.SMKDoubleClick(sender, e);
        }

        private void adminTabControl_SelectedIndexChanged(object sender, EventArgs e)
        {

            saveTab(this.activeTabIndex);
            this.activeTabIndex = this.adminTabControl.SelectedIndex;

            switch (this.activeTabIndex)
            {
                case 0: //configuration
                    break;
                case 1: // Inputs
                    break;
                case 2: // video lists
                    try
                    {
                        Int32 numberOfLabels = Int32.Parse(domainUpDownInputs.Text);

                        string[] newComboList = new string[numberOfLabels];

                        switch (numberOfLabels)
                        {
                            case 4:
                                newComboList[3] = textBoxLabel4.Text;
                                newComboList[2] = textBoxLabel3.Text;
                                newComboList[1] = textBoxLabel2.Text;
                                newComboList[0] = textBoxLabel1.Text;
                                break;
                            case 3:
                                newComboList[2] = textBoxLabel3.Text;
                                newComboList[1] = textBoxLabel2.Text;
                                newComboList[0] = textBoxLabel1.Text;
                                break;
                            case 2:
                                newComboList[1] = textBoxLabel2.Text;
                                newComboList[0] = textBoxLabel1.Text;
                                break;
                            case 1:
                                newComboList[0] = textBoxLabel1.Text;
                                break;
                        }

                        listView1.SMKUpdateCombo(newComboList);
                    }
                    catch (FormatException exception)
                    {
                        Console.WriteLine(exception.Message);
                    }
                    break;
                case 3: //Preview
                    break;
                case 4: // Export
                    break;
                default:
                    break;
            }           
        }

        private void buttonExport_Click(object sender, EventArgs e)
        {
            string playlistFileName = textBoxExportPlaylistPathName.Text;
            if (playlistFileName.Length > 0)
            {
                string playlistPath;
                string fileName;
                playlistPath  = Path.GetDirectoryName(playlistFileName);
                playlistPath = playlistPath + "\\" +  Path.GetFileNameWithoutExtension(playlistFileName);
                // create playlist file with relative paths
                Directory.CreateDirectory(playlistPath);
                //QTester.Backend.Common.XMLPlaylistFile();
                using (StreamWriter sw = File.CreateText(playlistFileName))
                {
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + QTester.Backend.Common.XML.XMLPlaylistConstants.XML_TYPE_PLAYLIST_TAG + QTester.Backend.Common.constants.XML_END_TAG);
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + QTester.Backend.Common.XML.XMLPlaylistConstants.XML_HEADER_SECTION_TAG + QTester.Backend.Common.constants.XML_END_TAG);
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + QTester.Backend.Common.XML.XMLPlaylistConstants.XML_VERSION_TAG + QTester.Backend.Common.constants.XML_END_TAG);
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + QTester.Backend.Common.XML.XMLPlaylistConstants.XML_TITLE_TAG);
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + QTester.Backend.Common.XML.XMLPlaylistConstants.XML_VERSION_TAG + QTester.Backend.Common.constants.XML_END_TAG);
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + QTester.Backend.Common.XML.XMLPlaylistConstants.XML_HEADER_SECTION_TAG + QTester.Backend.Common.constants.XML_END_TAG);
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + QTester.Backend.Common.XML.XMLPlaylistConstants.XML_BODY_SECTION_TAG + QTester.Backend.Common.constants.XML_END_TAG);
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + QTester.Backend.Common.XML.XMLPlaylistConstants.XML_CONFIGURATION_TAG + QTester.Backend.Common.constants.XML_END_TAG);
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + QTester.Backend.Common.XML.XMLPlaylistConstants.XML_OPTIONS_TAG + QTester.Backend.Common.constants.XML_END_TAG);
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + "<No. Of Options 'n'>, <Option 1 | Label, Key>, ... <Option 'n' | Label, Key>");
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + "</OPTIONS>");
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + "<VIDEOs>");
                    sw.WriteLine("<correct option '1 .. n'>, <video name>");
                    sw.WriteLine("<correct option '1 .. n'>, <video name>");
                    sw.WriteLine(":");
                    sw.WriteLine(":");
                    sw.WriteLine(":");
                    sw.WriteLine("<correct option '1 .. n'>, <video name>");
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + "</VIDEOs>");
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + "</BODY>");
                    sw.WriteLine(QTester.Backend.Common.constants.XML_START_TAG + "</QTESTER_PLAYLIST>");
                }
                //}
                
                // create directory to store media
                
                //if (!Directory.Exists(destDirName))
                //{
                //    Directory.CreateDirectory(destDirName);
                //}



                // copy media to created directory

                // finalise
            }
        }

        private void buttonTest_Click(object sender, EventArgs e)
        {

        }

        private void textBoxtextBoxExportPlaylistPathName_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            System.Windows.Forms.SaveFileDialog fileDialog = new System.Windows.Forms.SaveFileDialog();
            fileDialog.FileName = textBoxExportPlaylistPathName.Text;
            fileDialog.DefaultExt = ".qtp";
            fileDialog.OverwritePrompt = true;
            fileDialog.AddExtension = true;
            fileDialog.Filter = "QTester Playlist |*.qtp|All files (*.*)|*.*";
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                textBoxExportPlaylistPathName.Text = fileDialog.FileName;
            }
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
