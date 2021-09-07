
#include<iostream>
#include<math.h>
using namespace std;

typedef struct Vat {
	float trongluong, giaTri, dongia;
	int method;
};

void donGia( int n, Vat v[]) {
	for (int i = 0; i < n; i++) {
		v[i].dongia = v[i].giaTri / v[i].trongluong;
	}
}

void sapXep(Vat v[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i].dongia < v[j].dongia)
				Vat temp = v[i];
				v[i] = v[j];
				v[j] = temp;
		}
	}
}

void chonDovat(Vat v[], float P, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (P >= v[i].trongLuong) {
			v[i].method = 1;
			sum += v[i].giaTri;
			P -= v[i].trongLuong;
		}
	}
	cout << " Chon cac vat co trong luong sau: " << endl;
	//cout << "  Do vat chon " << "     Trong luong cua vat" << endl;
	for (int i = 0; i < n; i++) {
		if (sp[i].method != 0) {
			cout << "STT: " << i + 1 << "   ";
			cout << "Vat co trong luong (P): " <<sp[i].trongLuong << endl;
		}
	}
	cout << "Tong gia tri duoc la: " << sum;
}

int main()
{
	int n, P;
	cout << "Nhap So do vat: "<<endl;
	cin >> n;
	cout << "Trong luong MAX: "<<endl;
	cin >> P;

	cout << "Trong luong , gia tri cac do vat la : " << endl;
	struct Vat a[1000];
	for (int i = 0; i < n; i++) {
		cout << "STT : " << i + 1 << endl;
		cin >> a[i].trongLuong;
		cin >> a[i].giaTri;
	}

	cout<<"Tinh don gia cua vat:"<<endl;
	donGia(n,a);
	cout<<"Tien hanh sx:"<<endl;
	sapXep(a, n);
	cout<<"Chon do vat: "<<endl;

	chonDovat(a, P,n);

	return 0;
}
