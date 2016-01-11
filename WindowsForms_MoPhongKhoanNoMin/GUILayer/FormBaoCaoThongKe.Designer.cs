namespace WindowsForms_MoPhongKhoanNoMin.GUILayer
{
    partial class FormBaoCaoThongKe
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
            this.buttonTaoMoi = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.labelText = new System.Windows.Forms.Label();
            this.comboBox_MaHoChieu = new System.Windows.Forms.ComboBox();
            this.labelText3 = new System.Windows.Forms.Label();
            this.label_GiaTri1 = new System.Windows.Forms.Label();
            this.label_GiaTri2 = new System.Windows.Forms.Label();
            this.label_GiaTri3 = new System.Windows.Forms.Label();
            this.label_GiaTri4 = new System.Windows.Forms.Label();
            this.label_GiaTri5 = new System.Windows.Forms.Label();
            this.labelValue_GiaTri1 = new System.Windows.Forms.Label();
            this.labelValue_GiaTri2 = new System.Windows.Forms.Label();
            this.labelValue_GiaTri3 = new System.Windows.Forms.Label();
            this.labelValue_GiaTri4 = new System.Windows.Forms.Label();
            this.labelValue_GiaTri5 = new System.Windows.Forms.Label();
            this.label_GiaTri6 = new System.Windows.Forms.Label();
            this.label_GiaTri7 = new System.Windows.Forms.Label();
            this.labelValue_GiaTri6 = new System.Windows.Forms.Label();
            this.labelValue_GiaTri7 = new System.Windows.Forms.Label();
            this.backgroundWorker_Loading = new System.ComponentModel.BackgroundWorker();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxNguoiLapHoChieu = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // buttonTaoMoi
            // 
            this.buttonTaoMoi.AutoSize = true;
            this.buttonTaoMoi.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.buttonTaoMoi.Cursor = System.Windows.Forms.Cursors.Hand;
            this.buttonTaoMoi.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonTaoMoi.Font = new System.Drawing.Font("Segoe UI Semibold", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonTaoMoi.ForeColor = System.Drawing.Color.White;
            this.buttonTaoMoi.Location = new System.Drawing.Point(65, 320);
            this.buttonTaoMoi.Name = "buttonTaoMoi";
            this.buttonTaoMoi.Size = new System.Drawing.Size(115, 33);
            this.buttonTaoMoi.TabIndex = 39;
            this.buttonTaoMoi.Text = "XUẤT BÁO CÁO";
            this.buttonTaoMoi.UseVisualStyleBackColor = false;
            this.buttonTaoMoi.Click += new System.EventHandler(this.buttonTaoMoi_Click);
            // 
            // label1
            // 
            this.label1.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label1.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label1.Location = new System.Drawing.Point(249, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(2, 380);
            this.label1.TabIndex = 40;
            // 
            // labelText
            // 
            this.labelText.AutoSize = true;
            this.labelText.BackColor = System.Drawing.Color.Transparent;
            this.labelText.Font = new System.Drawing.Font("Segoe UI Semibold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelText.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.labelText.Location = new System.Drawing.Point(30, 40);
            this.labelText.Name = "labelText";
            this.labelText.Padding = new System.Windows.Forms.Padding(3);
            this.labelText.Size = new System.Drawing.Size(81, 27);
            this.labelText.TabIndex = 61;
            this.labelText.Text = "Hộ chiếu";
            // 
            // comboBox_MaHoChieu
            // 
            this.comboBox_MaHoChieu.FormattingEnabled = true;
            this.comboBox_MaHoChieu.Items.AddRange(new object[] {
            "Trên",
            "Dưới",
            "Phải",
            "Trái"});
            this.comboBox_MaHoChieu.Location = new System.Drawing.Point(25, 80);
            this.comboBox_MaHoChieu.Name = "comboBox_MaHoChieu";
            this.comboBox_MaHoChieu.Size = new System.Drawing.Size(200, 21);
            this.comboBox_MaHoChieu.TabIndex = 91;
            this.comboBox_MaHoChieu.SelectedIndexChanged += new System.EventHandler(this.comboBox_MaHoChieu_SelectedIndexChanged);
            // 
            // labelText3
            // 
            this.labelText3.AutoSize = true;
            this.labelText3.BackColor = System.Drawing.Color.Transparent;
            this.labelText3.Font = new System.Drawing.Font("Segoe UI Semibold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelText3.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.labelText3.Location = new System.Drawing.Point(280, 40);
            this.labelText3.Name = "labelText3";
            this.labelText3.Padding = new System.Windows.Forms.Padding(3);
            this.labelText3.Size = new System.Drawing.Size(153, 27);
            this.labelText3.TabIndex = 93;
            this.labelText3.Text = "Tính toán thông số";
            // 
            // label_GiaTri1
            // 
            this.label_GiaTri1.AutoSize = true;
            this.label_GiaTri1.BackColor = System.Drawing.Color.Transparent;
            this.label_GiaTri1.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_GiaTri1.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label_GiaTri1.Location = new System.Drawing.Point(310, 80);
            this.label_GiaTri1.Name = "label_GiaTri1";
            this.label_GiaTri1.Padding = new System.Windows.Forms.Padding(3);
            this.label_GiaTri1.Size = new System.Drawing.Size(128, 23);
            this.label_GiaTri1.TabIndex = 94;
            this.label_GiaTri1.Text = "Công trung bình (e)";
            // 
            // label_GiaTri2
            // 
            this.label_GiaTri2.AutoSize = true;
            this.label_GiaTri2.BackColor = System.Drawing.Color.Transparent;
            this.label_GiaTri2.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_GiaTri2.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label_GiaTri2.Location = new System.Drawing.Point(310, 120);
            this.label_GiaTri2.Name = "label_GiaTri2";
            this.label_GiaTri2.Padding = new System.Windows.Forms.Padding(3);
            this.label_GiaTri2.Size = new System.Drawing.Size(126, 23);
            this.label_GiaTri2.TabIndex = 95;
            this.label_GiaTri2.Text = "Đường kháng (Wct)";
            // 
            // label_GiaTri3
            // 
            this.label_GiaTri3.AutoSize = true;
            this.label_GiaTri3.BackColor = System.Drawing.Color.Transparent;
            this.label_GiaTri3.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_GiaTri3.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label_GiaTri3.Location = new System.Drawing.Point(310, 160);
            this.label_GiaTri3.Name = "label_GiaTri3";
            this.label_GiaTri3.Padding = new System.Windows.Forms.Padding(3);
            this.label_GiaTri3.Size = new System.Drawing.Size(144, 23);
            this.label_GiaTri3.TabIndex = 96;
            this.label_GiaTri3.Text = "Khoảng cách cột (a,m)";
            // 
            // label_GiaTri4
            // 
            this.label_GiaTri4.AutoSize = true;
            this.label_GiaTri4.BackColor = System.Drawing.Color.Transparent;
            this.label_GiaTri4.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_GiaTri4.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label_GiaTri4.Location = new System.Drawing.Point(310, 200);
            this.label_GiaTri4.Name = "label_GiaTri4";
            this.label_GiaTri4.Padding = new System.Windows.Forms.Padding(3);
            this.label_GiaTri4.Size = new System.Drawing.Size(156, 23);
            this.label_GiaTri4.TabIndex = 97;
            this.label_GiaTri4.Text = "Khoảng cách hàng (b,m)";
            // 
            // label_GiaTri5
            // 
            this.label_GiaTri5.AutoSize = true;
            this.label_GiaTri5.BackColor = System.Drawing.Color.Transparent;
            this.label_GiaTri5.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_GiaTri5.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label_GiaTri5.Location = new System.Drawing.Point(310, 240);
            this.label_GiaTri5.Name = "label_GiaTri5";
            this.label_GiaTri5.Padding = new System.Windows.Forms.Padding(3);
            this.label_GiaTri5.Size = new System.Drawing.Size(188, 23);
            this.label_GiaTri5.TabIndex = 98;
            this.label_GiaTri5.Text = "Chiều sâu khoan thêm (Lkt, m)";
            // 
            // labelValue_GiaTri1
            // 
            this.labelValue_GiaTri1.BackColor = System.Drawing.Color.Transparent;
            this.labelValue_GiaTri1.Font = new System.Drawing.Font("Segoe UI Semibold", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelValue_GiaTri1.ForeColor = System.Drawing.Color.Black;
            this.labelValue_GiaTri1.Location = new System.Drawing.Point(500, 80);
            this.labelValue_GiaTri1.Name = "labelValue_GiaTri1";
            this.labelValue_GiaTri1.Padding = new System.Windows.Forms.Padding(3);
            this.labelValue_GiaTri1.Size = new System.Drawing.Size(150, 23);
            this.labelValue_GiaTri1.TabIndex = 99;
            this.labelValue_GiaTri1.Text = "value";
            // 
            // labelValue_GiaTri2
            // 
            this.labelValue_GiaTri2.BackColor = System.Drawing.Color.Transparent;
            this.labelValue_GiaTri2.Font = new System.Drawing.Font("Segoe UI Semibold", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelValue_GiaTri2.ForeColor = System.Drawing.Color.Black;
            this.labelValue_GiaTri2.Location = new System.Drawing.Point(500, 120);
            this.labelValue_GiaTri2.Name = "labelValue_GiaTri2";
            this.labelValue_GiaTri2.Padding = new System.Windows.Forms.Padding(3);
            this.labelValue_GiaTri2.Size = new System.Drawing.Size(150, 23);
            this.labelValue_GiaTri2.TabIndex = 100;
            this.labelValue_GiaTri2.Text = "value";
            // 
            // labelValue_GiaTri3
            // 
            this.labelValue_GiaTri3.BackColor = System.Drawing.Color.Transparent;
            this.labelValue_GiaTri3.Font = new System.Drawing.Font("Segoe UI Semibold", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelValue_GiaTri3.ForeColor = System.Drawing.Color.Black;
            this.labelValue_GiaTri3.Location = new System.Drawing.Point(500, 160);
            this.labelValue_GiaTri3.Name = "labelValue_GiaTri3";
            this.labelValue_GiaTri3.Padding = new System.Windows.Forms.Padding(3);
            this.labelValue_GiaTri3.Size = new System.Drawing.Size(150, 23);
            this.labelValue_GiaTri3.TabIndex = 101;
            this.labelValue_GiaTri3.Text = "value";
            // 
            // labelValue_GiaTri4
            // 
            this.labelValue_GiaTri4.BackColor = System.Drawing.Color.Transparent;
            this.labelValue_GiaTri4.Font = new System.Drawing.Font("Segoe UI Semibold", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelValue_GiaTri4.ForeColor = System.Drawing.Color.Black;
            this.labelValue_GiaTri4.Location = new System.Drawing.Point(500, 200);
            this.labelValue_GiaTri4.Name = "labelValue_GiaTri4";
            this.labelValue_GiaTri4.Padding = new System.Windows.Forms.Padding(3);
            this.labelValue_GiaTri4.Size = new System.Drawing.Size(150, 23);
            this.labelValue_GiaTri4.TabIndex = 102;
            this.labelValue_GiaTri4.Text = "value";
            // 
            // labelValue_GiaTri5
            // 
            this.labelValue_GiaTri5.BackColor = System.Drawing.Color.Transparent;
            this.labelValue_GiaTri5.Font = new System.Drawing.Font("Segoe UI Semibold", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelValue_GiaTri5.ForeColor = System.Drawing.Color.Black;
            this.labelValue_GiaTri5.Location = new System.Drawing.Point(500, 240);
            this.labelValue_GiaTri5.Name = "labelValue_GiaTri5";
            this.labelValue_GiaTri5.Padding = new System.Windows.Forms.Padding(3);
            this.labelValue_GiaTri5.Size = new System.Drawing.Size(150, 23);
            this.labelValue_GiaTri5.TabIndex = 103;
            this.labelValue_GiaTri5.Text = "value";
            // 
            // label_GiaTri6
            // 
            this.label_GiaTri6.AutoSize = true;
            this.label_GiaTri6.BackColor = System.Drawing.Color.Transparent;
            this.label_GiaTri6.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_GiaTri6.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label_GiaTri6.Location = new System.Drawing.Point(310, 280);
            this.label_GiaTri6.Name = "label_GiaTri6";
            this.label_GiaTri6.Padding = new System.Windows.Forms.Padding(3);
            this.label_GiaTri6.Size = new System.Drawing.Size(131, 23);
            this.label_GiaTri6.TabIndex = 104;
            this.label_GiaTri6.Text = "Chiều sâu tối đa (m)";
            // 
            // label_GiaTri7
            // 
            this.label_GiaTri7.AutoSize = true;
            this.label_GiaTri7.BackColor = System.Drawing.Color.Transparent;
            this.label_GiaTri7.Font = new System.Drawing.Font("Segoe UI", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label_GiaTri7.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label_GiaTri7.Location = new System.Drawing.Point(310, 320);
            this.label_GiaTri7.Name = "label_GiaTri7";
            this.label_GiaTri7.Padding = new System.Windows.Forms.Padding(3);
            this.label_GiaTri7.Size = new System.Drawing.Size(138, 23);
            this.label_GiaTri7.TabIndex = 105;
            this.label_GiaTri7.Text = "Chiều dài bua (Lb, m)";
            // 
            // labelValue_GiaTri6
            // 
            this.labelValue_GiaTri6.BackColor = System.Drawing.Color.Transparent;
            this.labelValue_GiaTri6.Font = new System.Drawing.Font("Segoe UI Semibold", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelValue_GiaTri6.ForeColor = System.Drawing.Color.Black;
            this.labelValue_GiaTri6.Location = new System.Drawing.Point(500, 280);
            this.labelValue_GiaTri6.Name = "labelValue_GiaTri6";
            this.labelValue_GiaTri6.Padding = new System.Windows.Forms.Padding(3);
            this.labelValue_GiaTri6.Size = new System.Drawing.Size(150, 23);
            this.labelValue_GiaTri6.TabIndex = 106;
            this.labelValue_GiaTri6.Text = "value";
            // 
            // labelValue_GiaTri7
            // 
            this.labelValue_GiaTri7.BackColor = System.Drawing.Color.Transparent;
            this.labelValue_GiaTri7.Font = new System.Drawing.Font("Segoe UI Semibold", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelValue_GiaTri7.ForeColor = System.Drawing.Color.Black;
            this.labelValue_GiaTri7.Location = new System.Drawing.Point(500, 320);
            this.labelValue_GiaTri7.Name = "labelValue_GiaTri7";
            this.labelValue_GiaTri7.Padding = new System.Windows.Forms.Padding(3);
            this.labelValue_GiaTri7.Size = new System.Drawing.Size(150, 23);
            this.labelValue_GiaTri7.TabIndex = 107;
            this.labelValue_GiaTri7.Text = "value";
            // 
            // backgroundWorker_Loading
            // 
            this.backgroundWorker_Loading.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker_Loading_DoWork);
            this.backgroundWorker_Loading.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.backgroundWorker_Loading_RunWorkerCompleted);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("Segoe UI Semibold", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.label2.Location = new System.Drawing.Point(30, 140);
            this.label2.Name = "label2";
            this.label2.Padding = new System.Windows.Forms.Padding(3);
            this.label2.Size = new System.Drawing.Size(154, 27);
            this.label2.TabIndex = 108;
            this.label2.Text = "Người lập hộ chiếu";
            // 
            // textBoxNguoiLapHoChieu
            // 
            this.textBoxNguoiLapHoChieu.Font = new System.Drawing.Font("Segoe UI", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBoxNguoiLapHoChieu.Location = new System.Drawing.Point(25, 180);
            this.textBoxNguoiLapHoChieu.Name = "textBoxNguoiLapHoChieu";
            this.textBoxNguoiLapHoChieu.Size = new System.Drawing.Size(200, 22);
            this.textBoxNguoiLapHoChieu.TabIndex = 109;
            // 
            // FormBaoCaoThongKe
            // 
            this.Appearance.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(246)))), ((int)(((byte)(246)))), ((int)(((byte)(246)))));
            this.Appearance.Options.UseBackColor = true;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 411);
            this.Controls.Add(this.textBoxNguoiLapHoChieu);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.labelValue_GiaTri7);
            this.Controls.Add(this.labelValue_GiaTri6);
            this.Controls.Add(this.label_GiaTri7);
            this.Controls.Add(this.label_GiaTri6);
            this.Controls.Add(this.labelValue_GiaTri5);
            this.Controls.Add(this.labelValue_GiaTri4);
            this.Controls.Add(this.labelValue_GiaTri3);
            this.Controls.Add(this.labelValue_GiaTri2);
            this.Controls.Add(this.labelValue_GiaTri1);
            this.Controls.Add(this.label_GiaTri5);
            this.Controls.Add(this.label_GiaTri4);
            this.Controls.Add(this.label_GiaTri3);
            this.Controls.Add(this.label_GiaTri2);
            this.Controls.Add(this.label_GiaTri1);
            this.Controls.Add(this.labelText3);
            this.Controls.Add(this.comboBox_MaHoChieu);
            this.Controls.Add(this.labelText);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonTaoMoi);
            this.Name = "FormBaoCaoThongKe";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Báo cáo - thống kê";
            this.Shown += new System.EventHandler(this.FormBaoCaoThongKe_Shown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonTaoMoi;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label labelText;
        private System.Windows.Forms.ComboBox comboBox_MaHoChieu;
        private System.Windows.Forms.Label labelText3;
        private System.Windows.Forms.Label label_GiaTri1;
        private System.Windows.Forms.Label label_GiaTri2;
        private System.Windows.Forms.Label label_GiaTri3;
        private System.Windows.Forms.Label label_GiaTri4;
        private System.Windows.Forms.Label label_GiaTri5;
        private System.Windows.Forms.Label labelValue_GiaTri1;
        private System.Windows.Forms.Label labelValue_GiaTri2;
        private System.Windows.Forms.Label labelValue_GiaTri3;
        private System.Windows.Forms.Label labelValue_GiaTri4;
        private System.Windows.Forms.Label labelValue_GiaTri5;
        private System.Windows.Forms.Label label_GiaTri6;
        private System.Windows.Forms.Label label_GiaTri7;
        private System.Windows.Forms.Label labelValue_GiaTri6;
        private System.Windows.Forms.Label labelValue_GiaTri7;
        private System.ComponentModel.BackgroundWorker backgroundWorker_Loading;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxNguoiLapHoChieu;
    }
}