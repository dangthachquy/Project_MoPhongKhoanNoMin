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

using WindowsForms_MoPhongKhoanNoMin.BusinessLayer;
using WindowsForms_MoPhongKhoanNoMin.CustomControls;

namespace WindowsForms_MoPhongKhoanNoMin.GUILayer
{
    public partial class FormLoKhoan : DevExpress.XtraEditors.XtraForm
    {
        private String idHoChieu, idLoKhoan;
        List<Label> textLabel = new List<Label>();
        List<Label> valueLabel = new List<Label>();
        List<TextBox> valueTextBox = new List<TextBox>();
        List<System.Windows.Forms.ComboBox> valueComboBox = new List<System.Windows.Forms.ComboBox>();
        List<Button> buttonGroup = new List<Button>();

        UserControl_LoKhoan hienLoKhoan = new UserControl_LoKhoan();

        public FormLoKhoan()
        {
            InitializeComponent();
        }

        public FormLoKhoan(String _idHoChieu, String _idLoKhoan)
        {
            InitializeComponent();
            //add text control
            textLabel.Add(labelTitle1);
            textLabel.Add(labelTitle2);
            textLabel.Add(label_MaBanVe);
            textLabel.Add(label_MaLK);
            textLabel.Add(label_MaHoChieu);
            textLabel.Add(label_MaMayKhoan);
            textLabel.Add(label_DuongKinh);
            textLabel.Add(label_ChieuSauLK);
            textLabel.Add(label_HuongKhoan);
            textLabel.Add(label_ToaDoX);
            textLabel.Add(label_ToaDoY);
            //add value control
            valueLabel.Add(labelValue_MaBanVe);
            valueLabel.Add(labelValue_MaLK);
            valueLabel.Add(labelValue_MaHoChieu);
            valueLabel.Add(labelValue_MaMayKhoan);
            valueLabel.Add(labelValue_DuongKinh);
            valueLabel.Add(labelValue_ChieuSauLK);
            valueLabel.Add(labelValue_HuongKhoan);
            valueLabel.Add(labelValue_ToaDoX);
            valueLabel.Add(labelValue_ToaDoY);
            valueTextBox.Add(textBox_DuongKinh);
            valueTextBox.Add(textBox_ChieuSauLK);
            valueTextBox.Add(textBox_ToaDoX);
            valueTextBox.Add(textBox_ToaDoY);
            valueTextBox.Add(textBox1);
            valueTextBox.Add(textBox2);
            valueTextBox.Add(textBox3);
            valueTextBox.Add(textBox4);
            //add combobox control
            valueComboBox.Add(comboBox_MayKhoan);
            valueComboBox.Add(comboBox_HuongKhoan);
            //add button control
            buttonGroup.Add(buttonBack);
            buttonGroup.Add(buttonEdit);
            buttonGroup.Add(buttonUpdate);
            idHoChieu = _idHoChieu;
            idLoKhoan = _idLoKhoan;            
            foreach (TextBox tx in valueTextBox)
            {
                tx.KeyPress += textBoxInput_KeyPress;
                tx.TextChanged += textBox_TextChanged;
            }
            comboBox_MaLK.DataSource = BS_LoKhoan.DanhSachLoKhoan(idHoChieu);
            comboBox_MaLK.DisplayMember = "MaLoKhoan";
            comboBox_MaLK.Text = (BS_LoKhoan.ThongTinLoKhoan(idHoChieu, idLoKhoan)).MaLoKhoan;
            //UI
            this.BackColor = Properties.Settings.Default.FormBackgroundColor;
            this.MinimizeBox = false;
            this.MaximizeBox = false;
            label1.BackColor = ColorTranslator.FromHtml("#58D13D");
            label2.BackColor = ColorTranslator.FromHtml("#3DD1A2");
            label3.BackColor = ColorTranslator.FromHtml("#3DBDD1");
            label4.BackColor = ColorTranslator.FromHtml("#3D65D1");
            foreach (Button b in buttonGroup)
            {
                b.BackColor = Properties.Settings.Default.ButtonColor;
                b.FlatAppearance.BorderSize = 0;
            }
            foreach (Label l in textLabel)
            {
                l.ForeColor = Properties.Settings.Default.TextColor;
            }           
        }

