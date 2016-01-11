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

namespace WindowsForms_MoPhongKhoanNoMin.GUILayer
{
    public partial class FormXayDungLoKhoan : DevExpress.XtraEditors.XtraForm
    {
        private int huongVe;
        List<RadioButton> radioButtonTemplate = new List<RadioButton>();
        List<TextBox> textBoxInput = new List<TextBox>();
        List<Label> textLabel = new List<Label>();

        // khai báo 1 hàm delegate
        public delegate void GetData(int soHang, int soCot, int khoangCachHang, int khoangCachCot, double banKinh, bool luoiKichThuoc);
        // khai báo 1 kiểu hàm delegate
        public GetData MyGetData;

        public FormXayDungLoKhoan()
        {
            InitializeComponent();
            //nhóm các controls
            radioButtonTemplate.Add(radioButtonTemp1);
            radioButtonTemplate.Add(radioButtonTemp2);
            radioButtonTemplate.Add(radioButtonTemp3);
            radioButtonTemplate.Add(radioButtonTemp4);
            textBoxInput.Add(textBoxSoHang);
            textBoxInput.Add(textBoxSoCot);
            textBoxInput.Add(textBoxKhoangCachHang);
            textBoxInput.Add(textBoxKhoangCachCot);
            textBoxInput.Add(textBoxBanKinh);
            textLabel.Add(label1);
            textLabel.Add(label2);
            textLabel.Add(label3);
            textLabel.Add(label4);
            textLabel.Add(label5);
            textLabel.Add(label6);
            textLabel.Add(label7);
            //UI
            this.BackColor = Properties.Settings.Default.FormBackgroundColor;
            buttonChonToaDo.FlatAppearance.BorderSize = 0;
            buttonChonToaDo.BackColor = Properties.Settings.Default.ButtonColor;
            foreach (TextBox tx in textBoxInput)
            {
                tx.KeyPress += textBoxInput_KeyPress;
            }
            foreach (RadioButton rb in radioButtonTemplate)
            {
                rb.FlatAppearance.BorderSize = 2;
                rb.CheckedChanged += new System.EventHandler(radioButtonTempGroups_CheckedChanged);
            }
            foreach (Label l in textLabel)
            {
                l.ForeColor = Properties.Settings.Default.TextColor;
            }
        }

        private void FormXayDungLoKhoan1_Load(object sender, EventArgs e)
        {
            radioButtonTemp1.Checked = true;
        }

        /// <summary>
        /// Hàm truyền dữ liệu về FormMain để vẽ lưới lỗ khoan
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void buttonChonToaDo_Click(object sender, EventArgs e)
        {
            int soHang, soCot, khoangCachHang, khoangCachCot;
            double banKinh;
            soHang = int.Parse(textBoxSoHang.Text);
            soCot = int.Parse(textBoxSoCot.Text);
            khoangCachHang = int.Parse(textBoxKhoangCachHang.Text);
            khoangCachCot = int.Parse(textBoxKhoangCachCot.Text);
            banKinh = Double.Parse(textBoxBanKinh.Text);
            if (soHang == 0 || soCot == 0 || khoangCachHang == 0 || khoangCachCot == 0 || banKinh == 0)
            {
                MessageBox.Show("Nhap sai nhe :D");
            }
            else
            {
                switch (huongVe)
                {
                    case 1:
                        khoangCachHang = khoangCachHang * -1;
                        //khoangCachCot khong doi
                        break;
                    case 2:
                        //khoangCachHang khong doi
                        //khoangCachCot khong doi
                        break;
                    case 3:
                        khoangCachHang = khoangCachHang * -1;
                        khoangCachCot = khoangCachCot * -1;
                        break;
                    case 4:
                        //khoangCachHang khong doi
                        khoangCachCot = khoangCachCot * -1;
                        break;
                }
                MyGetData(soHang, soCot, khoangCachHang, khoangCachCot, banKinh, checkBoxKichThuoc.Checked);
                this.Close();
            }
        }

        /// <summary>
        /// Hàm kiểm tra sự kiện nhập phím có phải phím số không
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void textBoxInput_KeyPress(object sender, KeyPressEventArgs e)
        {
            //const char Delete = (char)8;
            //e.Handled = !Char.IsDigit(e.KeyChar) && e.KeyChar != Delete;
        }

        private void radioButtonTempGroups_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = sender as RadioButton;
            if (rb.Checked)
            {
                rb.ForeColor = Properties.Settings.Default.PrimaryColor;
            }
            else
            {
                rb.ForeColor = Properties.Settings.Default.FormBackgroundColor;
            }
            switch (rb.Name)
            {
                case "radioButtonTemp1":
                    if (rb.Checked)
                    {
                        huongVe = 1;
                    }
                    break;
                case "radioButtonTemp2":
                    if (rb.Checked)
                    {
                        huongVe = 2;
                    }
                    break;
                case "radioButtonTemp3":
                    if (rb.Checked)
                    {
                        huongVe = 3;
                    }
                    break;
                case "radioButtonTemp4":
                    if (rb.Checked)
                    {
                        huongVe = 4;
                    }
                    break;                
            }
        }
    }
}