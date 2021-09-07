#include "Hinh.h"

class HCN : public Hinh
{
private:
    double ChieuDai;
    double ChieuRong;
    const string name = "Hinh chu nhat";

public:
    HCN();
    HCN(int x, int y);
    void show();
    void Nhap();
    virtual void setDienTich();
    void Print();
    double getDienTich()
    {
        Hinh::getDienTich();
    }
    string getName()
    {
        return name;
    }
};

HCN::HCN()
{
    ChieuDai = ChieuRong = 0;
}
HCN::HCN(int x, int y)
{
    this->ChieuDai = x;
    this->ChieuRong = y;
    setDienTich();
}

void HCN::show()
{
    cout << "Chieu dai : " << ChieuDai << endl;
    cout << "Chieu rong: " << ChieuRong << endl;
}

void HCN::Nhap()
{
    cout << "Nhap chieu dai : ";
    cin >> this->ChieuDai;
    cout << "Nhap chieu rong : ";
    cin >> this->ChieuRong;
    setDienTich();
}

void HCN::setDienTich()
{
    dientich = this->ChieuDai * this->ChieuRong;
}

void HCN::Print()
{
    cout << "Hinh chu nhat : " << ChieuDai << " : " << ChieuRong << " | ";
    Hinh::Print();
}