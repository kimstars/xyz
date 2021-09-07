#include <iostream>
#pragma once
#define MAX 1000
using namespace std;

class monHang
{
public:
    string tenHang;
    int canNang;
    int giaTri;

public:
    void setTenHang(string);
    string getTenHang();
    void setCanNang(int);
    int getCanNang();
    void setGiaTri(int);
    int getGiaTri();
};

void monHang::setTenHang(string tenHang)
{
    this->tenHang = tenHang;
}
string monHang::getTenHang()
{
    return tenHang;
}
void monHang::setCanNang(int canNang)
{
    this->canNang = canNang;
}
int monHang::getCanNang()
{
    return canNang;
}
void monHang::setGiaTri(int giaTri)
{
    this->giaTri = giaTri;
}
int monHang::getGiaTri()
{
    return giaTri;
}