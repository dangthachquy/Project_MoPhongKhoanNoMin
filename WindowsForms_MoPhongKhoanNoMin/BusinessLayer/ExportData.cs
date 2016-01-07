﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;

using WindowsForms_MoPhongKhoanNoMin.DataAccessLayer;

namespace WindowsForms_MoPhongKhoanNoMin.BusinessLayer
{
    class ExportData
    {
        //dữ liệu tính toán.
        public double duongKhang;             // Đường Kháng 
        public double KC_Hang;               // Khoảng cách giữa các hàng. (b)
        public double KC_Cot;               // Khoảng cách giữa các lỗ mìn (A)
        public double chieuSauThem;
        public double chieuSauToanBoLK;     // Chiều dài lỗ khoan  (Lk)
        public double chieuDaiBua;          //Chieu cao cột bua thiết kế  (Lbua)
        public double congTB;
        public int soCotMin, hangMin, tongLoMin;
        public HoChieu hoChieu = new HoChieu();
        public List<LoKhoan> danhSachLoKhoan = new List<LoKhoan>();
        public DateTime thoiDiemNo;
        public DatDa datDa;
        public CapDoNo capDoNo;
        public MayKhoan mayKhoan;
        public ThuocNo thuocNo;
        public CongTruong congTruong;

        public ExportData(String _maHoChieu)
        {
            Connection conn = new Connection();
            string sql = "SELECT HoChieu.*, LoKhoan.ID, LoKhoan.MaLK, LoKhoan.BanKinhLK, LoKhoan.ChieuSauLK FROM LoKhoan, BanVe, HoChieu WHERE HoChieu.MaHoChieu = LoKhoan.MaHoChieu And BanVe.ID= HoChieu.MaBanVe and HoChieu.MaHoChieu = \'" + _maHoChieu + "\';";
            SQLiteDataReader dr = conn.GetData(sql);
            while (dr.Read())
            {
                hoChieu.TenHoChieu = dr["TenHoChieu"].ToString();
                hoChieu.ChieuCaoTang = Convert.ToDouble(dr["ChieuCaoTang"].ToString());
                hoChieu.HeSoKC = Convert.ToDouble(dr["HeSoKC"].ToString());
                hoChieu.KichThuoc_X = Convert.ToDouble(dr["KichThuoc_X"].ToString());
                hoChieu.KichThuoc_Y = Convert.ToDouble(dr["KichThuoc_Y"].ToString());

                //thoiDiemNo = Convert.ToDateTime(dr["ThoiDiemNo"].ToString());
   
                hoChieu.MaDatDa = dr["MaDatDa"].ToString();
                hoChieu.MaCapDo = dr["MaCapDo"].ToString();
                hoChieu.MaMayKhoan = dr["MaMayKhoan"].ToString();
                hoChieu.MaThuocNo = dr["MaThuocNo"].ToString();
                hoChieu.MaCongTruong = dr["MaCongTruong"].ToString();
                danhSachLoKhoan.Add(new LoKhoan(dr["MaLK"].ToString(), Convert.ToDouble(dr["BanKinhLK"].ToString()), Convert.ToDouble(dr["ChieuSauLK"].ToString())));
            }
            dr.Close();

            //Lấy hết giá trị của bảng Đất Đá 
            datDa = BS_DatDa.DatDa(hoChieu.MaDatDa);

            //Lấy hết giá trị từ bảng Cấp độ nổ
            capDoNo = BS_CapDoNo.CapDoNo(hoChieu.MaCapDo);

            //Lấy hết giá trị của bảng Máy khoan 
            mayKhoan = BS_MayKhoan.MayKhoan(hoChieu.MaMayKhoan);

            //Lấy hết giá trị của bảng Thuốc nổ
            thuocNo = BS_ThuocNo.ThuocNo(hoChieu.MaThuocNo);

            //Lấy hết giá trị của bảng Công trường
            congTruong = BS_CongTruong.CongTruong(hoChieu.MaCongTruong);

            //tính toán
            congTB = Math.Round((thuocNo.KhaNangSinhCong / 360) * 100) / 100;   // Cong trung binh (e)

            //duong Khang chan tang
            duongKhang = Math.Round((53 * datDa.KCTB_KhoiNut * (mayKhoan.DuongKinhLoKhoan / 1000) * Math.Sqrt(thuocNo.MatDoNapThuoc * congTB / datDa.DungTrong) * (1.6 - 0.5 * hoChieu.HeSoKC)) * 100) / 100;
            //Khoang cach giua cac lo min  (Kí Hiệu {A})
            KC_Cot = Math.Round((hoChieu.HeSoKC * duongKhang) * 100) / 100;
            // Khoảng cách giữa các hàng  (Kí Hiệu {b})
            KC_Hang = Math.Round((0.85 * KC_Cot) * 100) / 100;
            //Chieu sau khoan them
            chieuSauThem = Math.Round((0.3 * KC_Hang) * 100) / 100;
            // Chieu dai lo khoan (Kí Hiệu {Lk})
            chieuSauToanBoLK = Math.Round((mayKhoan.ChieuSau + chieuSauThem) * 100) / 100;
            // Chieu cao cột bua thiết kế ( Kí Hiệu {Lbua})
            chieuDaiBua = Math.Round((0.75 * duongKhang) * 100) / 100;
            //Hang min
            //hangMin = Convert.ToInt32(hoChieu.KichThuoc_Y / KC_Hang);
            //Hangmin = Math.Round(Hangmin * 100) / 100;
            //Cot min
            //soCotMin = Convert.ToInt32((hoChieu.KichThuoc_X - duongKhang) / KC_Cot);
            // Tổng số lỗ mìn    (Kí Hiệu {Tổng số lỗ})
            //tongLoMin = soCotMin * hangMin;
        }
    }
}
