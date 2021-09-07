#ifndef SANXUAT_H
#define SANXUAT_H

#include "NhanVien.h"
#include <bits/stdc++.h>
using namespace std;

class SanXuat : public NhanVien {
	private:
		int Soluongsp;
	
	public:
		SanXuat();
		SanXuat(string name, int soluong);
		virtual void Nhap();
		int getSoluong();
		virtual void setSalary();
		
		virtual void Print() {
			cout << left << setw(15) << "San xuat ";
			NhanVien::Print();
		}
};


SanXuat::SanXuat() {
	Soluongsp = 0;
}

void SanXuat::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so luong san pham nhan vien lam ra: ";
	cin >> this->Soluongsp;
	setSalary();
}

void SanXuat::setSalary() {
	salary = Soluongsp * 5000;
}

int SanXuat::getSoluong() {
	return Soluongsp;
}

#endif

