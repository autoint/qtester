namespace QTester.Display
{
    partial class AdminForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.adminTabControl = new System.Windows.Forms.TabControl();
            this.Configuration = new System.Windows.Forms.TabPage();
            this.labelSavedAs = new System.Windows.Forms.Label();
            this.textBoxSavedAs = new System.Windows.Forms.TextBox();
            this.labelPassword = new System.Windows.Forms.Label();
            this.textBoxPassword = new System.Windows.Forms.TextBox();
            this.labelNotes = new System.Windows.Forms.Label();
            this.textBoxNotes = new System.Windows.Forms.TextBox();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.labelDateLastUpdated = new System.Windows.Forms.Label();
            this.dateTimePickerCreated = new System.Windows.Forms.DateTimePicker();
            this.labelDateCreated = new System.Windows.Forms.Label();
            this.labelAuthor = new System.Windows.Forms.Label();
            this.textBoxAuthorName = new System.Windows.Forms.TextBox();
            this.labelPlayListName = new System.Windows.Forms.Label();
            this.textBoxPlayListName = new System.Windows.Forms.TextBox();
            this.Command = new System.Windows.Forms.TabPage();
            this.textBoxKeyStroke4 = new System.Windows.Forms.TextBox();
            this.textBoxLabel4 = new System.Windows.Forms.TextBox();
            this.labelOption4 = new System.Windows.Forms.Label();
            this.textBoxKeyStroke3 = new System.Windows.Forms.TextBox();
            this.textBoxLabel3 = new System.Windows.Forms.TextBox();
            this.labelOption3 = new System.Windows.Forms.Label();
            this.textBoxKeyStroke2 = new System.Windows.Forms.TextBox();
            this.textBoxLabel2 = new System.Windows.Forms.TextBox();
            this.labelOption2 = new System.Windows.Forms.Label();
            this.textBoxKeyStroke1 = new System.Windows.Forms.TextBox();
            this.textBoxLabel1 = new System.Windows.Forms.TextBox();
            this.labelOption1 = new System.Windows.Forms.Label();
            this.LabelNumberOfInputs = new System.Windows.Forms.Label();
            this.domainUpDownInputs = new System.Windows.Forms.DomainUpDown();
            this.VideoList = new System.Windows.Forms.TabPage();
            this.listView1 = new QTester.Display.Common.EditableListBox();
            this.Label = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.Option = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.Location = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.addToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.removeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.moveUpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.moveDownToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.Preview = new System.Windows.Forms.TabPage();
            this.buttonVideoNext = new System.Windows.Forms.Button();
            this.buttonPlayControl = new System.Windows.Forms.Button();
            this.buttonVideoPrevious = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxOutputPreview = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.Export = new System.Windows.Forms.TabPage();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonTest = new System.Windows.Forms.Button();
            this.textBoxOutput = new System.Windows.Forms.TextBox();
            this.labelOutput = new System.Windows.Forms.Label();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.buttonExport = new System.Windows.Forms.Button();
            this.labelExportDirectory = new System.Windows.Forms.Label();
            this.textBoxExportPlaylistPathName = new System.Windows.Forms.TextBox();
            this.backgroundWorkerExport = new System.ComponentModel.BackgroundWorker();
            this.adminTabControl.SuspendLayout();
            this.Configuration.SuspendLayout();
            this.Command.SuspendLayout();
            this.VideoList.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.Preview.SuspendLayout();
            this.Export.SuspendLayout();
            this.SuspendLayout();
            // 
            // adminTabControl
            // 
            this.adminTabControl.Controls.Add(this.Configuration);
            this.adminTabControl.Controls.Add(this.Command);
            this.adminTabControl.Controls.Add(this.VideoList);
            this.adminTabControl.Controls.Add(this.Preview);
            this.adminTabControl.Controls.Add(this.Export);
            this.adminTabControl.Dock = System.Windows.Forms.DockStyle.Fill;
            this.adminTabControl.Location = new System.Drawing.Point(0, 0);
            this.adminTabControl.Name = "adminTabControl";
            this.adminTabControl.SelectedIndex = 0;
            this.adminTabControl.Size = new System.Drawing.Size(624, 271);
            this.adminTabControl.TabIndex = 0;
            this.adminTabControl.SelectedIndexChanged += new System.EventHandler(this.adminTabControl_SelectedIndexChanged);
            // 
            // Configuration
            // 
            this.Configuration.Controls.Add(this.labelSavedAs);
            this.Configuration.Controls.Add(this.textBoxSavedAs);
            this.Configuration.Controls.Add(this.labelPassword);
            this.Configuration.Controls.Add(this.textBoxPassword);
            this.Configuration.Controls.Add(this.labelNotes);
            this.Configuration.Controls.Add(this.textBoxNotes);
            this.Configuration.Controls.Add(this.dateTimePicker1);
            this.Configuration.Controls.Add(this.labelDateLastUpdated);
            this.Configuration.Controls.Add(this.dateTimePickerCreated);
            this.Configuration.Controls.Add(this.labelDateCreated);
            this.Configuration.Controls.Add(this.labelAuthor);
            this.Configuration.Controls.Add(this.textBoxAuthorName);
            this.Configuration.Controls.Add(this.labelPlayListName);
            this.Configuration.Controls.Add(this.textBoxPlayListName);
            this.Configuration.Location = new System.Drawing.Point(4, 22);
            this.Configuration.Name = "Configuration";
            this.Configuration.Padding = new System.Windows.Forms.Padding(3);
            this.Configuration.Size = new System.Drawing.Size(616, 245);
            this.Configuration.TabIndex = 2;
            this.Configuration.Text = "Configuration";
            this.Configuration.UseVisualStyleBackColor = true;
            // 
            // labelSavedAs
            // 
            this.labelSavedAs.AutoSize = true;
            this.labelSavedAs.Location = new System.Drawing.Point(26, 91);
            this.labelSavedAs.Name = "labelSavedAs";
            this.labelSavedAs.Size = new System.Drawing.Size(53, 13);
            this.labelSavedAs.TabIndex = 14;
            this.labelSavedAs.Text = "Saved As";
            // 
            // textBoxSavedAs
            // 
            this.textBoxSavedAs.Location = new System.Drawing.Point(85, 84);
            this.textBoxSavedAs.Name = "textBoxSavedAs";
            this.textBoxSavedAs.Size = new System.Drawing.Size(523, 20);
            this.textBoxSavedAs.TabIndex = 13;
            // 
            // labelPassword
            // 
            this.labelPassword.AutoSize = true;
            this.labelPassword.Location = new System.Drawing.Point(5, 65);
            this.labelPassword.Name = "labelPassword";
            this.labelPassword.Size = new System.Drawing.Size(74, 13);
            this.labelPassword.TabIndex = 12;
            this.labelPassword.Text = "Edit Password";
            // 
            // textBoxPassword
            // 
            this.textBoxPassword.Location = new System.Drawing.Point(85, 58);
            this.textBoxPassword.Name = "textBoxPassword";
            this.textBoxPassword.Size = new System.Drawing.Size(200, 20);
            this.textBoxPassword.TabIndex = 11;
            // 
            // labelNotes
            // 
            this.labelNotes.AutoSize = true;
            this.labelNotes.Location = new System.Drawing.Point(44, 113);
            this.labelNotes.Name = "labelNotes";
            this.labelNotes.Size = new System.Drawing.Size(35, 13);
            this.labelNotes.TabIndex = 10;
            this.labelNotes.Text = "Notes";
            // 
            // textBoxNotes
            // 
            this.textBoxNotes.Location = new System.Drawing.Point(85, 110);
            this.textBoxNotes.Multiline = true;
            this.textBoxNotes.Name = "textBoxNotes";
            this.textBoxNotes.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxNotes.Size = new System.Drawing.Size(523, 129);
            this.textBoxNotes.TabIndex = 9;
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Location = new System.Drawing.Point(408, 32);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(200, 20);
            this.dateTimePicker1.TabIndex = 8;
            this.dateTimePicker1.TabStop = false;
            // 
            // labelDateLastUpdated
            // 
            this.labelDateLastUpdated.AutoSize = true;
            this.labelDateLastUpdated.Location = new System.Drawing.Point(331, 39);
            this.labelDateLastUpdated.Name = "labelDateLastUpdated";
            this.labelDateLastUpdated.Size = new System.Drawing.Size(71, 13);
            this.labelDateLastUpdated.TabIndex = 7;
            this.labelDateLastUpdated.Text = "Last Updated";
            // 
            // dateTimePickerCreated
            // 
            this.dateTimePickerCreated.CalendarTitleBackColor = System.Drawing.SystemColors.ControlText;
            this.dateTimePickerCreated.CalendarTitleForeColor = System.Drawing.SystemColors.InactiveCaptionText;
            this.dateTimePickerCreated.Location = new System.Drawing.Point(408, 6);
            this.dateTimePickerCreated.Name = "dateTimePickerCreated";
            this.dateTimePickerCreated.Size = new System.Drawing.Size(200, 20);
            this.dateTimePickerCreated.TabIndex = 6;
            this.dateTimePickerCreated.TabStop = false;
            // 
            // labelDateCreated
            // 
            this.labelDateCreated.AutoSize = true;
            this.labelDateCreated.Location = new System.Drawing.Point(332, 13);
            this.labelDateCreated.Name = "labelDateCreated";
            this.labelDateCreated.Size = new System.Drawing.Size(70, 13);
            this.labelDateCreated.TabIndex = 5;
            this.labelDateCreated.Text = "Date Created";
            // 
            // labelAuthor
            // 
            this.labelAuthor.AutoSize = true;
            this.labelAuthor.Location = new System.Drawing.Point(41, 39);
            this.labelAuthor.Name = "labelAuthor";
            this.labelAuthor.Size = new System.Drawing.Size(38, 13);
            this.labelAuthor.TabIndex = 3;
            this.labelAuthor.Text = "Author";
            // 
            // textBoxAuthorName
            // 
            this.textBoxAuthorName.Location = new System.Drawing.Point(85, 32);
            this.textBoxAuthorName.Name = "textBoxAuthorName";
            this.textBoxAuthorName.Size = new System.Drawing.Size(200, 20);
            this.textBoxAuthorName.TabIndex = 2;
            // 
            // labelPlayListName
            // 
            this.labelPlayListName.AutoSize = true;
            this.labelPlayListName.Location = new System.Drawing.Point(9, 13);
            this.labelPlayListName.Name = "labelPlayListName";
            this.labelPlayListName.Size = new System.Drawing.Size(70, 13);
            this.labelPlayListName.TabIndex = 1;
            this.labelPlayListName.Text = "Playlist Name";
            // 
            // textBoxPlayListName
            // 
            this.textBoxPlayListName.Location = new System.Drawing.Point(85, 6);
            this.textBoxPlayListName.Name = "textBoxPlayListName";
            this.textBoxPlayListName.Size = new System.Drawing.Size(200, 20);
            this.textBoxPlayListName.TabIndex = 0;
            // 
            // Command
            // 
            this.Command.Controls.Add(this.textBoxKeyStroke4);
            this.Command.Controls.Add(this.textBoxLabel4);
            this.Command.Controls.Add(this.labelOption4);
            this.Command.Controls.Add(this.textBoxKeyStroke3);
            this.Command.Controls.Add(this.textBoxLabel3);
            this.Command.Controls.Add(this.labelOption3);
            this.Command.Controls.Add(this.textBoxKeyStroke2);
            this.Command.Controls.Add(this.textBoxLabel2);
            this.Command.Controls.Add(this.labelOption2);
            this.Command.Controls.Add(this.textBoxKeyStroke1);
            this.Command.Controls.Add(this.textBoxLabel1);
            this.Command.Controls.Add(this.labelOption1);
            this.Command.Controls.Add(this.LabelNumberOfInputs);
            this.Command.Controls.Add(this.domainUpDownInputs);
            this.Command.Location = new System.Drawing.Point(4, 22);
            this.Command.Name = "Command";
            this.Command.Padding = new System.Windows.Forms.Padding(3);
            this.Command.Size = new System.Drawing.Size(616, 245);
            this.Command.TabIndex = 0;
            this.Command.Text = "Command";
            this.Command.UseVisualStyleBackColor = true;
            // 
            // textBoxKeyStroke4
            // 
            this.textBoxKeyStroke4.Location = new System.Drawing.Point(170, 134);
            this.textBoxKeyStroke4.Name = "textBoxKeyStroke4";
            this.textBoxKeyStroke4.Size = new System.Drawing.Size(100, 20);
            this.textBoxKeyStroke4.TabIndex = 13;
            this.textBoxKeyStroke4.Text = "Key Stroke";
            this.textBoxKeyStroke4.Visible = false;
            // 
            // textBoxLabel4
            // 
            this.textBoxLabel4.Location = new System.Drawing.Point(64, 134);
            this.textBoxLabel4.Name = "textBoxLabel4";
            this.textBoxLabel4.Size = new System.Drawing.Size(100, 20);
            this.textBoxLabel4.TabIndex = 12;
            this.textBoxLabel4.Text = "Label";
            this.textBoxLabel4.Visible = false;
            // 
            // labelOption4
            // 
            this.labelOption4.AutoSize = true;
            this.labelOption4.Location = new System.Drawing.Point(8, 137);
            this.labelOption4.Name = "labelOption4";
            this.labelOption4.Size = new System.Drawing.Size(50, 13);
            this.labelOption4.TabIndex = 11;
            this.labelOption4.Text = "Option 4:";
            this.labelOption4.Visible = false;
            // 
            // textBoxKeyStroke3
            // 
            this.textBoxKeyStroke3.Location = new System.Drawing.Point(170, 108);
            this.textBoxKeyStroke3.Name = "textBoxKeyStroke3";
            this.textBoxKeyStroke3.Size = new System.Drawing.Size(100, 20);
            this.textBoxKeyStroke3.TabIndex = 10;
            this.textBoxKeyStroke3.Text = "Key Stroke";
            this.textBoxKeyStroke3.Visible = false;
            // 
            // textBoxLabel3
            // 
            this.textBoxLabel3.Location = new System.Drawing.Point(64, 108);
            this.textBoxLabel3.Name = "textBoxLabel3";
            this.textBoxLabel3.Size = new System.Drawing.Size(100, 20);
            this.textBoxLabel3.TabIndex = 9;
            this.textBoxLabel3.Text = "Label";
            this.textBoxLabel3.Visible = false;
            // 
            // labelOption3
            // 
            this.labelOption3.AutoSize = true;
            this.labelOption3.Location = new System.Drawing.Point(8, 111);
            this.labelOption3.Name = "labelOption3";
            this.labelOption3.Size = new System.Drawing.Size(50, 13);
            this.labelOption3.TabIndex = 8;
            this.labelOption3.Text = "Option 3:";
            this.labelOption3.Visible = false;
            // 
            // textBoxKeyStroke2
            // 
            this.textBoxKeyStroke2.Location = new System.Drawing.Point(170, 82);
            this.textBoxKeyStroke2.Name = "textBoxKeyStroke2";
            this.textBoxKeyStroke2.Size = new System.Drawing.Size(100, 20);
            this.textBoxKeyStroke2.TabIndex = 7;
            this.textBoxKeyStroke2.Text = "Key Stroke";
            this.textBoxKeyStroke2.Visible = false;
            // 
            // textBoxLabel2
            // 
            this.textBoxLabel2.Location = new System.Drawing.Point(64, 82);
            this.textBoxLabel2.Name = "textBoxLabel2";
            this.textBoxLabel2.Size = new System.Drawing.Size(100, 20);
            this.textBoxLabel2.TabIndex = 6;
            this.textBoxLabel2.Text = "Label";
            this.textBoxLabel2.Visible = false;
            // 
            // labelOption2
            // 
            this.labelOption2.AutoSize = true;
            this.labelOption2.Location = new System.Drawing.Point(8, 85);
            this.labelOption2.Name = "labelOption2";
            this.labelOption2.Size = new System.Drawing.Size(50, 13);
            this.labelOption2.TabIndex = 5;
            this.labelOption2.Text = "Option 2:";
            this.labelOption2.Visible = false;
            // 
            // textBoxKeyStroke1
            // 
            this.textBoxKeyStroke1.Location = new System.Drawing.Point(170, 56);
            this.textBoxKeyStroke1.Name = "textBoxKeyStroke1";
            this.textBoxKeyStroke1.Size = new System.Drawing.Size(100, 20);
            this.textBoxKeyStroke1.TabIndex = 4;
            this.textBoxKeyStroke1.Text = "Key Stroke";
            this.textBoxKeyStroke1.Visible = false;
            // 
            // textBoxLabel1
            // 
            this.textBoxLabel1.Location = new System.Drawing.Point(64, 56);
            this.textBoxLabel1.Name = "textBoxLabel1";
            this.textBoxLabel1.Size = new System.Drawing.Size(100, 20);
            this.textBoxLabel1.TabIndex = 3;
            this.textBoxLabel1.Text = "Label";
            this.textBoxLabel1.Visible = false;
            // 
            // labelOption1
            // 
            this.labelOption1.AutoSize = true;
            this.labelOption1.Location = new System.Drawing.Point(8, 59);
            this.labelOption1.Name = "labelOption1";
            this.labelOption1.Size = new System.Drawing.Size(50, 13);
            this.labelOption1.TabIndex = 2;
            this.labelOption1.Text = "Option 1:";
            this.labelOption1.Visible = false;
            // 
            // LabelNumberOfInputs
            // 
            this.LabelNumberOfInputs.AutoSize = true;
            this.LabelNumberOfInputs.Location = new System.Drawing.Point(8, 18);
            this.LabelNumberOfInputs.Name = "LabelNumberOfInputs";
            this.LabelNumberOfInputs.Size = new System.Drawing.Size(90, 13);
            this.LabelNumberOfInputs.TabIndex = 1;
            this.LabelNumberOfInputs.Text = "Number Of Inputs";
            // 
            // domainUpDownInputs
            // 
            this.domainUpDownInputs.Items.Add("1");
            this.domainUpDownInputs.Items.Add("2");
            this.domainUpDownInputs.Items.Add("3");
            this.domainUpDownInputs.Items.Add("4");
            this.domainUpDownInputs.Location = new System.Drawing.Point(104, 16);
            this.domainUpDownInputs.Name = "domainUpDownInputs";
            this.domainUpDownInputs.Size = new System.Drawing.Size(56, 20);
            this.domainUpDownInputs.TabIndex = 0;
            this.domainUpDownInputs.SelectedItemChanged += new System.EventHandler(this.domainUpDown1_SelectedItemChanged);
            // 
            // VideoList
            // 
            this.VideoList.Controls.Add(this.listView1);
            this.VideoList.Location = new System.Drawing.Point(4, 22);
            this.VideoList.Name = "VideoList";
            this.VideoList.Padding = new System.Windows.Forms.Padding(3);
            this.VideoList.Size = new System.Drawing.Size(616, 245);
            this.VideoList.TabIndex = 1;
            this.VideoList.Text = "Video List";
            this.VideoList.UseVisualStyleBackColor = true;
            // 
            // listView1
            // 
            this.listView1.AllowDrop = true;
            this.listView1.AutoArrange = false;
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.Label,
            this.Option,
            this.Location});
            this.listView1.ContextMenuStrip = this.contextMenuStrip1;
            this.listView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listView1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listView1.FullRowSelect = true;
            this.listView1.GridLines = true;
            this.listView1.HeaderStyle = System.Windows.Forms.ColumnHeaderStyle.Nonclickable;
            this.listView1.Location = new System.Drawing.Point(3, 3);
            this.listView1.MultiSelect = false;
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(610, 239);
            this.listView1.TabIndex = 0;
            this.listView1.UseCompatibleStateImageBehavior = false;
            this.listView1.View = System.Windows.Forms.View.Details;
            this.listView1.SelectedIndexChanged += new System.EventHandler(this.listView1_SelectedIndexChanged);
            this.listView1.DoubleClick += new System.EventHandler(this.listView1_DoubleClick);
            // 
            // Label
            // 
            this.Label.Text = "Label";
            this.Label.Width = 114;
            // 
            // Option
            // 
            this.Option.Text = "Option";
            this.Option.Width = 109;
            // 
            // Location
            // 
            this.Location.Text = "Location";
            this.Location.Width = 381;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.addToolStripMenuItem,
            this.removeToolStripMenuItem,
            this.toolStripSeparator1,
            this.moveUpToolStripMenuItem,
            this.moveDownToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(138, 98);
            // 
            // addToolStripMenuItem
            // 
            this.addToolStripMenuItem.Image = global::QTester.Properties.Resources.webdev_add;
            this.addToolStripMenuItem.Name = "addToolStripMenuItem";
            this.addToolStripMenuItem.Size = new System.Drawing.Size(137, 22);
            this.addToolStripMenuItem.Text = "Add";
            this.addToolStripMenuItem.Click += new System.EventHandler(this.addToolStripMenuItem_Click);
            // 
            // removeToolStripMenuItem
            // 
            this.removeToolStripMenuItem.Image = global::QTester.Properties.Resources.webdev_remove;
            this.removeToolStripMenuItem.Name = "removeToolStripMenuItem";
            this.removeToolStripMenuItem.Size = new System.Drawing.Size(137, 22);
            this.removeToolStripMenuItem.Text = "Remove";
            this.removeToolStripMenuItem.Click += new System.EventHandler(this.removeToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(134, 6);
            // 
            // moveUpToolStripMenuItem
            // 
            this.moveUpToolStripMenuItem.Image = global::QTester.Properties.Resources.webdev_arrow_up;
            this.moveUpToolStripMenuItem.Name = "moveUpToolStripMenuItem";
            this.moveUpToolStripMenuItem.Size = new System.Drawing.Size(137, 22);
            this.moveUpToolStripMenuItem.Text = "Move Up";
            this.moveUpToolStripMenuItem.Click += new System.EventHandler(this.moveUpToolStripMenuItem_Click);
            // 
            // moveDownToolStripMenuItem
            // 
            this.moveDownToolStripMenuItem.Image = global::QTester.Properties.Resources.webdev_arrow_down;
            this.moveDownToolStripMenuItem.Name = "moveDownToolStripMenuItem";
            this.moveDownToolStripMenuItem.Size = new System.Drawing.Size(137, 22);
            this.moveDownToolStripMenuItem.Text = "Move down";
            this.moveDownToolStripMenuItem.Click += new System.EventHandler(this.moveDownToolStripMenuItem_Click);
            // 
            // Preview
            // 
            this.Preview.Controls.Add(this.buttonVideoNext);
            this.Preview.Controls.Add(this.buttonPlayControl);
            this.Preview.Controls.Add(this.buttonVideoPrevious);
            this.Preview.Controls.Add(this.label2);
            this.Preview.Controls.Add(this.textBoxOutputPreview);
            this.Preview.Controls.Add(this.panel1);
            this.Preview.Location = new System.Drawing.Point(4, 22);
            this.Preview.Name = "Preview";
            this.Preview.Padding = new System.Windows.Forms.Padding(3);
            this.Preview.Size = new System.Drawing.Size(616, 245);
            this.Preview.TabIndex = 4;
            this.Preview.Text = "Preview";
            this.Preview.UseVisualStyleBackColor = true;
            // 
            // buttonVideoNext
            // 
            this.buttonVideoNext.Location = new System.Drawing.Point(158, 200);
            this.buttonVideoNext.Name = "buttonVideoNext";
            this.buttonVideoNext.Size = new System.Drawing.Size(69, 22);
            this.buttonVideoNext.TabIndex = 14;
            this.buttonVideoNext.Text = "Next";
            this.buttonVideoNext.UseVisualStyleBackColor = true;
            // 
            // buttonPlayControl
            // 
            this.buttonPlayControl.Location = new System.Drawing.Point(83, 200);
            this.buttonPlayControl.Name = "buttonPlayControl";
            this.buttonPlayControl.Size = new System.Drawing.Size(69, 22);
            this.buttonPlayControl.TabIndex = 13;
            this.buttonPlayControl.Text = "Pause";
            this.buttonPlayControl.UseVisualStyleBackColor = true;
            // 
            // buttonVideoPrevious
            // 
            this.buttonVideoPrevious.Location = new System.Drawing.Point(8, 200);
            this.buttonVideoPrevious.Name = "buttonVideoPrevious";
            this.buttonVideoPrevious.Size = new System.Drawing.Size(69, 22);
            this.buttonVideoPrevious.TabIndex = 12;
            this.buttonVideoPrevious.Text = "Previous";
            this.buttonVideoPrevious.UseVisualStyleBackColor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(253, 6);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(39, 13);
            this.label2.TabIndex = 11;
            this.label2.Text = "Output";
            // 
            // textBoxOutputPreview
            // 
            this.textBoxOutputPreview.BackColor = System.Drawing.SystemColors.InactiveCaptionText;
            this.textBoxOutputPreview.Dock = System.Windows.Forms.DockStyle.Right;
            this.textBoxOutputPreview.Location = new System.Drawing.Point(298, 3);
            this.textBoxOutputPreview.Multiline = true;
            this.textBoxOutputPreview.Name = "textBoxOutputPreview";
            this.textBoxOutputPreview.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxOutputPreview.Size = new System.Drawing.Size(315, 239);
            this.textBoxOutputPreview.TabIndex = 10;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.Black;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Location = new System.Drawing.Point(8, 6);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(218, 188);
            this.panel1.TabIndex = 4;
            // 
            // Export
            // 
            this.Export.Controls.Add(this.label1);
            this.Export.Controls.Add(this.buttonTest);
            this.Export.Controls.Add(this.textBoxOutput);
            this.Export.Controls.Add(this.labelOutput);
            this.Export.Controls.Add(this.progressBar1);
            this.Export.Controls.Add(this.buttonExport);
            this.Export.Controls.Add(this.labelExportDirectory);
            this.Export.Controls.Add(this.textBoxExportPlaylistPathName);
            this.Export.Location = new System.Drawing.Point(4, 22);
            this.Export.Name = "Export";
            this.Export.Padding = new System.Windows.Forms.Padding(3);
            this.Export.Size = new System.Drawing.Size(616, 245);
            this.Export.TabIndex = 3;
            this.Export.Text = "Export";
            this.Export.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(5, 198);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(37, 13);
            this.label1.TabIndex = 11;
            this.label1.Text = "Status";
            // 
            // buttonTest
            // 
            this.buttonTest.Location = new System.Drawing.Point(168, 217);
            this.buttonTest.Name = "buttonTest";
            this.buttonTest.Size = new System.Drawing.Size(69, 22);
            this.buttonTest.TabIndex = 10;
            this.buttonTest.Text = "Test";
            this.buttonTest.UseVisualStyleBackColor = true;
            this.buttonTest.Click += new System.EventHandler(this.buttonTest_Click);
            // 
            // textBoxOutput
            // 
            this.textBoxOutput.BackColor = System.Drawing.SystemColors.InactiveCaptionText;
            this.textBoxOutput.Location = new System.Drawing.Point(50, 32);
            this.textBoxOutput.Multiline = true;
            this.textBoxOutput.Name = "textBoxOutput";
            this.textBoxOutput.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxOutput.Size = new System.Drawing.Size(557, 160);
            this.textBoxOutput.TabIndex = 9;
            // 
            // labelOutput
            // 
            this.labelOutput.AutoSize = true;
            this.labelOutput.Location = new System.Drawing.Point(5, 35);
            this.labelOutput.Name = "labelOutput";
            this.labelOutput.Size = new System.Drawing.Size(39, 13);
            this.labelOutput.TabIndex = 8;
            this.labelOutput.Text = "Output";
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(50, 198);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(556, 13);
            this.progressBar1.TabIndex = 7;
            // 
            // buttonExport
            // 
            this.buttonExport.Location = new System.Drawing.Point(93, 217);
            this.buttonExport.Name = "buttonExport";
            this.buttonExport.Size = new System.Drawing.Size(69, 22);
            this.buttonExport.TabIndex = 6;
            this.buttonExport.Text = "Export";
            this.buttonExport.UseVisualStyleBackColor = true;
            this.buttonExport.Click += new System.EventHandler(this.buttonExport_Click);
            // 
            // labelExportDirectory
            // 
            this.labelExportDirectory.AutoSize = true;
            this.labelExportDirectory.Location = new System.Drawing.Point(5, 9);
            this.labelExportDirectory.Name = "labelExportDirectory";
            this.labelExportDirectory.Size = new System.Drawing.Size(39, 13);
            this.labelExportDirectory.TabIndex = 3;
            this.labelExportDirectory.Text = "Playlist";
            // 
            // textBoxExportPlaylistPathName
            // 
            this.textBoxExportPlaylistPathName.Location = new System.Drawing.Point(50, 6);
            this.textBoxExportPlaylistPathName.Name = "textBoxExportPlaylistPathName";
            this.textBoxExportPlaylistPathName.Size = new System.Drawing.Size(556, 20);
            this.textBoxExportPlaylistPathName.TabIndex = 2;
            this.textBoxExportPlaylistPathName.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.textBoxtextBoxExportPlaylistPathName_MouseDoubleClick);
            // 
            // backgroundWorkerExport
            // 
            this.backgroundWorkerExport.WorkerReportsProgress = true;
            this.backgroundWorkerExport.WorkerSupportsCancellation = true;
            // 
            // AdminForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(624, 271);
            this.Controls.Add(this.adminTabControl);
            this.Name = "AdminForm";
            this.Text = "AdminForm";
            this.adminTabControl.ResumeLayout(false);
            this.Configuration.ResumeLayout(false);
            this.Configuration.PerformLayout();
            this.Command.ResumeLayout(false);
            this.Command.PerformLayout();
            this.VideoList.ResumeLayout(false);
            this.contextMenuStrip1.ResumeLayout(false);
            this.Preview.ResumeLayout(false);
            this.Preview.PerformLayout();
            this.Export.ResumeLayout(false);
            this.Export.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl adminTabControl;
        private System.Windows.Forms.TabPage Command;
        private System.Windows.Forms.TabPage VideoList;
        private System.Windows.Forms.Label LabelNumberOfInputs;
        private System.Windows.Forms.DomainUpDown domainUpDownInputs;
        private System.Windows.Forms.TextBox textBoxKeyStroke4;
        private System.Windows.Forms.TextBox textBoxLabel4;
        private System.Windows.Forms.Label labelOption4;
        private System.Windows.Forms.TextBox textBoxKeyStroke3;
        private System.Windows.Forms.TextBox textBoxLabel3;
        private System.Windows.Forms.Label labelOption3;
        private System.Windows.Forms.TextBox textBoxKeyStroke2;
        private System.Windows.Forms.TextBox textBoxLabel2;
        private System.Windows.Forms.Label labelOption2;
        private System.Windows.Forms.TextBox textBoxKeyStroke1;
        private System.Windows.Forms.TextBox textBoxLabel1;
        private System.Windows.Forms.Label labelOption1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem addToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem removeToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem moveUpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem moveDownToolStripMenuItem;        
        private System.Windows.Forms.ColumnHeader Label;
        private System.Windows.Forms.ColumnHeader Option;
        private System.Windows.Forms.ColumnHeader Location;
        private QTester.Display.Common.EditableListBox listView1;
        private System.Windows.Forms.TabPage Configuration;
        private System.Windows.Forms.DateTimePicker dateTimePickerCreated;
        private System.Windows.Forms.Label labelDateCreated;
        private System.Windows.Forms.Label labelAuthor;
        private System.Windows.Forms.TextBox textBoxAuthorName;
        private System.Windows.Forms.Label labelPlayListName;
        private System.Windows.Forms.TextBox textBoxPlayListName;
        private System.Windows.Forms.Label labelNotes;
        private System.Windows.Forms.TextBox textBoxNotes;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.Label labelDateLastUpdated;
        private System.Windows.Forms.Label labelSavedAs;
        private System.Windows.Forms.TextBox textBoxSavedAs;
        private System.Windows.Forms.Label labelPassword;
        private System.Windows.Forms.TextBox textBoxPassword;
        private System.Windows.Forms.TabPage Preview;
        private System.Windows.Forms.TabPage Export;
        private System.Windows.Forms.Button buttonExport;
        private System.Windows.Forms.Label labelExportDirectory;
        private System.Windows.Forms.TextBox textBoxExportPlaylistPathName;
        private System.ComponentModel.BackgroundWorker backgroundWorkerExport;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.TextBox textBoxOutput;
        private System.Windows.Forms.Label labelOutput;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonTest;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxOutputPreview;
        private System.Windows.Forms.Button buttonVideoNext;
        private System.Windows.Forms.Button buttonPlayControl;
        private System.Windows.Forms.Button buttonVideoPrevious;
    }
}