#include "Hinh.h"

#define Pi 3.14

class Tron : public Hinh
{
    private:
        string name = "Tron";
        double R;

    public:
        Tron();

        Tron(double R);

        void setDienTich();

        void Nhap();

        void Print();
        double getDienTich(){
            Hinh::getDienTich();
        }

        string getName(){
            return name;
        }

};
Tron::Tron()
{
    R = 0;
    setDienTich();
}

Tron::Tron(double R)
{
    this->R = R;
    setDienTich();

}

void Tron::setDienTich()
{
    dientich = Pi * pow(R, 2);
}

void Tron::Nhap()
{
    cout << "Nhap ban kinh: ";
    cin >> R;
    setDienTich();

}
void Tron::Print()
{

    cout << "Hinh tron: R =  " << R  << " | ";
    Hinh::Print();
}