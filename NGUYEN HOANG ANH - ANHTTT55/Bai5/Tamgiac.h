#include "Hinh.h"

class Tamgiac : public Hinh
{
private:
    string name = "Tam giac";
    double A;
    double B;
    double C;

public:
    Tamgiac();
    Tamgiac(double A, double B, double C);
    virtual void Nhap();

    double canhAB();
    double canhBC();
    double canhCA();
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

Tamgiac::Tamgiac()
{
    A = B = C = 0;
}
Tamgiac::Tamgiac(double A, double B, double C)
{
    this->A = A;
    this->B = B;
    this->C = C;
    setDienTich();
}
void Tamgiac::Nhap()
{
    cout << "Nhap canh AB : ";
    cin >> A;
    cout << "Nhap canh BC : ";
    cin >> B;
    cout << "Nhap canh CA : ";
    cin >> C;
    setDienTich();
}

double Tamgiac::canhAB()
{
    return A;
}
double Tamgiac::canhBC()
{
    return B;
}
double Tamgiac::canhCA()
{
    return C;
}

void Tamgiac::setDienTich()
{
    double p = (A + B + C) / 2;
    dientich = sqrt(p * (p + A) * (p + B) * (p + C));
}
void Tamgiac::Print()
{
    cout << "Tam giac AB =" << A << " : BC =" << B << " : CA = " << C << " | ";
    Hinh::Print();
}