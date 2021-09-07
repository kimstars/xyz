#include <bits/stdc++.h>
#pragma once
#define MAX 1000

using namespace std;

class goiHang
{
public:
    string tenHang;
    long canNang;
    long giaTri;

public:
goiHang(){
    tenHang = "";
    canNang = giaTri = 0;
}
    // goiHang(string tenHang, long canNang, long giaTri) : tenHang(tenHang), canNang(canNang), giaTri(giaTri){};
    void Nhap();
    void setTenHang(string);
    string getTenHang();
    void setCanNang(long);
    long getCanNang();
    void setGiaTri(long);
    long getGiaTri();
};

void goiHang::Nhap()
{
    cout << "Ten loai hang: ";
    cin >> tenHang;
    cout << "Can nang cua loai hang: ";
    cin >> canNang;
    cout << "Gia tri cua loai hang: ";
    cin >> giaTri;
}

void goiHang::setTenHang(string tenHang)
{
    this->tenHang = tenHang;
}
string goiHang::getTenHang()
{
    return tenHang;
}
void goiHang::setCanNang(long canNang)
{
    this->canNang = canNang;
}
long goiHang::getCanNang()
{
    return canNang;
}
void goiHang::setGiaTri(long giaTri)
{
    this->giaTri = giaTri;
}
long goiHang::getGiaTri()
{
    return giaTri;
}