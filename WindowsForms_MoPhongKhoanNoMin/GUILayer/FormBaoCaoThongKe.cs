using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using DevExpress.XtraEditors;

using System.Diagnostics;
using System.Reflection;
using System.IO;
using System.Threading;
using Word = Microsoft.Office.Interop.Word;
using WindowsForms_MoPhongKhoanNoMin.BusinessLayer;
using WindowsForms_MoPhongKhoanNoMin.CustomControls;

namespace WindowsForms_MoPhongKhoanNoMin.GUILayer
{
    public partial class FormBaoCaoThongKe : DevExpress.XtraEditors.XtraForm
    {
        private String idHoChieu, fileName, userName = "";
        List<Label> textLabel = new List<Label>();
        List<Label> valueLabel = new List<Label>();
        List<System.Windows.Forms.ComboBox> valueComboBox = new List<System.Windows.Forms.ComboBox>();
        List<Button> buttonGroup = new List<Button>();

        public FormBaoCaoThongKe()
        {
            InitializeComponent();           
        }

        public FormBaoCaoThongKe(HoChieu _HoChieu)
        {
            InitializeComponent();
            //add text control
            textLabel.Add(labelText);
            textLabel.Add(labelText3);
            textLabel.Add(label_GiaTri1);
            textLabel.Add(label_GiaTri2);
            textLabel.Add(label_GiaTri3);
            textLabel.Add(label_GiaTri4);
            textLabel.Add(label_GiaTri5);
            textLabel.Add(label_GiaTri6);
            textLabel.Add(label_GiaTri7);
            //add value control
            valueLabel.Add(labelValue_GiaTri1);
            valueLabel.Add(labelValue_GiaTri2);
            valueLabel.Add(labelValue_GiaTri3);
            valueLabel.Add(labelValue_GiaTri4);
            valueLabel.Add(labelValue_GiaTri5);
            valueLabel.Add(labelValue_GiaTri6);
            valueLabel.Add(labelValue_GiaTri7);
            //add combobox control
            valueComboBox.Add(comboBox_MaHoChieu);
            //add button control
            buttonGroup.Add(buttonTaoMoi);
            //UI
            this.BackColor = Properties.Settings.Default.FormBackgroundColor;
            this.MinimizeBox = false;
            this.MaximizeBox = false;
            foreach (Button b in buttonGroup)
            {
                b.BackColor = Properties.Settings.Default.ButtonColor;
                b.FlatAppearance.BorderSize = 0;
            }
            foreach (Label l in textLabel)
            {
                l.ForeColor = Properties.Settings.Default.TextColor;
            }
            idHoChieu = _HoChieu.MaHoChieu;
            comboBox_MaHoChieu.DataSource = BS_HoChieu.DanhSachHoChieu();
            comboBox_MaHoChieu.DisplayMember = "TenHoChieu";
            comboBox_MaHoChieu.Text = _HoChieu.TenHoChieu;
        }

        private void FormBaoCaoThongKe_Shown(object sender, EventArgs e)
        {

        }

        private void comboBox_MaHoChieu_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(comboBox_MaHoChieu.SelectedItem != null)
            {
                ExportData Objdata = new ExportData((comboBox_MaHoChieu.SelectedItem as HoChieu).MaHoChieu);
                labelValue_GiaTri1.Text = Objdata.congTB.ToString();
                labelValue_GiaTri2.Text = Objdata.duongKhang.ToString() + " mét";
                labelValue_GiaTri3.Text = Objdata.KC_Cot.ToString() + " mét";
                labelValue_GiaTri4.Text = Objdata.KC_Hang.ToString() + " mét";
                labelValue_GiaTri5.Text = Objdata.chieuSauThem.ToString() + " mét";
                labelValue_GiaTri6.Text = Objdata.chieuSauToanBoLK.ToString() + " mét";
                labelValue_GiaTri7.Text = Objdata.chieuDaiBua.ToString() + " mét";
            }                   
        }