        private void FormLoKhoan_Load(object sender, EventArgs e)
        {
            if (idHoChieu == null)
            {
                MessageBox.Show("Thông tin hộ chiếu chưa được lưu trong CSDL");
                this.Close();
                return;
            }
            if(BS_LoKhoan.ThongTinLoKhoan(idHoChieu, idLoKhoan).MaLoKhoan == null)
            {
                MessageBox.Show("Thông tin lỗ khoan chưa được lưu trong CSDL");
                this.Close();
                return;
            }
            ChangeView(false);
        }

        private void FormLoKhoan_Shown(object sender, EventArgs e)
        {
            RefreshData(idLoKhoan);
        }

        private void buttonEdit_Click(object sender, EventArgs e)
        {
            ChangeView(true);
        }

        private void buttonBack_Click(object sender, EventArgs e)
        {
            ChangeView(false);
            RefreshData(idLoKhoan);
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            LoKhoan loKhoan = BS_LoKhoan.ThongTinLoKhoan(idHoChieu, (comboBox_MaLK.SelectedItem as LoKhoan).MaLoKhoan);
            if(comboBox_MayKhoan.SelectedItem != null)
            {
                loKhoan.MaMayKhoan = (comboBox_MayKhoan.SelectedItem as MayKhoan).MaMayKhoan;
            }
            loKhoan.BanKinh = double.Parse(textBox_DuongKinh.Text) / 2;
            loKhoan.ChieuSau = double.Parse(textBox_ChieuSauLK.Text);
            loKhoan.HuongKhoan = comboBox_HuongKhoan.Text;
            loKhoan.ToaDoX = double.Parse(textBox_ToaDoX.Text);
            loKhoan.ToaDoY = double.Parse(textBox_ToaDoY.Text);
            loKhoan.Lt = double.Parse(textBox1.Text);
            loKhoan.Lkk = double.Parse(textBox2.Text);
            loKhoan.L0 = double.Parse(textBox3.Text);
            loKhoan.Lbua = double.Parse(textBox4.Text);
            BS_LoKhoan.CapNhatLoKhoan(loKhoan);
            ChangeView(false);
            RefreshData((comboBox_MaLK.SelectedItem as LoKhoan).MaLoKhoan);
        }

        private void ChangeView(bool b)
        {
            buttonEdit.Visible = !b;
            buttonBack.Visible = b;            
            buttonUpdate.Visible = b;
            foreach(System.Windows.Forms.ComboBox value in valueComboBox)
            {
                value.Visible = b;
            }
            foreach (TextBox t in valueTextBox)
            {
                t.Visible = b;
            }
        }

