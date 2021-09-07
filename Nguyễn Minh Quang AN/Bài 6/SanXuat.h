#include "Nhanvien.h"

class SanXuat : public NhanVien
{
private:
    int Soluongsp; // số lượng sản phẩm làm ra
public:
    SanXuat();
    SanXuat(string name, int soluong);
    virtual void Nhap();
    int getSoluong();
    virtual void SetSalary();

    virtual void Print()
    {
        cout << left << setw(15) <<  "San xuat ";
        NhanVien::Print();
    }

};


SanXuat::SanXuat()
{
    Soluongsp = 0;
}
SanXuat::SanXuat(string name, int soluong) : NhanVien(name)
{
    this->Soluongsp = soluong;
}
void SanXuat::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap So luong san pham nhan vien lam ra : ";
    cin >> this->Soluongsp;
    SetSalary();
}


void SanXuat::SetSalary(){
    salary = Soluongsp*5000;
}

int SanXuat::getSoluong()
{
    return Soluongsp;
}