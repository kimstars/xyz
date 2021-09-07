#ifndef HANHCHINH_H
#define HANHCHINH_H

#include "NhanVien.h"
#include <bits/stdc++.h>
using namespace std;

class HanhChinh : public NhanVien {
	private:
		double BaseSalary; // he so luong
	
	public:
		HanhChinh();
		HanhChinh(string name, double BaseSalary);
		virtual void Nhap();
		double getBaseSalary();
		
		virtual void setSalary();
		
		virtual void Print() {
			cout << left << setw(15) << "Hanh chinh ";
			NhanVien::Print();
		}
		
};

HanhChinh::HanhChinh() : NhanVien() {
	BaseSalary = 0;
}

HanhChinh::HanhChinh(string name, double BaseSalary) : NhanVien(name) {
	this->BaseSalary = BaseSalary;
}

void HanhChinh::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap he so luong: ";
	cin >> this->BaseSalary;
	setSalary();
}

double HanhChinh::getBaseSalary() {
	return BaseSalary;
}

void HanhChinh::setSalary() {
	salary = 13000 * BaseSalary;
}

#endif