        private void RefreshData(String _idLoKhoan)
        {
            LoKhoan loKhoan = BS_LoKhoan.ThongTinLoKhoan(idHoChieu, _idLoKhoan);
            //hiển thị thông tin
            labelValue_MaHoChieu.Text = BS_HoChieu.HoChieu(loKhoan.MaHoChieu).TenHoChieu;
            labelValue_MaBanVe.Text = loKhoan.MaBanVe;
            labelValue_MaMayKhoan.Text = BS_MayKhoan.MayKhoan(loKhoan.MaMayKhoan).TenMayKhoan;
            labelValue_MaLK.Text = loKhoan.MaLoKhoan;
            comboBox_MayKhoan.DataSource = BS_MayKhoan.DanhSachMayKhoan();
            comboBox_MayKhoan.DisplayMember = "TenMayKhoan";
            comboBox_MayKhoan.Text = BS_MayKhoan.MayKhoan(loKhoan.MaMayKhoan).TenMayKhoan;
            //hiển thị thông số
            labelValue_DuongKinh.Text = (Math.Round(loKhoan.BanKinh * 2, 2)).ToString();
            textBox_DuongKinh.Text = (Math.Round(loKhoan.BanKinh * 2, 2)).ToString();
            labelValue_ChieuSauLK.Text = (Math.Round(loKhoan.ChieuSau, 2)).ToString();
            textBox_ChieuSauLK.Text = (Math.Round(loKhoan.ChieuSau, 2)).ToString();
            labelValue_HuongKhoan.Text = comboBox_HuongKhoan.Text = loKhoan.HuongKhoan;
            labelValue_ToaDoX.Text = textBox_ToaDoX.Text = (Math.Round(loKhoan.ToaDoX, 2)).ToString();
            labelValue_ToaDoY.Text = textBox_ToaDoY.Text = (Math.Round(loKhoan.ToaDoY, 2)).ToString();
            labelValue_Lt.Text = textBox1.Text = loKhoan.Lt.ToString();
            labelValue_Lkk.Text = textBox2.Text = loKhoan.Lkk.ToString();
            labelValue_L0.Text = textBox3.Text = loKhoan.L0.ToString();
            labelValue_Lbua.Text = textBox4.Text = loKhoan.Lbua.ToString();    
        }

        private void comboBox_MaLK_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(comboBox_MaLK.SelectedItem == null)
            {
                return;
            }
            else
            {
                RefreshData((comboBox_MaLK.SelectedItem as LoKhoan).MaLoKhoan);
            }            
        }

        /// <summary>
        /// Hàm kiểm tra sự kiện nhập phím có phải phím số không
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void textBoxInput_KeyPress(object sender, KeyPressEventArgs e)
        {
            const char Delete = (char)8;
            e.Handled = !Char.IsDigit(e.KeyChar) && e.KeyChar != Delete;
        }

        private void textBox_TextChanged(object sender, EventArgs e)
        {
            TextBox tx = sender as TextBox;
            if (tx.Text == String.Empty)
            {
                tx.Text = "0";
            }
            //còn đường kính và chiều sâu
            //if (int.Parse(tx.Text) > 100)
            //{
            //    tx.Text = "100";
            //}
            if (int.Parse(textBox_ChieuSauLK.Text) != 0)
            {
                int lt = (int)(double.Parse(textBox1.Text) / double.Parse(textBox_ChieuSauLK.Text) * 100);
                int lkk = (int)(double.Parse(textBox2.Text) / double.Parse(textBox_ChieuSauLK.Text) * 100);
                int l0 = (int)(double.Parse(textBox3.Text) / double.Parse(textBox_ChieuSauLK.Text) * 100);
                int lbua = (int)(double.Parse(textBox4.Text) / double.Parse(textBox_ChieuSauLK.Text) * 100);
                MoPhongLoKhoan(lt, lkk, l0, lbua);
            }
        }

        private void MoPhongLoKhoan(int l1, int l2, int l3, int l4)
        {
            hienLoKhoan.CaoDo1 = l1 * 3;
            hienLoKhoan.CaoDo2 = l2 * 3;
            hienLoKhoan.CaoDo3 = l3 * 3;
            hienLoKhoan.CaoDo4 = l4 * 3;
            hienLoKhoan.CaoDoText1 = (l1 == 0) ? 0 : l1 * 3 + 20;
            hienLoKhoan.CaoDoText2 = (l2 == 0) ? 0 : l1 * 3 + l2 * 3 + 20;
            hienLoKhoan.CaoDoText3 = (l3 == 0) ? 0 : l1 * 3 + l2 * 3 + l3 * 3 + 20;
            hienLoKhoan.CaoDoText4 = (l4 == 0) ? 0 : l1 * 3 + l2 * 3 + l3 * 3 + l4 * 3 + 20;
            elementHost_LoKhoan.Child = hienLoKhoan;
            hienLoKhoan.HienLoKhoan();
        }
    }
}