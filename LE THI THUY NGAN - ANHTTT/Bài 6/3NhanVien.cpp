#include <iostream>
#include <string>
using namespace std;

class congNhanSanXuat
{
private:
    string hoTen;
    int tuoi;
    string gioiTinh;
    int soSanPham;
    
public:
    void Nhap();
    void Xuat();
    float Tinh_Tien_Luong();

    congNhanSanXuat();
    ~congNhanSanXuat();
};

void congNhanSanXuat::Nhap()
{
    cout << "\nNhap ho ten: ";
    cin >> hoTen;
    cout << "\nNhap tuoi: ";
    cin >> tuoi;
    cout << "\nNhap gioi tinh: ";
    cin >> gioiTinh;
    cout << "\nNhap so san pham lam trong thang: ";
    cin >> soSanPham;
    
}

void congNhanSanXuat::Xuat()
{
    cout << "\nHo ten: " << hoTen;
    cout << "\nTuoi: " << tuoi;
    cout << "\nGioi tinh: " << gioiTinh;
    cout << "\nSo san pham lam ra: " << soSanPham;
    cout << "\nTien luong thang: " << Tinh_Tien_Luong() << "\n";
}

float congNhanSanXuat::Tinh_Tien_Luong() {
    return soSanPham * 5000;
}

double Tong_Tien_Luong_CNSX(congNhanSanXuat ds[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ds[i].Tinh_Tien_Luong();
    }
    return sum;
}

congNhanSanXuat::congNhanSanXuat() {

}

congNhanSanXuat::~congNhanSanXuat() {

}

class congNhanHanhChinh
{
private:
    string hoTen;
    int tuoi;
    string gioiTinh;
    float heSoLuong;
public:
    void Nhap();
    void Xuat();
    float Tinh_Tien_Luong();

    congNhanHanhChinh();
    ~congNhanHanhChinh();
};

void congNhanHanhChinh::Nhap()
{
    cout << "\nNhap ho ten: ";
    cin >> hoTen;
    cout << "\nNhap tuoi: ";
    cin >> tuoi;
    cout << "\nNhap gioi tinh: ";
    cin >> gioiTinh;
    cout << "\nNhap he so luong: ";
    cin >> heSoLuong;
}

void congNhanHanhChinh::Xuat()
{
    cout << "\nHo ten: " << hoTen;
    cout << "\nTuoi: " << tuoi;
    cout << "\nGioi tinh: " << gioiTinh;
    cout << "\nHe so luong: " << heSoLuong;
    cout << "\nTien luong thang: " << Tinh_Tien_Luong() << "\n";
    
}

float congNhanHanhChinh::Tinh_Tien_Luong() {
    return heSoLuong * 1300;
}

double Tong_Tien_Luong_CNHC(congNhanHanhChinh ds[], int m) {
    double sum = 0;
    for (int i = 0; i < m; i++) {
        sum += ds[i].Tinh_Tien_Luong();
    }
    return sum;
}


congNhanHanhChinh::congNhanHanhChinh() {

}

congNhanHanhChinh::~congNhanHanhChinh() {

}

double min_CNSX(congNhanSanXuat ds[], int n) {
    int i;
    double min1 = ds[0].Tinh_Tien_Luong();
    for (i = 0; i < n; i++) {
        if (ds[i].Tinh_Tien_Luong() < ds[i - 1].Tinh_Tien_Luong()) {
            min1 = ds[i].Tinh_Tien_Luong();
        }
    }
    return min1;
}

double min_CNHC(congNhanHanhChinh ds[], int m) {
    int i;
    double min2 = ds[0].Tinh_Tien_Luong();
    for (i = 0; i < m; i++) {
        if (ds[i].Tinh_Tien_Luong() < ds[i - 1].Tinh_Tien_Luong()) {
            min2 = ds[i].Tinh_Tien_Luong();
        }
    }
    return min2;
}

void Menu(congNhanSanXuat ds_cn_sanxuat[], congNhanHanhChinh ds_cn_hanhchinh[], int n, int m)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t ============= CHUONG TRINH QUAN LY ======================";
        cout << "\n1. NHAP THONG TIN CONG NHAN SAN XUAT ";
        cout << "\n2. NHAP THONG TIN CONG NHAN HANH CHINH ";
        cout << "\n3. XUAT DANH SACH CONG NHAN SAN XUAT";
        cout << "\n4. XUAT DANH SACH CONG NHAN HANH CHINH ";
        cout << "\n5. TINH TONG LUONG CUA TAT CA CAC NHAN VIEN TRONG CONG TY ";
        cout << "\n6. MUC LUONG NHO NHAT TRONG CONG TY: ";

        cout << "\n\n\t\t ======================= END ===============================";
        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon < 0 && luachon > 5) {
             cout << "Nhap lai: ";
        }

        else if (luachon == 0) {
             break;
        }

        else if (luachon == 1)
        {
            congNhanSanXuat nv_sanxuat;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN SUA ONG NUOC\n";
            nv_sanxuat.Nhap();

            ds_cn_sanxuat[n] = nv_sanxuat;
            n++;
        }
        else if (luachon == 2)
        {
            congNhanHanhChinh cn_hanhchinh;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN HANH CHINH: \n";
            cn_hanhchinh.Nhap();

            ds_cn_hanhchinh[m] = cn_hanhchinh;
            m++;
        }

        else if (luachon == 3)
        {
            cout << "\n\n\t\t DANH SACH THONG TIN CONG NHAN SAN XUAT";
            for (int i = 0; i < n; i++) {
                cout << "\n\n\t\t THONG TIN CONG NHAN SAN XUAT THU " << i + 1;
                ds_cn_sanxuat[i].Xuat();
            }
            cout << "\n\nTONG TIEN LUONG CUA CAC NHAN VIEN SAN XUAT: " << Tong_Tien_Luong_CNSX(ds_cn_sanxuat, n) << "\n\n";
            system("pause");
        }

        else if (luachon == 4)
        {
            cout << "\n\n\t\t DANH SACH THONG TIN CONG NHAN HANH CHINH";
            for (int i = 0; i < m; i++) {
                cout << "\n\n\t\t THONG TIN CONG NHAN HANH CHINH THU " << i + 1;
                ds_cn_hanhchinh[i].Xuat();
            }
            cout << "\n\nTONG TIEN LUONG CUA CAC NHAN VIEN HANH CHINH: " << Tong_Tien_Luong_CNHC(ds_cn_hanhchinh, m) << "\n\n";
            system("pause");
        }
        else if (luachon == 5)
        {
            cout << "\n\nTONG TIEN LUONG CUA TAT CA CAC NHAN VIEN: " << Tong_Tien_Luong_CNHC(ds_cn_hanhchinh, m) + Tong_Tien_Luong_CNSX(ds_cn_sanxuat, n);
            system("pause");
        }

        else if (luachon == 6)
        {
            cout << "\n\nMUC LUONG NHO NHAT TRONG CONG TY LA:  " << (min_CNHC(ds_cn_hanhchinh, m) < min_CNSX(ds_cn_sanxuat, n) ? min_CNHC(ds_cn_hanhchinh, m) : min_CNSX(ds_cn_sanxuat, n)) <<"\n\n";
            system("pause");
        }
    }
}

int main()
{
    congNhanSanXuat ds_cn_sanxuat[100];
    congNhanHanhChinh ds_cn_hanhchinh[100];

    int n = 0;
    int m = 0;

    Menu(ds_cn_sanxuat, ds_cn_hanhchinh, n, m);

    system("pause");
    return 0;
}


