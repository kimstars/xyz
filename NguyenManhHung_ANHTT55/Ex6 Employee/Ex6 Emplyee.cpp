/*
	Câu 6. Trong một cty có n nhân công, công nhân sản xuất = 5000d * số lượng sp trong tháng đó
công nhân hành chính = hệ số lương * 1300
+ Xây dựng lớp mô tả lại lưu trữ dữ liệu cho cty đó
+ Tìm người có mức lương nhỏ nhất trong cty
+ Tính tổng mức lương phải chi trả trong tháng

*/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Salary {
public:
	virtual double salary() = 0;
};

class CongNhanSX : public Salary {
private:
	string name;
	string id;
	int soLuongSP;
public:
	CongNhanSX() {}
	CongNhanSX(string name, string id, int soLuongSP) : name(name), id(id), soLuongSP(soLuongSP) {}
	double salary() {
		return 5000 * soLuongSP;
	}
	string getName() {
		return this->name;
	}
	static long getSalary1(vector<CongNhanSX> vt) {
		long min1 = vt[0].salary();
		vector<CongNhanSX> v;
		for (int i = 1; i < vt.size(); i++) {
			if (vt[i].salary() < min1) {
				min1 = vt[i].salary();
			}
		}
		return min1;
	}
	static long getSumSalary1(vector<CongNhanSX> vt) {
		long sum = 0;
		for (int i = 0; i < vt.size(); i++) {
			sum += vt[i].salary();
		}
		return sum;
	}
};

class NguoiHanhChinh : public Salary {
private:
	string name;
	string id;
	double heSoLuongCB;
public:
	NguoiHanhChinh(string name, string id, double heSoLuongCB) : name(name), id(id), heSoLuongCB(heSoLuongCB) {}
	string getName() {
		return this->name;
	}
	double salary() {
		return 1300000 * heSoLuongCB;
	}

	static long getSalary2(vector<NguoiHanhChinh> vt) {
		long min2 = vt[0].salary();
		for (int i = 1; i < vt.size(); i++) {
			if (vt[i].salary() < min2) {
				min2 = vt[i].salary();
			}
		}
		return min2;
	}
	static long getSumSalary2(vector<NguoiHanhChinh> vt) {
		long sum = 0;
		for (int i = 0; i < vt.size(); i++) {
			sum += vt[i].salary();
		}
		return sum;
	}
};

void fillVectorCongNhanSX(vector<CongNhanSX>&);
void fillVectorNguoiHanhChinh(vector<NguoiHanhChinh>&);

int main() {

	vector<CongNhanSX> sx;
	vector<NguoiHanhChinh> hc;
	fillVectorCongNhanSX(sx);
	fillVectorNguoiHanhChinh(hc);
	
	long a = CongNhanSX::getSalary1(sx);
	long b = NguoiHanhChinh::getSalary2(hc);
	if (a < b) {
		for (int i = 0; i < sx.size(); i++) {
			if (sx[i].salary() == a) {
				cout << "Nguoi co muc luong nho nhat la Cong nhan san xuat: ";
				cout << sx[i].getName() << " voi " << a << " vnd" << endl;
			}
		}
	}
	else {
		for (int i = 0; i < hc.size(); i++) {
			if (hc[i].salary() == b) {
				cout << "Nguoi co muc luong nho nhat la Nguoi hanh chinh: ";
				cout << hc[i].getName() << " voi " << b << " vnd" << endl;
			}
		}
	}
	
	long x = CongNhanSX::getSumSalary1(sx);
	long y = NguoiHanhChinh::getSumSalary2(hc);
	cout << "Tong tien luong cong ty phai tra moi thang la: " << x + y << " vnd " << endl;
}


void fillVectorCongNhanSX(vector<CongNhanSX>& congnhanSX) {
	string name;
	string id;
	int soLuongSP;

	cout << "Nhap so luong cong nhan san xuat: ";
	int n1;
	cin >> n1;

	for (int i = 0; i < n1; i++) {
		cout << "-----Cong nhan thu " << i + 1 << "-----" << endl;
		cout << "Ten: ";
		cin >> name;
		cout << "ID: ";
		cin >> id;
		cout << "So luong san pham: ";
		cin >> soLuongSP;

		CongNhanSX newCongNhanSX(name, id, soLuongSP);
		congnhanSX.push_back(newCongNhanSX);
		cout << endl;
	}
	cout << endl;
}

void fillVectorNguoiHanhChinh(vector<NguoiHanhChinh>& hanhchinh) {
	string name;
	string id;
	double heSoLuongCB;

	cout << "Nhap so luong nguoi hanh chinh: ";
	int n2;
	cin >> n2;

	for (int i = 0; i < n2; i++) {
		cout << "---------Nguoi hanh chinh thu " << i + 1 << "--------" << endl;
		cout << "Ten: ";
		cin >> name;
		cout << "Id: ";
		cin >> id;
		cout << "He so luong CB: ";
		cin >> heSoLuongCB;

		NguoiHanhChinh newNguoiHanhChinh(name, id, heSoLuongCB);
		hanhchinh.push_back(newNguoiHanhChinh);
		cout << endl;
	}
	cout << endl;
}
