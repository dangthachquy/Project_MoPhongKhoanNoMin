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
using System.Threading;
using System.IO;

namespace WindowsForms_MoPhongKhoanNoMin.GUILayer
{
    public partial class FormMain : DevExpress.XtraEditors.XtraForm
    {
        //biến LiteCAD
        private int hWnd;   //biến hiển thị giao diện - Windows        
        private int hCmd;   //biến hiển thị giao diện - Command
        private int hProp;  //biến hiển thị giao diện - Properties
        private int hDrw;   //biến lưu bản vẽ hiện tại
        //biến layer
        private int layerLoMin;
        private int layerLuoiKichThuoc;
        //private int nameOfBlock;
        //biến lưu sự kiện mouse click
        F_MOUSEDBLCLK _EventMouseDbclick_LoMin;
        F_MOUSEDBLCLK _EventMouseDbclick_XayDungLuoiLoMin;
        F_MOUSEDOWN _EventMouseDown_Default;
        F_MOUSEDOWN _EventMouseDown_GetPoint;
        //biến bản vẽ hiện tại
        HoChieu hoChieuChinh = new HoChieu();
        BanVe banVeChinh = new BanVe();
        private ManageCircle mgCircles = new ManageCircle();
        //dữ liệu để dựng lưới lỗ khoan
        private int soHang, soCot, khoangCachHang, khoangCachCot;
        private double banKinh;
        //private bool hienThiKichThuoc;
        //dữ liệu để khoanh vùng lỗ khoan
        private double xFirstPoint, yFirstPoint, xLastPoint, yLastPoint;
        //khóa key để nhận dạng Circle
        private int keyCircle = 22;

        public FormMain()
        {
            InitializeComponent();
            Lcad.PropPutStr(0, Lcad.LC_PROP_G_REGCODE, "1234"); // 1234 là mã số khi mua LiteCad đã đăng ký 
            //Lcad.PropPutStr(0, Lcad.LC_PROP_G_DIRDATA, @"..\..\LiteCAD\Data");
            //Lcad.PropPutStr(0, Lcad.LC_PROP_G_DIRPLUG, @"..\..\LiteCAD\Data\Plugins");
            //Lcad.PropPutStr(0, Lcad.LC_PROP_G_DIRCFG, @"..\..\LiteCAD");
            Lcad.PropPutBool(0, Lcad.LC_PROP_G_DLGRECENT, true);
            Lcad.PropPutBool(0, Lcad.LC_PROP_G_ADDRECENT, true);
            //gán các sự kiện mouse click với các hàm
            _EventMouseDbclick_LoMin = new F_MOUSEDBLCLK(MouseDblClkProc_LoMin);
            _EventMouseDbclick_XayDungLuoiLoMin = new F_MOUSEDBLCLK(MouseDblClkProc_XayDungLuoiLoMin);
            _EventMouseDown_Default = new F_MOUSEDOWN(MouseDownProc_Default);
            Lcad.OnEventMouseDblClk(_EventMouseDbclick_LoMin);
            Lcad.Initialize();
            //UI
            this.BackColor = Properties.Settings.Default.FormBackgroundColor;
        }

        private void FormMain_Load(object sender, EventArgs e)
        {           
            //tạo cửa sổ - Windows
            hWnd = Lcad.CreateWindow(panelControl_hWnd.Handle, Lcad.LC_WS_VIEWTABS, 0, 0, panelControl_hWnd.Width, panelControl_hWnd.Height);
            //tạo cửa sổ - Command
            hCmd = Lcad.CreateCmdwin(panelControl_hCmd.Handle, 0, 0, panelControl_hCmd.Width, panelControl_hCmd.Height);
            //tạo cửa sổ - Properties
            hProp = Lcad.CreatePropwin(splitContainerControl.Panel1.Handle, 0, 0, splitContainerControl.Panel1.Width, splitContainerControl.Panel1.Height);
            //liên kết các cửa sổ với nhau
            Lcad.WndSetCmdwin(hWnd, hCmd);           
            Lcad.WndSetPropwin(hWnd, hProp);
            //tạo bản vẽ, gán cho cửa sổ LiteCad + đặt tên
            hDrw = Lcad.CreateDrawing();
            Lcad.DrwNew(hDrw, "", hWnd);
            Lcad.WndSetFocus(hWnd);
            //lấy giá trị hBlockModel của bản vẽ
            int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
            //điều chỉnh kích thước
            Lcad.CmdwinResize(hCmd, 0, 0, panelControl_hCmd.Width, panelControl_hCmd.Height);
            Lcad.PropwinResize(hProp, 0, 0, splitContainerControl.Panel1.Width, splitContainerControl.Panel1.Height);
            Lcad.WndResize(hWnd, 0, 0, panelControl_hWnd.Width, panelControl_hWnd.Height);
            //thêm layer
            layerLoMin = Lcad.DrwAddLayer(hDrw, "LoMin", "cyan", 0, Lcad.LC_LWEIGHT_DEFAULT);
            layerLuoiKichThuoc = Lcad.DrwAddLayer(hDrw, "LuoiKichThuoc", "foreground", 0, Lcad.LC_LWEIGHT_DEFAULT);
            //vẽ lại hình
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_REGEN, 0);
            Lcad.DrwRegenViews(hDrw, 0);
            Lcad.Initialize();
        }
        
        //aka FormMain_Loaded :D    
        private void FormMain_Shown(object sender, EventArgs e)
        {
            //load form bắt đầu
            FormStart fm = new FormStart();
            fm.MyGetData = new FormStart.GetData(loadFile_FormMoBanVeDatabase);
            fm.Show();
        }

        private void FormMain_SizeChanged(object sender, EventArgs e)
        {
            Lcad.CmdwinResize(hCmd, 0, 0, panelControl_hCmd.Width, panelControl_hCmd.Height);
            Lcad.PropwinResize(hProp, 0, 0, splitContainerControl.Panel1.Width, splitContainerControl.Panel1.Height);
            Lcad.WndResize(hWnd, 0, 0, panelControl_hWnd.Width, panelControl_hWnd.Height);
            if(this.Width > 1000)
            {
                Point a = new Point(this.Width - 300, 30);
                elementHost1.Location = a;
            }
            panelStatusBar.Width = this.Width - 16;
        }

