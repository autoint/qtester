using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace QTester.Display.Common
{
    public partial class EditableListBox : ListView
    {

        private ListViewItem li;
		private int X=0;
		private int Y=0;
		private string subItemText ;
		private int subItemSelected = 0 ; 
		private System.Windows.Forms.TextBox  editBox = new System.Windows.Forms.TextBox();
		private System.Windows.Forms.ComboBox cmbBox = new System.Windows.Forms.ComboBox();
        private System.Windows.Forms.OpenFileDialog openFileDialogVideo;

        public EditableListBox()
        {
            cmbBox.Size = new System.Drawing.Size(0, 0);
            cmbBox.Location = new System.Drawing.Point(0, 0);
            this.Controls.AddRange(new System.Windows.Forms.Control[] { this.cmbBox });
            cmbBox.SelectedIndexChanged += new System.EventHandler(this.CmbSelected);
            cmbBox.LostFocus += new System.EventHandler(this.CmbFocusOver);
            cmbBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.CmbKeyPress);
            cmbBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
            cmbBox.BackColor = Color.LightYellow;
            cmbBox.DropDownStyle = ComboBoxStyle.DropDownList;
            cmbBox.Hide();

            this.Dock = System.Windows.Forms.DockStyle.Fill;
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
            this.FullRowSelect = true;
            this.Name = "listView1";
            this.Size = new System.Drawing.Size(0, 0);
            this.TabIndex = 0;
            this.View = System.Windows.Forms.View.Details;
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.SMKMouseDown);
            this.GridLines = true;


            editBox.Size = new System.Drawing.Size(0, 0);
            editBox.Location = new System.Drawing.Point(0, 0);
            this.Controls.AddRange(new System.Windows.Forms.Control[] { this.editBox });
            editBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.EditOver);
            editBox.LostFocus += new System.EventHandler(this.FocusOver);
            editBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((System.Byte)(0)));
            editBox.BackColor = Color.LightYellow;
            editBox.BorderStyle = BorderStyle.Fixed3D;
            editBox.Hide();
            editBox.Text = "";

            // 
            // openFileDialogVideo
            // 
            this.openFileDialogVideo = new System.Windows.Forms.OpenFileDialog();           
            this.openFileDialogVideo.FileName = "*.*";
        }

        private void CmbKeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            if (e.KeyChar == 13 || e.KeyChar == 27)
            {
                cmbBox.Hide();
            }
        }

        private void CmbSelected(object sender, System.EventArgs e)
        {
            int sel = cmbBox.SelectedIndex;
            if (sel >= 0)
            {
                string itemSel = cmbBox.Items[sel].ToString();
                li.SubItems[subItemSelected].Text = itemSel;
            }
        }

        private void CmbFocusOver(object sender, System.EventArgs e)
        {
            cmbBox.Hide();
        }

        private void EditOver(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            if (e.KeyChar == 13)
            {
                li.SubItems[subItemSelected].Text = editBox.Text;
                editBox.Hide();
            }

            if (e.KeyChar == 27)
                editBox.Hide();
        }

        private void FocusOver(object sender, System.EventArgs e)
        {
            li.SubItems[subItemSelected].Text = editBox.Text;
            editBox.Hide();
        }

        public void SMKUpdateCombo(string[] newList)
        {
            cmbBox.Items.Clear();
            foreach (string elment in newList)
            {
                cmbBox.Items.Add(elment);
            }                        
        }

        /*private int IdentifySubItemSelected*/

        public void SMKDoubleClick(object sender, System.EventArgs e)
        {         
            // Check the subitem clicked .
            int nStart = X;
            int spos = 0;
            int epos = this.Columns[0].Width;            
            for (int i = 0; i < this.Columns.Count; i++)            
            {
                if (nStart > spos && nStart < epos)
                {
                    subItemSelected = i;
                    break;
                }

                spos = epos;
                epos += this.Columns[i].Width;
            }
            epos = spos + this.Columns[subItemSelected].Width;

            Console.WriteLine("SUB ITEM SELECTED = " + li.SubItems[subItemSelected].Text);
            subItemText = li.SubItems[subItemSelected].Text;

            string colName = this.Columns[subItemSelected].Text;
            if (colName == "Option")
            {
                Rectangle r = new Rectangle(spos, li.Bounds.Y, epos, li.Bounds.Bottom);
                cmbBox.Size = new System.Drawing.Size(epos - spos, li.Bounds.Bottom - li.Bounds.Top);
                cmbBox.Location = new System.Drawing.Point(spos, li.Bounds.Y);
                cmbBox.Show();
                cmbBox.Text = subItemText;
                cmbBox.SelectAll();
                cmbBox.Focus();
            }
            else if (colName == "Location")
            {
                openFileDialogVideo.FileName = subItemText;
                if (openFileDialogVideo.ShowDialog() == DialogResult.OK)
                {
                    li.SubItems[subItemSelected].Text = openFileDialogVideo.FileName;
                }
            }
            else
            {
                Rectangle r = new Rectangle(spos, li.Bounds.Y, epos, li.Bounds.Bottom);
                editBox.Size = new System.Drawing.Size(epos - spos, li.Bounds.Bottom - li.Bounds.Top);
                editBox.Location = new System.Drawing.Point(spos, li.Bounds.Y);
                editBox.Show();
                editBox.Text = subItemText;
                editBox.SelectAll();
                editBox.Focus();
            }
        }

        public ListViewItem GetListviewItemSelected()
        {
            return li;
        }

        public void SMKMouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            li = this.GetItemAt(e.X, e.Y);
            X = e.X;
            Y = e.Y;
        }

        protected override void OnPaint(PaintEventArgs pe)
        {
            base.OnPaint(pe);
        }
    }
}
