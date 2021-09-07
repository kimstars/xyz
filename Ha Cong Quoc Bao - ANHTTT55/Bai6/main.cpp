#include "Nhanvien.cpp" 
#include "Lamtheosp.cpp"

int main() {
    int nhanvien;
    int lamtheosp;
    
    Nhanvien n[1000];
    Lamtheosp l[1000];
    
    double thanhtien1 = 0;
    double thanhtien2 = 0;
    
    int x1 = 0;
    int x2 = 0;

    cout << "Co bao nhieu nhan vien: ";
    cin >> nhanvien;
    for(int i = 0; i < nhanvien; i++) {
        cout << "Nhap thong tin nguoi thu " << i + 1 << endl;
        n[i].set();
    }

    cout << "Co bao nhieu nguoi lam theo san pham: ";
    cin >> lamtheosp;
    for(int i = 0; i < lamtheosp; i++) {
        cout << "Nhap thong tin nguoi thu " << i + 1 << endl;
        l[i].set();
    }

    double luongmin1 = n[0].tinhtien1();
    cout << endl << "_______________________TINH TIEN CHO NHAN VIEN_____________________" << endl;
    cout << setw(5) << "STT";
    cout << setw(20) << "MA SO";
    cout << setw(30) << "HO TEN";
    cout << setw(20) << "NGAY SINH";
    cout << setw(20) << "HE SO LUONG";
    cout << setw(10) << "LUONG CB";
    cout << setw(20) << "THANH TIEN" << endl;
    for(int i = 0; i < nhanvien; i++) {
        cout << setw(5) << right << i + 1;
        n[i].get();
        thanhtien1 += n[i].tinhtien1();
        if (n[i].tinhtien1() < luongmin1) {
            luongmin1 = n[i].tinhtien1();
            x1 = i;
        }
    }
    cout << "==>> TONG: " << thanhtien1 << " VND" << endl;

    double luongmin2 = l[0].tinhtien2();
    cout << endl << "______________TINH TIEN CHO NGUOI LAM THEO SAN PHAM_______________" << endl;
    cout << setw(5) << "STT";
    cout << setw(20) << "MA SO";
    cout << setw(30) << "HO TEN";
    cout << setw(20) << "NGAY SINH";
    cout << setw(20) << "SO SAN PHAM";
    cout << setw(10) << "TIEN 1SP";
    cout << setw(20) << "THANH TIEN" << endl;
    for(int i = 0; i < lamtheosp; i++) {
        cout << setw(5) << right << i + 1;
        l[i].get();
        thanhtien2 += l[i].tinhtien2();
        if (l[i].tinhtien2() < luongmin2) {
            luongmin2 = l[i].tinhtien2();
            x2 = i;
        }
    }
    cout << "==>> TONG: " << thanhtien2 << " VND" << endl;
    cout << "===> TONG QUY LUONG CONG TY: " << thanhtien1 + thanhtien2 << " VND" << endl;

    if (luongmin1 < luongmin2) {
        cout << "Nguoi co luong thap nhat trong cong ty la: " << endl;
        n[x1].get();
    } else if(luongmin1 > luongmin2) {
        cout << "Nguoi co luong thap nhat trong cong ty la: " << endl;
        l[x2].get();
    } else {
        cout << "Nguoi co luong thap nhat trong cong ty la: " << endl;
        n[x1].get();
        l[x2].get();
    }
    return 0;
}