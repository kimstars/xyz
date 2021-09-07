#include "Nhanvien.h"

class HanhChinh : public NhanVien
{
private:
    double BaseSalary; // hệ số lương
public:
    HanhChinh();
    HanhChinh(string name, double BaseSalary);
    virtual void Nhap();
    double getHSluong();

    virtual void SetSalary();

    virtual void Print()
    {
        cout << left << setw(15) << "Hanh chinh ";
        NhanVien::Print();
    }
};

HanhChinh::HanhChinh() : NhanVien()
{
    BaseSalary = 0;
}
HanhChinh::HanhChinh(string name, double BaseSalary) : NhanVien(name)
{
    this->BaseSalary = BaseSalary;
}

void HanhChinh::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap he so luong : ";
    cin >> this->BaseSalary;
    SetSalary();
}

double HanhChinh::getHSluong()
{
    return BaseSalary;
}

void HanhChinh::SetSalary()
{
    salary = 130000 * BaseSalary;
};
