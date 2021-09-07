#pragma once
#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

#include "Date.cpp"  

class Nguoi {
private:
    string maso;
    string ten;
    Date ngaysinh;
public:
    void set() {
        cout << "Nhap ma so: ";
        fflush(stdin);
        getline(cin, maso);
        cout << "Nhap ten: ";
        fflush(stdin);
        getline(cin, ten);
        ngaysinh.set();        
    }

    void get() {
        cout << setw(20) << right << this->maso;
        cout << setw(30) << right << this->ten;
        ngaysinh.get();

    }
};
