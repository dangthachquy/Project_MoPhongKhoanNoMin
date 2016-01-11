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
    public partial class FormLoKhoanHoChieu : DevExpress.XtraEditors.XtraForm
    {
        private String idHoChieu;
        List<Label> textLabel = new List<Label>();
        List<TextBox> valueTextBox = new List<TextBox>();
        List<TextBox> valueTextBox2 = new List<TextBox>();
        List<System.Windows.Forms.ComboBox> valueComboBox = new List<System.Windows.Forms.ComboBox>();
        List<Button> buttonGroup = new List<Button>();

        UserControl_LoKhoan hienLoKhoan = new UserControl_LoKhoan();

        // khai báo 1 hàm delegate
        public delegate void GetData(bool flag);
        // khai báo 1 kiểu hàm delegate
        public GetData MyGetData;

        public FormLoKhoanHoChieu()
        {
            InitializeComponent();
        }

        public FormLoKhoanHoChieu(String _idHoChieu)
        {
            InitializeComponent();
            //add text control
            textLabel.Add(labelTitle1);
            textLabel.Add(labelTitle2);
            textLabel.Add(label_MaHoChieu);
            textLabel.Add(label_MaMayKhoan);
            textLabel.Add(label_DuongKinh);
            textLabel.Add(label_ChieuSauLK);
            textLabel.Add(label_HuongKhoan);
            //add combobox control
            valueComboBox.Add(comboBox_MayKhoan);
            valueComboBox.Add(comboBox_HuongKhoan);
            //add button control
            buttonGroup.Add(buttonUpdate);
            //add textbox control
            valueTextBox.Add(textBox_ChieuSauLK);
            valueTextBox.Add(textBox_DuongKinh);
            valueTextBox.Add(textBox1);
            valueTextBox.Add(textBox2);
            valueTextBox.Add(textBox3);
            valueTextBox.Add(textBox4);
            valueTextBox2.Add(textBox_ChieuSauLK);
            valueTextBox2.Add(textBox1);
            valueTextBox2.Add(textBox2);
            valueTextBox2.Add(textBox3);
            valueTextBox2.Add(textBox4);
            idHoChieu = _idHoChieu;
            foreach (TextBox tx in valueTextBox)
            {
                tx.KeyPress += textBoxInput_KeyPress;               
            }
            foreach (TextBox tx in valueTextBox2)
            {
                tx.TextChanged += textBox_TextChanged;
            }          
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

        private void FormLoKhoanBanVe_Load(object sender, EventArgs e)
        {
            if (idHoChieu == null)
            {
                MessageBox.Show("Thông tin hộ chiếu chưa được lưu trong CSDL");
                this.Close();
                return;
            }
            RefreshData();
        }

        private void RefreshData()
        {
            labelValue_MaHoChieu.Text = BS_HoChieu.HoChieu(idHoChieu).TenHoChieu;
            comboBox_MayKhoan.DataSource = BS_MayKhoan.DanhSachMayKhoan();
            comboBox_MayKhoan.DisplayMember = "TenMayKhoan";
            comboBox_MayKhoan.SelectedItem = null;
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            List<LoKhoan> danhSachLoKhoan = BS_LoKhoan.DanhSachLoKhoan(idHoChieu);
            foreach (LoKhoan value in danhSachLoKhoan)
            {
                if(comboBox_MayKhoan.SelectedItem != null)
                {
                    value.MaMayKhoan = (comboBox_MayKhoan.SelectedItem as MayKhoan).MaMayKhoan;
                }
                if(textBox_DuongKinh.Text != String.Empty)
                {
                    value.BanKinh = double.Parse(textBox_DuongKinh.Text) / 2;
                }
                if(textBox_ChieuSauLK.Text != String.Empty)
                {
                    value.ChieuSau = double.Parse(textBox_ChieuSauLK.Text);
                }
                if(comboBox_HuongKhoan.Text != String.Empty)
                {
                    value.HuongKhoan = comboBox_HuongKhoan.Text;
                }
                if (textBox1.Text != String.Empty)
                {
                    value.Lt = double.Parse(textBox1.Text);
                }
                if (textBox2.Text != String.Empty)
                {
                    value.Lkk = double.Parse(textBox2.Text);
                }
                if (textBox3.Text != String.Empty)
                {
                    value.L0 = double.Parse(textBox3.Text);
                }
                if (textBox4.Text != String.Empty)
                {
                    value.Lbua = double.Parse(textBox4.Text);
                }
            }
            MyGetData(BS_LoKhoan.CapNhatLoKhoan(danhSachLoKhoan));
            this.Close();
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

        private void textBox_TextChanged(object sender, EventArgs e)
        {
            TextBox tx = sender as TextBox;
            if (tx.Text == String.Empty && tx.Name != "textBox_ChieuSauLK")
            {
                tx.Text = "0";
            }
            //còn đường kính và chiều sâu
            //if (int.Parse(tx.Text) > 100)
            //{
            //    tx.Text = "100";
            //}
            if (textBox_ChieuSauLK.Text != String.Empty)
            {
                if (int.Parse(textBox_ChieuSauLK.Text) != 0)
                {
                    int lt = (int)(double.Parse(textBox1.Text) / double.Parse(textBox_ChieuSauLK.Text) * 100);
                    int lkk = (int)(double.Parse(textBox2.Text) / double.Parse(textBox_ChieuSauLK.Text) * 100);
                    int l0 = (int)(double.Parse(textBox3.Text) / double.Parse(textBox_ChieuSauLK.Text) * 100);
                    int lbua = (int)(double.Parse(textBox4.Text) / double.Parse(textBox_ChieuSauLK.Text) * 100);
                    MoPhongLoKhoan(lt, lkk, l0, lbua);
                }
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