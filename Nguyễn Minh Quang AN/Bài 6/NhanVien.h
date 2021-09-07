#pragma once
#include <bits/stdc++.h>
using namespace std;

class NhanVien
{
private:
    string name;

protected:
    double salary;

public:
    NhanVien();
    NhanVien(string name);
    virtual void Nhap();
    string getName();
    double GetSalary() { return salary; }
    virtual void SetSalary() = 0;

    virtual void Print()
    {
        cout << left << setw(30) << name << setw(30) << fixed << salary << endl;
    }
};

NhanVien::NhanVien()
{
    name = "";
}
NhanVien::NhanVien(string name)
{
    this->name = name;
}
void NhanVien::Nhap()
{
    cout << "Nhap ten nhan vien: ";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, name);
}
string NhanVien::getName()
{
    return name;
}