        private void buttonTaoMoi_Click(object sender, EventArgs e)
        {
            Thread t = new Thread(new ThreadStart(BS_Main.LoadingScreen));
            try
            {
                userName = textBoxNguoiLapHoChieu.Text; //tên người dùng
                SaveFileDialog saveFileDialog1 = new SaveFileDialog();
                if (saveFileDialog1.ShowDialog() == DialogResult.OK)
                {
                    t.Start();
                    fileName = saveFileDialog1.FileName;
                    idHoChieu += (comboBox_MaHoChieu.SelectedItem as HoChieu).MaHoChieu;
                    String fullPath = Path.GetFullPath(Path.Combine((@"" + Application.StartupPath), @"..\..\"));
                    CreateWordDocument(fullPath + "Template\\template.doc", saveFileDialog1.FileName);
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show("Lỗi: " + ex.Message);
            }
            finally
            {
                t.Abort();
            }
            /*SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                buttonTaoMoi.Enabled = false;
                buttonTaoMoi.Text = "ĐANG XỬ LÝ...";
                fileName = saveFileDialog1.FileName;
                idHoChieu += (comboBox_MaHoChieu.SelectedItem as HoChieu).MaHoChieu;
                backgroundWorker_Loading.RunWorkerAsync();
            }   */   
        }

        private void CreateWordDocument(object filename, object saves)
        {
            object missing = Missing.Value;

            Word.Application wordApp = null;
            Word.Document doc = null;
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();
            GC.WaitForPendingFinalizers();
            //word.Table table;
            if (File.Exists((string)filename))
            {
                DateTime today = DateTime.Now;
                object readOnly = false;
                object isvisible = false;                
                if(wordApp == null)
                {
                    wordApp = new Word.Application();
                }
                wordApp.Visible = false;
                /*doc = wordApp.Documents.Open(ref filename, ref missing, ref missing,
                                                ref missing, ref missing, ref missing,
                                                ref missing, ref missing, ref missing,
                                                ref missing, ref missing, ref missing,
                                                ref missing, ref missing, ref missing, ref missing);*/
                doc = wordApp.Documents.Open(ref filename);
                doc.ActiveWindow.Selection.WholeStory();
                //doc.Activate();
                ExportData Objdata = new ExportData(idHoChieu);
                //this.FindAndReplace(wordApp, "DonVi", txtDonviNo.Text.Trim());
                this.FindAndReplace(wordApp, "hour", (Objdata.thoiDiemNo.Hour.ToString() == String.Empty ? "" : Objdata.thoiDiemNo.Hour.ToString()) );
                this.FindAndReplace(wordApp, "minute", (Objdata.thoiDiemNo.Minute.ToString() == String.Empty ? "" : Objdata.thoiDiemNo.Minute.ToString()) );
                this.FindAndReplace(wordApp, "day", (Objdata.thoiDiemNo.Day.ToString() == String.Empty ? "" : Objdata.thoiDiemNo.Day.ToString()) );
                this.FindAndReplace(wordApp, "month", (Objdata.thoiDiemNo.Month.ToString() == String.Empty ? "" : Objdata.thoiDiemNo.Month.ToString()) );
                this.FindAndReplace(wordApp, "year", (Objdata.thoiDiemNo.Year.ToString() == String.Empty ? "" : Objdata.thoiDiemNo.Year.ToString()) );
                this.FindAndReplace(wordApp, "DiaDiemNo", (Objdata.congTruong.TenCongTruong == String.Empty ? "" : Objdata.congTruong.TenCongTruong) );
                this.FindAndReplace(wordApp, "TenDatDa", (Objdata.datDa.TenDatDa.ToString() == String.Empty ? "" : Objdata.datDa.TenDatDa.ToString()));
                Word.Range range = doc.Range(ref missing, ref missing);
                for (int i = 1; i < Objdata.danhSachLoKhoan.Count; i++)
                {
                    doc.Tables[2].Rows.Add();
                    doc.Tables[2].Rows[i + 1].Cells[1].Range.Text = Objdata.danhSachLoKhoan[i].ID.ToString();
                    doc.Tables[2].Rows[i + 1].Cells[3].Range.Text = (Objdata.danhSachLoKhoan[i].BanKinh * 2).ToString();
                    doc.Tables[2].Rows[i + 1].Cells[4].Range.Text = Objdata.chieuSauToanBoLK.ToString();
                    doc.Tables[2].Rows[i + 1].Cells[5].Range.Text = Objdata.KC_Cot.ToString();
                    doc.Tables[2].Rows[i + 1].Cells[6].Range.Text = Objdata.KC_Hang.ToString();
                    doc.Tables[2].Rows[i + 1].Cells[9].Range.Text = Objdata.chieuDaiBua.ToString();
                }
                Word.Range rangePic = doc.Tables[5].Range;
                String fullPath = Path.GetFullPath(Path.Combine((@"" + Application.StartupPath), @"..\..\"));
                rangePic.InlineShapes.AddPicture(fullPath + "Template\\ViewTemp.bmp", ref missing, ref missing, ref missing);
                // var shape = doc.Bookmarks["PicHere"].Range.InlineShapes.AddPicture(@"C:\2.jpg", false, true);
                // doc.InlineShapes.AddPicture(@""+Application.StartupPath +"\\Sodobaino.bmp", ref missing, ref missing, ranges);
                // shape.Width = 150;
                // shape.Height = 150;                 
            }
            else
            {
                MessageBox.Show("File not exits");
                return;
            }
            // saves filename
            doc.SaveAs2(ref saves, ref missing, ref missing, ref missing,
                        ref missing, ref missing, ref missing,
                        ref missing, ref missing, ref missing,
                        ref missing, ref missing, ref missing,
                        ref missing, ref missing, ref missing);
            MessageBox.Show("Create !!");
        }
        private void FindAndReplace(Word.Application app, object findText, object replaceWithText)
        {
            object missing = Missing.Value;
            Word.Find findObject = app.ActiveWindow.Selection.Find;
            findObject.ClearFormatting();
            findObject.Text = findText as String;
            findObject.Replacement.ClearFormatting();
            findObject.Replacement.Text = replaceWithText as String;

            object replaceAll = Word.WdReplace.wdReplaceAll;
            findObject.Execute(ref missing, ref missing, ref missing, ref missing, ref missing,
                ref missing, ref missing, ref missing, ref missing, ref missing,
                ref replaceAll, ref missing, ref missing, ref missing, ref missing);

            /*Word.Find fnd = app.ActiveWindow.Selection.Find;

            fnd.ClearFormatting();
            fnd.Replacement.ClearFormatting();
            fnd.Forward = true;
            fnd.Wrap = Word.WdFindWrap.wdFindContinue;

            fnd.Text = findText as String;
            fnd.Replacement.Text = replaceWithText as String;

            fnd.Execute(Replace: Word.WdReplace.wdReplaceAll);*/

            /*object matchCase = true;
            object matchWholeWord = true;
            object matchWillCards = false;
            object matchSoundLike = false;
            object nmatchAllForms = false;
            object forward = true;
            object format = false;
            object matchKashida = false;
            object matchDiactitics = false;
            object matchAleftHamza = false;
            object matchControl = false;
            object read_Only = false;
            object visible = false;
            object replace = 2;
            object wrap = 1;

            app.Selection.Find.Execute(ref findText, ref matchCase,
                                        ref matchWholeWord, ref matchWillCards,
                                        ref matchSoundLike, ref nmatchAllForms,
                                        ref forward, ref wrap, ref format,
                                        ref replaceWithText, ref replace, ref matchKashida,
                                        ref matchDiactitics, ref matchAleftHamza,
                                        ref matchControl);*/
        }

        private void backgroundWorker_Loading_DoWork(object sender, DoWorkEventArgs e)
        {
            String fullPath = Path.GetFullPath(Path.Combine((@"" + Application.StartupPath), @"..\..\"));
            CreateWordDocument(fullPath + "Template\\template.doc", fileName);
        }

        private void backgroundWorker_Loading_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled)
            {
                MessageBox.Show("cancel!");
                buttonTaoMoi.Enabled = true;
                buttonTaoMoi.Text = "XUẤT BÁO CÁO";
            }
            else
            {
                buttonTaoMoi.Enabled = true;
                buttonTaoMoi.Text = "XUẤT BÁO CÁO";
            }
        }
    }
}