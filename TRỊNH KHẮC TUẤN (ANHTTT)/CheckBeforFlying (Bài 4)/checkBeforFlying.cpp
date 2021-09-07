#include "quanly.h"

int main()
{
    int soLoaiHang; //so doi tuong
    int sM;
    //nhap so loai hang
    cout << "So loai hang mang theo: ";
    cin >> soLoaiHang;
    cout << "Can nang toi da cho phep: ";
    cin >> sM;
    monHang *hangs = new monHang[soLoaiHang]; //cap phat bo nho cho mang doi tuong
    //khoi tao cac doi tuong trong mang
    for (int i = 0; i < soLoaiHang; i++)
    {
        string tenHang;
        int canNang;
        int giaTri;
        cout << "Nhap hang thu "<<i+1 <<endl;
        // cout << "Ten loai hang: ";
        // cin >> tenHang;
        // hangs[i].setTenHang(tenHang);
        cout << "Can nang cua loai hang: ";
        cin >> canNang;
        hangs[i].setCanNang(canNang);
        cout << "Gia tri cua loai hang: ";
        cin >> giaTri;
        hangs[i].setGiaTri(giaTri);
    }
    
    quanLi q;
    q.setHang(hangs);
    cout << "Tong can nang hang duoc chon:\n";
    cout << q.chonHang(soLoaiHang,sM);

    return 0;
}