        private void MouseDblClkProc_LoMin(int hWnd, int Button, int Flags, int Xwin, int Ywin, double Xdrw, double Ydrw)
        {
            if (Button == Lcad.LC_LBUTTON)
            {
                List<Circle> listCircle = mgCircles.GetListCircles();
                foreach (Circle c in listCircle)
                {
                    if (BS_LiteCAD.CheckInCirlce(Xdrw, Ydrw, c))
                    {
                        FormLoKhoan fm = new FormLoKhoan(hoChieuChinh.MaHoChieu ,c.GetID().ToString());
                        fm.Show();
                        break;
                    }
                }
            }
        }
        //tab - hệ thống
        //tạo bản vẽ
        private void barButtonItem_New_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormHoChieuMoi fm = new FormHoChieuMoi();
            fm.MyGetData = new FormHoChieuMoi.GetData(loadFile_FormBanVeMoi);
            fm.Show();
        }
        private void loadFile_FormBanVeMoi(String idHoChieu)
        {
            this.hoChieuChinh = BS_HoChieu.HoChieu(idHoChieu);
            this.banVeChinh = BS_BanVe.BanVe(this.hoChieuChinh.MaBanVe);                    
            mgCircles = new ManageCircle();
            //dựng bản vẽ mới
            this.Text = "Hộ chiếu: [" + this.hoChieuChinh.TenHoChieu + "]";
            Lcad.DrwLoad(hDrw, BS_Template.ChonTemplate(this.banVeChinh.Template).DuongDan, this.Handle, hWnd);
            layerLoMin = Lcad.DrwAddLayer(hDrw, "LoMin", "cyan", 0, Lcad.LC_LWEIGHT_DEFAULT);
            layerLuoiKichThuoc = Lcad.DrwAddLayer(hDrw, "LuoiKichThuoc", "foreground", 0, Lcad.LC_LWEIGHT_DEFAULT);
            //vẽ lại hình
            Lcad.DrwRegenViews(hDrw, 0);
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
            //mở form dựng lưới lỗ khoan
            if (mgCircles.GetListCircles().Count == 0)
            {
                FormXayDungLoKhoan fm = new FormXayDungLoKhoan();
                fm.MyGetData = new FormXayDungLoKhoan.GetData(loadFile_FormXayDungLoKhoan);
                fm.Show();
            }
        }
        //mở bản vẽ
        private void barButtonItem_OpenFile_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            try
            {
                //filename = Lcad.DgGetFileName(panelControl_hWnd.Handle, Lcad.LC_DG_SELFILE);
                OpenFileDialog filename = new OpenFileDialog();
                filename.Title = "Open file LiteCAD";
                filename.Filter = "Drawing liteCAD|*.lcd;*.dwg;*.dxf;*.shp|all file|*.*";
                if (filename.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    if (filename.FileName != "")
                    {
                        this.hoChieuChinh = new HoChieu();
                        this.banVeChinh = new BanVe();
                        //this.banVeChinh.HienKhoangCach = false;
                        this.Text = "Bản vẽ: [" + filename.FileName + "]";
                        Lcad.DrwLoad(hDrw, filename.FileName, this.Handle, hWnd);
                        layerLoMin = Lcad.DrwAddLayer(hDrw, "LoMin", "cyan", 0, Lcad.LC_LWEIGHT_DEFAULT);
                        layerLuoiKichThuoc = Lcad.DrwAddLayer(hDrw, "LuoiKichThuoc", "foreground", 0, Lcad.LC_LWEIGHT_DEFAULT);
                        GetCirlcesFromAutocadFile();
                        Lcad.DrwRegenViews(hDrw, 0);
                        BS_LiteCAD.ShowNotifyAutoHide(elementHost1, "Bản vẽ sẵn sàng");
                    }
                }
            }
            catch
            {
                BS_LiteCAD.ShowNotifyAutoHide(elementHost1, "Không hiển thị được bản vẽ");
            }
        }
        //mở hộ chiếu từ CSDL
        private void barButtonItem_OpenFromDatabase_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormMoHoChieuDatabase fm = new FormMoHoChieuDatabase();
            fm.MyGetData = new FormMoHoChieuDatabase.GetData(loadFile_FormMoBanVeDatabase);
            fm.Show();
        }
        private void loadFile_FormMoBanVeDatabase(String idHoChieu)
        {
            this.hoChieuChinh = BS_HoChieu.HoChieu(idHoChieu);
            this.banVeChinh = BS_BanVe.BanVe(this.hoChieuChinh.MaBanVe);
            List<LoKhoan> danhSachLoKhoan = BS_LoKhoan.DanhSachLoKhoan(idHoChieu);
            List<Circle> danhSachCircle = new List<Circle>();
            mgCircles = new ManageCircle();
            //dựng bản vẽ mới          
            //this.banVeChinh.HienKhoangCach = false;
            this.Text = "Bản vẽ: [" + this.banVeChinh.TenBanVe + "]";
            Lcad.DrwLoad(hDrw, BS_Template.ChonTemplate(this.banVeChinh.Template).DuongDan, this.Handle, hWnd);
            layerLoMin = Lcad.DrwAddLayer(hDrw, "LoMin", "cyan", 0, Lcad.LC_LWEIGHT_DEFAULT);
            layerLuoiKichThuoc = Lcad.DrwAddLayer(hDrw, "LuoiKichThuoc", "foreground", 0, Lcad.LC_LWEIGHT_DEFAULT);
            int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
            foreach (LoKhoan value in danhSachLoKhoan)
            {
                int hEntCircle = Lcad.BlockAddCircle(hBlockModel, value.ToaDoX, value.ToaDoY, value.BanKinh, false);
                Lcad.PropPutInt(hEntCircle, Lcad.LC_PROP_ENT_ID, int.Parse(value.MaLoKhoan));
                Lcad.PropPutInt(hEntCircle, Lcad.LC_PROP_ENT_KEY, keyCircle);
                Lcad.PropPutStr(hEntCircle, Lcad.LC_PROP_ENT_LAYER, "LoMin");
                danhSachCircle.Add(new Circle(hEntCircle));
            }
            mgCircles.AddListCircle(danhSachCircle);
            if (banVeChinh.HienKhoangCach)
            {
                Lcad.LayerClear(layerLuoiKichThuoc, hBlockModel);
                DungLuoiKichThuoc();
            }
            //vẽ lại hình
            Lcad.DrwRegenViews(hDrw, 0);
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
            BS_LiteCAD.ShowNotifyAutoHide(elementHost1, this.banVeChinh.TenBanVe + " - đã mở");
            //mở form dựng lưới lỗ khoan
            if(mgCircles.GetListCircles().Count == 0)
            {
                FormXayDungLoKhoan fm = new FormXayDungLoKhoan();
                fm.MyGetData = new FormXayDungLoKhoan.GetData(loadFile_FormXayDungLoKhoan);
                fm.Show();
            }          
        }
        //thông tin bản vẽ
        private void barButtonItem_Info_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormThongTinBanVe fm = new FormThongTinBanVe(this.hoChieuChinh.MaHoChieu);
            fm.Show();
        }
        //lưu hộ chiếu
        private void barButtonItem_Save_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            if (this.hoChieuChinh.MaHoChieu == null)
            {
                FormNhapTenHoChieu fm = new FormNhapTenHoChieu();
                fm.MyGetData = new FormNhapTenHoChieu.GetData(LuuHoChieu);
                fm.Show();
            }
            else
            {
                LuuHoChieu(this.hoChieuChinh.MaHoChieu);
            }                 
        }
        private void LuuHoChieu(String idHoChieu)
        {            
            List<LoKhoan> danhSachLoKhoan = new List<LoKhoan>();
            GetCirlcesFromAutocadFile();
            List<Circle> danhSachCircle = mgCircles.GetListCircles();
            foreach (Circle value in danhSachCircle)
            {
                danhSachLoKhoan.Add(new LoKhoan(idHoChieu, value));
            }
            BS_HoChieu.LuuBanVe(danhSachLoKhoan, idHoChieu);
            //BS_BanVe.CapNhatDelta(BS_HoChieu.HoChieu(idHoChieu).MaBanVe, this.banVeChinh.DeltaX, this.banVeChinh.DeltaY);
            BS_BanVe.CapNhatBanVe(banVeChinh);
            BS_LiteCAD.ShowNotifyAutoHide(elementHost1, BS_HoChieu.HoChieu(idHoChieu).TenHoChieu + " - đã lưu");
        }
        //lưu với tên mới
        private void barButtonItem_SaveAs_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormNhapTenHoChieu fm = new FormNhapTenHoChieu();
            fm.MyGetData = new FormNhapTenHoChieu.GetData(LuuHoChieu);
            fm.Show();
        }
        //xuất tệp tin
        private void barButtonItem_Export_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_FILESAVEAS, 0);
        }

        //tab - 2
        private void barButtonItem_BanVe_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyBanVe fm = new FormQuanLyBanVe();
            fm.Show();
        }
        private void barButtonItem_HoChieu_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyHoChieu fm = new FormQuanLyHoChieu();
            fm.Show();
        }
        private void barButtonItem_LoKhoan_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyLoKhoan fm = new FormQuanLyLoKhoan();
            fm.Show();
        }
        private void barButtonItem_MayKhoan_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyMayKhoan fm = new FormQuanLyMayKhoan();
            fm.Show();
        }
        private void barButtonItem_CongTruong_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyCongTruong fm = new FormQuanLyCongTruong();
            fm.Show();
        }
        private void barButtonItem_DatDa_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyDatDa fm = new FormQuanLyDatDa();
            fm.Show();
        }
        private void barButtonItem_CapDoNo_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyCapDoNo fm = new FormQuanLyCapDoNo();
            fm.Show();
        }
        private void barButtonItem_ThuocNo_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyThuocNo fm = new FormQuanLyThuocNo();
            fm.Show();
        }
        private void barButtonItem_KipNo_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyKipNo fm = new FormQuanLyKipNo();
            fm.Show();
        }
        private void barButtonItem_PhuongPhapNo_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyPhuongPhapNo fm = new FormQuanLyPhuongPhapNo();
            fm.Show();
        }
        private void barButtonItem_PhuKienNo_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormQuanLyPhuKienNo fm = new FormQuanLyPhuKienNo();
            fm.Show();
        }


        //...
        private void loadFile_FormXayDungLoKhoan(int _soHang, int _soCot, int _khoangCachHang, int _khoangCachCot, double _banKinh, bool _hienThiKichThuoc)
        {
            this.soHang = _soHang;
            this.soCot = _soCot;
            this.khoangCachHang = _khoangCachHang;
            this.khoangCachCot = _khoangCachCot;
            this.banKinh = _banKinh;
            this.banVeChinh.HienKhoangCach = _hienThiKichThuoc;
            this.banVeChinh.DeltaX = Math.Abs(_khoangCachCot);
            this.banVeChinh.DeltaY = Math.Abs(_khoangCachHang);
            Lcad.OnEventMouseDblClk(_EventMouseDbclick_XayDungLuoiLoMin);
            UserControl_Notify note = new UserControl_Notify("Chọn tọa độ");
            elementHost1.Child = note;
            note.ShowNotify();
        }

        //private void barButtonItem13_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        //{
        //    if(mgCircles.GetListCircles().Count == 0)
        //    {
        //        UserControl_Notify note = new UserControl_Notify("Không có lỗ khoan");
        //        elementHost1.Child = note;
        //        note.ShowNotifyAutoHide();
        //    }
        //    else
        //    {
        //        DungLuoiKichThuoc();
        //        Lcad.DrwRegenViews(hDrw, 0);
        //        Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
        //    }
        //    this.banVeChinh.HienKhoangCach = true;
        //}      

        private void barButtonItem_AnKhoangCach_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            this.banVeChinh.HienKhoangCach = false;
            Lcad.PropPutBool(layerLuoiKichThuoc, Lcad.LC_PROP_LAYER_VISIBLE, false);
            Lcad.DrwRegenViews(hDrw, 0);
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
        }
        private void barButtonItem_HienKhoangCach_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            DungLuoiKichThuoc();
            this.banVeChinh.HienKhoangCach = true;
            Lcad.PropPutBool(layerLuoiKichThuoc, Lcad.LC_PROP_LAYER_VISIBLE, true);
            Lcad.DrwRegenViews(hDrw, 0);
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
        }
        private void barButtonItem_ThemCotLoKhoan_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            AddColumnCircle();
        }
        private void barButtonItem_ThemHangLoKhoan_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            AddRowCircle();
        }
        private void barButtonItem_XoaCotLoKhoan_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            DeleteColumnCircle();
        }
        private void barButtonItem_XoaHangLoKhoan_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            DeleteRowCircle();
        }

        private void barButtonItem_KhoanhVungLoKhoan_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            _EventMouseDown_GetPoint = new F_MOUSEDOWN(MouseDownProc_GetFirstPoint);
            Lcad.OnEventMouseDown(_EventMouseDown_GetPoint);
            //hiển thị thông báo
            UserControl_Notify note = new UserControl_Notify("Chọn điểm đầu");
            elementHost1.Child = note;
            note.ShowNotify();
        }

        private void barButtonItem_Rotate_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {           
            //select toàn bộ lỗ khoan
            int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
            int hEnt = Lcad.BlockGetFirstEnt(hBlockModel);
            List<Circle> listCircles = new List<Circle>();
            while (hEnt != 0)
            {
                int entType = Lcad.PropGetInt(hEnt, Lcad.LC_PROP_ENT_TYPE);
                if (!Lcad.PropGetBool(hEnt, Lcad.LC_PROP_ENT_DELETED))   //kiểm tra xem ent bị xóa hay không
                {
                    if (entType == Lcad.LC_ENT_CIRCLE)
                    {
                        Lcad.BlockSelectEnt(hBlockModel, hEnt, true);
                    }
                    //cách khác (dùng key, vì cái gì đấy mà ko lấy được LC_PROP_ENT_TYPE) - do thư viện....
                    else
                    {
                        int _key = Lcad.PropGetInt(hEnt, Lcad.LC_PROP_ENT_KEY);
                        if (_key == keyCircle)
                        {
                            Lcad.BlockSelectEnt(hBlockModel, hEnt, true);
                        }
                    }
                }
                hEnt = Lcad.BlockGetNextEnt(hBlockModel, hEnt);
            }
            //chạy hàm rotate
            bool flag = Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ROTATE, 0);
            if (flag)
            {
                mgCircles = new ManageCircle();
                GetCirlcesFromAutocadFile();
                if (this.banVeChinh.HienKhoangCach)
                {
                    DungLuoiKichThuoc();
                }
            }
        }

        private void barButtonItem_Move_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            //select toàn bộ lỗ khoan
            int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
            int hEnt = Lcad.BlockGetFirstEnt(hBlockModel);
            List<Circle> listCircles = new List<Circle>();
            while (hEnt != 0)
            {
                int entType = Lcad.PropGetInt(hEnt, Lcad.LC_PROP_ENT_TYPE);
                if (!Lcad.PropGetBool(hEnt, Lcad.LC_PROP_ENT_DELETED))   //kiểm tra xem ent bị xóa hay không
                {
                    if (entType == Lcad.LC_ENT_CIRCLE)
                    {
                        Lcad.BlockSelectEnt(hBlockModel, hEnt, true);
                    }
                    //cách khác (dùng key, vì cái gì đấy mà ko lấy được LC_PROP_ENT_TYPE) - do thư viện....
                    else
                    {
                        int _key = Lcad.PropGetInt(hEnt, Lcad.LC_PROP_ENT_KEY);
                        if (_key == keyCircle)
                        {
                            Lcad.BlockSelectEnt(hBlockModel, hEnt, true);
                        }
                    }
                }
                hEnt = Lcad.BlockGetNextEnt(hBlockModel, hEnt);
            }
            //chạy hàm move
            bool flag = Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_MOVE, 0);
            if (flag)
            {
                mgCircles = new ManageCircle();
                GetCirlcesFromAutocadFile();
                if (this.banVeChinh.HienKhoangCach)
                {
                    DungLuoiKichThuoc();
                }
            }
        }

        //cập nhật thông tin toàn bộ lỗ khoan
        private void barButtonItem_CapNhatLoKhoan_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            FormLoKhoanHoChieu fm = new FormLoKhoanHoChieu(this.hoChieuChinh.MaHoChieu);
            fm.MyGetData += new FormLoKhoanHoChieu.GetData(loadFile_FormLoKhoanBanVe);
            fm.Show();
        }
        private void loadFile_FormLoKhoanBanVe(bool flag)
        {
            if (flag)
            {
                BS_LiteCAD.ShowNotifyAutoHide(elementHost1, "Cập nhật thành công");
            }
        }

        //
        private void barButtonItem_HoChieuNoMin_ItemClick(object sender, DevExpress.XtraBars.ItemClickEventArgs e)
        {
            Lcad.PropPutInt(hDrw, Lcad.LC_PROP_DRW_COLORBACKM, int.Parse("FFFFFF", System.Globalization.NumberStyles.HexNumber));
            Lcad.PropPutInt(hDrw, Lcad.LC_PROP_DRW_COLORFOREM, int.Parse("000000", System.Globalization.NumberStyles.HexNumber));
            Lcad.PropPutStr(layerLoMin, Lcad.LC_PROP_LAYER_COLOR, "blue");
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_REGEN, 0);
            Lcad.DrwRegenViews(hDrw, 0);
            Lcad.Initialize();
            int hView = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_VIEW);
            String fullPath = Path.GetFullPath(Path.Combine((@"" + Application.StartupPath), @"..\..\"));
            Lcad.ViewRasterize(hView, fullPath + "Template\\ViewTemp.bmp", 0, 0, 0, 0, 10);
            Lcad.PropPutInt(hDrw, Lcad.LC_PROP_DRW_COLORBACKM, int.Parse("000000", System.Globalization.NumberStyles.HexNumber));
            Lcad.PropPutInt(hDrw, Lcad.LC_PROP_DRW_COLORFOREM, int.Parse("FFFFFF", System.Globalization.NumberStyles.HexNumber));
            Lcad.PropPutStr(layerLoMin, Lcad.LC_PROP_LAYER_COLOR, "cyan");
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_REGEN, 0);
            Lcad.DrwRegenViews(hDrw, 0);
            Lcad.Initialize();
            FormBaoCaoThongKe fm = new FormBaoCaoThongKe(hoChieuChinh);
            fm.Show();          
        }

        private void MouseDblClkProc_XayDungLuoiLoMin(int hWnd, int Button, int Flags, int Xwin, int Ywin, double Xdrw, double Ydrw)
        {
            int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
            if (mgCircles == null)
            {
                mgCircles = new ManageCircle();
            }
            else
            {
                Lcad.LayerClear(layerLoMin, hBlockModel);
                Lcad.LayerClear(layerLuoiKichThuoc, hBlockModel);
                mgCircles = new ManageCircle();
            }                                
            int hEntCircle = Lcad.BlockAddCircle(hBlockModel, Xdrw, Ydrw, banKinh, false);
            Lcad.PropPutInt(hEntCircle, Lcad.LC_PROP_ENT_KEY, keyCircle);
            Lcad.PropPutStr(hEntCircle, Lcad.LC_PROP_ENT_LAYER, "LoMin");
            Lcad.BlockUnselect(hBlockModel);           
            //tạo danh sách cột đầu tiên
            List<Circle> listCotDau = new List<Circle>();
            Circle root = new Circle(hEntCircle);
            listCotDau.Add(root);
            //tạo cột đầu tiên từ điểm gốc (số điểm trong cột ứng với số hàng trừ đi điểm gốc)
            for (int i = 0; i < soHang - 1; i++)
            {
                int newHEnt = Lcad.BlockAddClone(hBlockModel, listCotDau[i].GetHandle());
                Lcad.PropPutInt(newHEnt, Lcad.LC_PROP_ENT_KEY, keyCircle);
                Lcad.BlockSelectEnt(hBlockModel, newHEnt, true);
                Lcad.BlockSelMove(hBlockModel, 0, khoangCachHang, false, true);
                Lcad.BlockUnselect(hBlockModel);
                listCotDau.Add(new Circle(newHEnt));
            }
            mgCircles.AddListCircle(listCotDau);
            //thêm các cột còn lại (ứng với số cột trừ đi cột đầu)         
            for (int i = 0; i < soCot - 1; i++)
            {
                List<Circle> listCotGanNhat = new List<Circle>();
                List<Circle> listCotMoi = new List<Circle>();
                if (khoangCachCot > 0)
                {
                    listCotGanNhat = mgCircles.GetListCirleOfLastColumn();
                }
                else
                {
                    listCotGanNhat = mgCircles.GetListCirleOfFirstColumn();
                }
                foreach (var circle in listCotGanNhat)
                {
                    int newHEnt = Lcad.BlockAddClone(hBlockModel, circle.GetHandle());
                    Lcad.PropPutInt(newHEnt, Lcad.LC_PROP_ENT_KEY, keyCircle);
                    Lcad.BlockSelectEnt(hBlockModel, newHEnt, true);
                    Lcad.BlockSelMove(hBlockModel, khoangCachCot, 0, false, true);
                    Lcad.BlockUnselect(hBlockModel);
                    listCotMoi.Add(new Circle(newHEnt));
                }
                mgCircles.AddListCircle(listCotMoi);
            }
            //hiển thị lưới kích thước
            if (this.banVeChinh.HienKhoangCach)
            {
                DungLuoiKichThuoc();
            }
            //load lại
            //MessageBox.Show("hang" + soHang + "\ncot" + soCot + "\nkc hang" + khoangCachHang + "\nkc cot" + khoangCachCot + "\nX" + Xdrw + "\nY" + Ydrw);
            Lcad.DrwRegenViews(hDrw, 0);
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
            Lcad.OnEventMouseDblClk(_EventMouseDbclick_LoMin);
            LuuHoChieu(this.hoChieuChinh.MaHoChieu);    //ăn gian...
            BS_LiteCAD.ShowNotifyAutoHide(elementHost1, "Xây dựng lưới lỗ khoan - hoàn thành");
        }

        private void MouseDownProc_GetFirstPoint(int hWnd, int Button, int Flags, int Xwin, int Ywin, double Xdrw, double Ydrw)
        {
            if(Button == Lcad.LC_LBUTTON)
            {
                xFirstPoint = Xdrw;
                yFirstPoint = Ydrw;
                _EventMouseDown_GetPoint = new F_MOUSEDOWN(MouseDownProc_GetLastPoint);
                Lcad.OnEventMouseDown(_EventMouseDown_GetPoint);
                //hiển thị thông báo
                UserControl_Notify note = new UserControl_Notify("Chọn điểm cuối");
                elementHost1.Child = note;
                note.ShowNotify();
            }
            else
            {
                //tắt thông báo
                UserControl_Notify note = elementHost1.Child as UserControl_Notify;
                note.HideNotify();
                Lcad.OnEventMouseDown(_EventMouseDown_Default);
            }   
        }
        private void MouseDownProc_GetLastPoint(int hWnd, int Button, int Flags, int Xwin, int Ywin, double Xdrw, double Ydrw)
        {
            if (Button == Lcad.LC_LBUTTON)
            {
                xLastPoint = Xdrw;
                yLastPoint = Ydrw;
                //ham tinh toan
                KhoanhVungLoKhoan();
                Lcad.OnEventMouseDown(_EventMouseDown_Default);
            }
            else
            {
                Lcad.OnEventMouseDown(_EventMouseDown_Default);
            }
            //tắt thông báo
            UserControl_Notify note = elementHost1.Child as UserControl_Notify;
            note.HideNotify();
        }
        private void MouseDownProc_Default(int hWnd, int Button, int Flags, int Xwin, int Ywin, double Xdrw, double Ydrw)
        { }

        //dựng lưới kích thước lỗ khoan - old
        private void DungLuoiKichThuoc_old()
        {
            int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
            Lcad.DrwAddTextStyle(hDrw, "Arial", "Arial");
            Lcad.PropPutStr(hDrw, Lcad.LC_PROP_DRW_TEXTSTYLE, "Arial");
            List<Circle> danhSachLoKhoan = mgCircles.GetListCircles();
            for (int i = 0; i < danhSachLoKhoan.Count - 1; i++)
            {
                for (int j = i + 1; j < danhSachLoKhoan.Count; j++)
                {
                    int newText = 0, newLine = 0;
                    if ((danhSachLoKhoan[i].GetX() == danhSachLoKhoan[j].GetX()) && (Math.Round(Math.Abs(danhSachLoKhoan[i].GetY() - danhSachLoKhoan[j].GetY())) == Math.Round(mgCircles.GetDeltaY())))
                    {
                        newText = Lcad.BlockAddTextWin2(hBlockModel, mgCircles.GetDeltaY().ToString(), ((danhSachLoKhoan[i].GetX() + danhSachLoKhoan[j].GetX()) / 2), ((danhSachLoKhoan[i].GetY() + danhSachLoKhoan[j].GetY()) / 2), Lcad.LC_TA_CENTER, 0.75, 1, 0, 0);
                        newLine = Lcad.BlockAddLine(hBlockModel, danhSachLoKhoan[i].GetX(), danhSachLoKhoan[i].GetY(), danhSachLoKhoan[j].GetX(), danhSachLoKhoan[j].GetY());                        
                    }
                    if ((danhSachLoKhoan[i].GetY() == danhSachLoKhoan[j].GetY()) && (Math.Round(Math.Abs(danhSachLoKhoan[i].GetX() - danhSachLoKhoan[j].GetX())) == Math.Round(mgCircles.GetDeltaX())))
                    {
                        newText = Lcad.BlockAddTextWin2(hBlockModel, mgCircles.GetDeltaX().ToString(), ((danhSachLoKhoan[i].GetX() + danhSachLoKhoan[j].GetX()) / 2), ((danhSachLoKhoan[i].GetY() + danhSachLoKhoan[j].GetY()) / 2), Lcad.LC_TA_CENTER, 0.75, 1, 0, 0);
                        newLine = Lcad.BlockAddLine(hBlockModel, danhSachLoKhoan[i].GetX(), danhSachLoKhoan[i].GetY(), danhSachLoKhoan[j].GetX(), danhSachLoKhoan[j].GetY());
                    }
                    Lcad.PropPutStr(newText, Lcad.LC_PROP_ENT_LAYER, "LuoiKichThuoc");
                    Lcad.PropPutStr(newLine, Lcad.LC_PROP_ENT_LAYER, "LuoiKichThuoc");
                }
            }
        }
        //dựng lưới kích thước lỗ khoan
        private void DungLuoiKichThuoc()
        {
            //xóa lớp lưới cũ
            Lcad.LayerClear(layerLuoiKichThuoc, Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL));
            List<Circle> danhSachLoKhoan = mgCircles.GetListCircles();
            for (int i = 0; i < danhSachLoKhoan.Count - 1; i++)
            {
                for(int j = i + 1; j < danhSachLoKhoan.Count; j++)
                {
                    double length = Math.Sqrt(Math.Pow((danhSachLoKhoan[i].GetX() - danhSachLoKhoan[j].GetX()), 2) + Math.Pow((danhSachLoKhoan[i].GetY() - danhSachLoKhoan[j].GetY()), 2));
                    if (Math.Round(length) == Math.Round(this.banVeChinh.DeltaX))
                    {
                        VeKhoangCach(danhSachLoKhoan[i], danhSachLoKhoan[j]);
                    }
                    else
                    {
                        if (Math.Round(length) == Math.Round(this.banVeChinh.DeltaY))
                        {
                            VeKhoangCach(danhSachLoKhoan[i], danhSachLoKhoan[j]);
                        }
                    }                   
                }
            }
            Lcad.DrwRegenViews(hDrw, 0);
            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
        }
        private void VeKhoangCach(Circle c1, Circle c2)
        {
            int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
            Lcad.DrwAddTextStyle(hDrw, "Arial", "Arial");
            Lcad.PropPutStr(hDrw, Lcad.LC_PROP_DRW_TEXTSTYLE, "Arial");
            int newText = 0, newLine = 0;
            newText = Lcad.BlockAddTextWin2(hBlockModel, this.banVeChinh.DeltaX.ToString(), ((c1.GetX() + c2.GetX()) / 2), ((c1.GetY() + c2.GetY()) / 2), Lcad.LC_TA_CENTER, 0.75, 1, 0, 0);
            newLine = Lcad.BlockAddLine(hBlockModel, c1.GetX(), c1.GetY(), c2.GetX(), c2.GetY());            
            Lcad.PropPutStr(newText, Lcad.LC_PROP_ENT_LAYER, "LuoiKichThuoc");
            Lcad.PropPutStr(newLine, Lcad.LC_PROP_ENT_LAYER, "LuoiKichThuoc");
        }

        //thêm hàng, cột
        private void AddColumnCircle()
        {
            if (mgCircles.GetListCircles().Count == 0)
            {
                BS_LiteCAD.ShowNotifyAutoHide(elementHost1, "Không có lỗ khoan");
            }
            else
            {
                List<Circle> listCircle = mgCircles.GetListCirleOfLastColumn();
                List<Circle> listNewCircle = new List<Circle>();
                int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
                Lcad.BlockUnselect(hBlockModel);
                //thêm cột lỗ khoan mới
                foreach (var circle in listCircle)
                {
                    int newHEnt = Lcad.BlockAddClone(hBlockModel, circle.GetHandle());
                    Lcad.BlockSelectEnt(hBlockModel, newHEnt, true);
                    Lcad.BlockSelMove(hBlockModel, mgCircles.GetDeltaX(), 0, false, true);
                    Lcad.BlockUnselect(hBlockModel);
                    listNewCircle.Add(new Circle(newHEnt));
                }
                mgCircles.AddListCircle(listNewCircle);
                //thêm lưới tọa độ
                if (this.banVeChinh.HienKhoangCach)  
                {
                    Lcad.LayerClear(layerLuoiKichThuoc, hBlockModel);
                    DungLuoiKichThuoc();
                }
                //load lại
                Lcad.DrwRegenViews(hDrw, 0);
                Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
            }
        }

        private void AddRowCircle()
        {
            if (mgCircles.GetListCircles().Count == 0)
            {
                BS_LiteCAD.ShowNotifyAutoHide(elementHost1, "Không có lỗ khoan");
            }
            else
            {
                List<Circle> listCircle = mgCircles.GetListCircleOfFirstRow();
                List<Circle> listNewCircle = new List<Circle>();
                int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
                Lcad.BlockUnselect(hBlockModel);
                //thêm hàng lỗ khoan mới
                foreach (var circle in listCircle)
                {
                    int newHEnt = Lcad.BlockAddClone(hBlockModel, circle.GetHandle());
                    Lcad.BlockSelectEnt(hBlockModel, newHEnt, true);
                    Lcad.BlockSelMove(hBlockModel, 0, mgCircles.GetDeltaY(), false, true);
                    Lcad.BlockUnselect(hBlockModel);
                    listNewCircle.Add(new Circle(newHEnt));
                }
                mgCircles.AddListCircle(listNewCircle);
                //thêm lưới tọa độ
                if (this.banVeChinh.HienKhoangCach)   
                {
                    Lcad.LayerClear(layerLuoiKichThuoc, hBlockModel);
                    DungLuoiKichThuoc();
                }
                //load lại
                Lcad.DrwRegenViews(hDrw, 0);
                Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
            }
        }

        //xóa hàng, cột
        private void DeleteColumnCircle()
        {
            if (mgCircles.GetListCircles().Count == 0)
            {
                BS_LiteCAD.ShowNotifyAutoHide(elementHost1, "Không có lỗ khoan");
            }
            else
            {
                List<Circle> listCircle = mgCircles.GetListCirleOfLastColumn();
                int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
                Lcad.BlockUnselect(hBlockModel);
                //xóa cột lỗ khoan mới
                mgCircles.RemoveListCircles(listCircle);
                foreach (var circle in listCircle)
                {
                    Lcad.BlockSelectEnt(hBlockModel, circle.GetHandle(), true);
                    Lcad.BlockSelErase(hBlockModel);
                    Lcad.BlockUnselect(hBlockModel);
                }
                //thêm lưới tọa độ
                if (this.banVeChinh.HienKhoangCach)   //sau them dk vao day
                {
                    Lcad.LayerClear(layerLuoiKichThuoc, hBlockModel);
                    DungLuoiKichThuoc();
                }
                //load lại
                Lcad.DrwRegenViews(hDrw, 0);
                Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
            }
        }
        private void DeleteRowCircle()
        {
            if (mgCircles.GetListCircles().Count == 0)
            {
                BS_LiteCAD.ShowNotifyAutoHide(elementHost1, "Không có lỗ khoan");
            }
            else
            {
                List<Circle> listCircle = mgCircles.GetListCircleOfFirstRow();
                int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
                Lcad.BlockUnselect(hBlockModel);
                //xóa hàng lỗ khoan mới
                mgCircles.RemoveListCircles(listCircle);
                foreach (var circle in listCircle)
                {
                    Lcad.BlockSelectEnt(hBlockModel, circle.GetHandle(), true);
                    Lcad.BlockSelErase(hBlockModel);
                    Lcad.BlockUnselect(hBlockModel);
                }
                //thêm lưới tọa độ
                if (this.banVeChinh.HienKhoangCach)   //sau them dk vao day
                {
                    Lcad.LayerClear(layerLuoiKichThuoc, hBlockModel);
                    DungLuoiKichThuoc();
                }
                //load lại
                Lcad.DrwRegenViews(hDrw, 0);
                Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
            }
        }

        //tính toán khoanh vùng
        private void KhoanhVungLoKhoan()
        {
            if (mgCircles.GetListCircles().Count == 0)
            {
                BS_LiteCAD.ShowNotifyAutoHide(elementHost1, "Không có lỗ khoan");
            }
            else
            {
                double xMax, xMin, yMax, yMin;
                if(xFirstPoint > xLastPoint)
                {
                    xMax = xFirstPoint;
                    xMin = xLastPoint;
                }
                else
                {
                    xMax = xLastPoint;
                    xMin = xFirstPoint;
                }
                if(yFirstPoint > yLastPoint)
                {
                    yMax = yFirstPoint;
                    yMin = yLastPoint;
                }
                else
                {
                    yMax = yLastPoint;
                    yMin = yFirstPoint;
                }
                List<Circle> listCircle = mgCircles.GetListCircles();
                List<Circle> listRemoveCircle = new List<Circle>();
                int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);
                foreach(Circle value in listCircle)
                {
                    if(value.GetX() > xMax || value.GetX() < xMin || value.GetY() > yMax || value.GetY() < yMin)
                    {
                        listRemoveCircle.Add(value);
                        Lcad.BlockSelectEnt(hBlockModel, value.GetHandle(), true);
                        Lcad.BlockSelErase(hBlockModel);
                        Lcad.BlockUnselect(hBlockModel);
                    }
                }
                //xóa danh sách nằm ngoài
                mgCircles.RemoveListCircles(listRemoveCircle);
                //vẽ lại lưới tọa độ
                if (this.banVeChinh.HienKhoangCach)   //sau them dk vao day
                {
                    Lcad.LayerClear(layerLuoiKichThuoc, hBlockModel);
                    DungLuoiKichThuoc();
                }
                //load lại
                Lcad.DrwRegenViews(hDrw, 0);
                Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_ZOOM_EXT, 0);
                SendKeys.Send("{ESC}");
            }
        }

        //hiện thông báo
        //private void ShowNotifyAutoHide(String text)
        //{
        //    UserControl_Notify note = new UserControl_Notify(text);
        //    elementHost1.Child = note;
        //    note.ShowNotifyAutoHide();
        //}
        
        //lấy danh sách lỗ khoan trên bản vẽ
        private void GetCirlcesFromAutocadFile()
        {
            int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);           
            int hEnt = Lcad.BlockGetFirstEnt(hBlockModel);           
            List<Circle> listCircles = new List<Circle>();
            while (hEnt != 0)
            {
                int entType = Lcad.PropGetInt(hEnt, Lcad.LC_PROP_ENT_TYPE);
                if (!Lcad.PropGetBool(hEnt, Lcad.LC_PROP_ENT_DELETED))   //kiểm tra xem ent bị xóa hay không
                {
                    if (entType == Lcad.LC_ENT_CIRCLE)
                    {
                        listCircles.Add(new Circle(hEnt));
                    }
                    //cách khác (dùng key, vì cái gì đấy mà ko lấy được LC_PROP_ENT_TYPE) - do thư viện....
                    else
                    {
                        int _key = Lcad.PropGetInt(hEnt, Lcad.LC_PROP_ENT_KEY);
                        if (_key == keyCircle)
                        {
                            listCircles.Add(new Circle(hEnt));
                        }

                    }
                }              
                hEnt = Lcad.BlockGetNextEnt(hBlockModel, hEnt);
            }
            mgCircles = new ManageCircle();
            mgCircles.AddListCircle(listCircles);
        }

        //test
        private void button1_Click(object sender, EventArgs e)
        {
            int hView = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_VIEW);
            Lcad.ViewRasterize(hView, @"E:\Sample1.bmp", 0, 0, 0, 0, 10);
        }
        //test
        //private void drawConnectLine(Circle start, Circle end, int type)
        //{
        //    int hBlockModel = Lcad.PropGetHandle(hDrw, Lcad.LC_PROP_DRW_BLOCK_MODEL);

        //    double Xcircle1 = start.GetX();
        //    double Ycircle1 = start.GetY();
        //    double Xcircle2 = end.GetX();
        //    double Ycircle2 = end.GetY();

        //    // neu lo khoan phia sau chua co "parent"
        //    if (end.HasParent() == false)
        //    {
        //        start.AddCirleChildren(end);
        //        end.SetCircleParent(start);

        //        int hBlock = Lcad.DrwAddBlock(hDrw, "Arrow" + nameOfBlock, 0, 0);
        //        int hPoint = Lcad.BlockAddPoint2(hBlock, Xcircle1, Ycircle1, Lcad.LC_PROP_POINT_MODE, 0.2);

        //        int hLine = Lcad.BlockAddLine(hBlock, Xcircle1, Ycircle1, Xcircle2, Ycircle2);
        //        double lenghLine = Lcad.PropGetFloat(hLine, Lcad.LC_PROP_LINE_LEN);

        //        int hPline = Lcad.BlockAddPolyline(hBlock, 0, true, true);
        //        Lcad.PlineAddVer(hPline, 0, Xcircle1 + lenghLine, Ycircle1);
        //        Lcad.PlineAddVer(hPline, 0, Xcircle1 - 0.5 + lenghLine, Ycircle1 + 0.5);
        //        Lcad.PlineAddVer(hPline, 0, Xcircle1 - 0.5 + lenghLine, Ycircle1 - 0.5);

        //        double anphal = 0;
        //        if (Ycircle1 <= Ycircle2)
        //            anphal = Math.Acos((Xcircle2 - Xcircle1) / lenghLine);
        //        else
        //            anphal = Math.PI * 2 - Math.Acos((Xcircle2 - Xcircle1) / lenghLine);

        //        switch (type)
        //        {
        //            case 1:
        //                {
        //                    int hLineAvg1 = Lcad.BlockAddLine(hBlock, Xcircle1 + lenghLine / 2, Ycircle1 - 0.5, Xcircle1 + lenghLine / 2, Ycircle1 + 0.5);
        //                    Lcad.BlockSelectEnt(hBlock, hLineAvg1, true);
        //                    break;
        //                }
        //            case 2:
        //                {
        //                    int hLineAvg1 = Lcad.BlockAddLine(hBlock, Xcircle1 + lenghLine / 2, Ycircle1 - 0.5, Xcircle1 + lenghLine / 2, Ycircle1 + 0.5);
        //                    int hLineAvg2 = Lcad.BlockAddLine(hBlock, Xcircle1 + 1 + lenghLine / 2, Ycircle1 - 0.5, Xcircle1 + 1 + lenghLine / 2, Ycircle1 + 0.5);
        //                    Lcad.BlockSelectEnt(hBlock, hLineAvg1, true);
        //                    Lcad.BlockSelectEnt(hBlock, hLineAvg2, true);
        //                    break;
        //                }
        //            default: { break; }
        //        }

        //        Lcad.BlockUnselect(hBlockModel);
        //        Lcad.BlockSelectEnt(hBlock, hPline, true);
        //        Lcad.BlockSelRotate(hBlock, Xcircle1, Ycircle1, anphal, false, false);
        //        Lcad.BlockUnselect(hBlock);

        //        int hBlockRef = Lcad.BlockAddBlockRef(hBlockModel, hBlock, 0, 0, 1, 0);
        //        nameOfBlock++;
        //        Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_REGEN, 0);

        //        //Connecting conn = new Connecting(start, end, type, hBlock, hBlockRef);
        //        //mgConnects.addConnecting(conn);
        //    }
        //    else // neu lo khoan phia sau da co "parent" roi
        //    {
        //        DialogResult dialogResult = MessageBox.Show("You sure about that", "Warning", MessageBoxButtons.YesNo);
        //        if (dialogResult == DialogResult.Yes)
        //        {
        //            //removeConnectLine(end);

        //            start.AddCirleChildren(end);
        //            end.SetCircleParent(start);

        //            int hBlock = Lcad.DrwAddBlock(hDrw, "Arrow" + nameOfBlock, 0, 0);
        //            int hPoint = Lcad.BlockAddPoint2(hBlock, Xcircle1, Ycircle1, Lcad.LC_PROP_POINT_MODE, 0.2);

        //            int hLine = Lcad.BlockAddLine(hBlock, Xcircle1, Ycircle1, Xcircle2, Ycircle2);
        //            double lenghLine = Lcad.PropGetFloat(hLine, Lcad.LC_PROP_LINE_LEN);

        //            int hPline = Lcad.BlockAddPolyline(hBlock, 0, true, true);
        //            Lcad.PlineAddVer(hPline, 0, Xcircle1 + lenghLine, Ycircle1);
        //            Lcad.PlineAddVer(hPline, 0, Xcircle1 - 0.5 + lenghLine, Ycircle1 + 0.5);
        //            Lcad.PlineAddVer(hPline, 0, Xcircle1 - 0.5 + lenghLine, Ycircle1 - 0.5);

        //            double anphal = 0;
        //            if (Ycircle1 <= Ycircle2)
        //                anphal = Math.Acos((Xcircle2 - Xcircle1) / lenghLine);
        //            else
        //                anphal = Math.PI * 2 - Math.Acos((Xcircle2 - Xcircle1) / lenghLine);

        //            switch (type)
        //            {
        //                case 1:
        //                    {
        //                        int hLineAvg1 = Lcad.BlockAddLine(hBlock, Xcircle1 + lenghLine / 2, Ycircle1 - 0.5, Xcircle1 + lenghLine / 2, Ycircle1 + 0.5);
        //                        Lcad.BlockSelectEnt(hBlock, hLineAvg1, true);
        //                        break;
        //                    }
        //                case 2:
        //                    {
        //                        int hLineAvg1 = Lcad.BlockAddLine(hBlock, Xcircle1 + lenghLine / 2, Ycircle1 - 0.5, Xcircle1 + lenghLine / 2, Ycircle1 + 0.5);
        //                        int hLineAvg2 = Lcad.BlockAddLine(hBlock, Xcircle1 + 1 + lenghLine / 2, Ycircle1 - 0.5, Xcircle1 + 1 + lenghLine / 2, Ycircle1 + 0.5);
        //                        Lcad.BlockSelectEnt(hBlock, hLineAvg1, true);
        //                        Lcad.BlockSelectEnt(hBlock, hLineAvg2, true);
        //                        break;
        //                    }
        //                default: { break; }
        //            }

        //            Lcad.BlockUnselect(hBlockModel);
        //            Lcad.BlockSelectEnt(hBlock, hPline, true);
        //            Lcad.BlockSelRotate(hBlock, Xcircle1, Ycircle1, anphal, false, false);
        //            Lcad.BlockUnselect(hBlock);

        //            int hBlockRef = Lcad.BlockAddBlockRef(hBlockModel, hBlock, 0, 0, 1, 0);
        //            nameOfBlock++;
        //            Lcad.WndExeCommand(hWnd, Lcad.LC_CMD_REGEN, 0);

        //            //Connecting conn = new Connecting(start, end, type, hBlock, hBlockRef);
        //            //mgConnects.addConnecting(conn);
        //        }
        //        else if (dialogResult == DialogResult.No)
        //        {
        //            //do something else
        //        }
        //    }
        //}
    }
}