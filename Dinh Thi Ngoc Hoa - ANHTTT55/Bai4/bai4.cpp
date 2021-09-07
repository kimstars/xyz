//chon do vat

#include<iostream>

using namespace std;

struct DoVat {
	float trongLuong, giaTri, donGia;
	int phuongAn;
};

void tinhDonGia(DoVat sp[], int n) {
	for (int i=0; i<n; i++) {
		sp[i].donGia = sp[i].giaTri / sp[i].trongLuong;
	}
}

void sapXep(DoVat sp[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if (sp[i].donGia < sp[j].donGia)
				swap(sp[i], sp[j]);
		}
	}
}

void layVat(DoVat sp[], int n, float W) {
	int tonggt = 0;
	for (int i = 0; i < n; i++) {
        if (W >= sp[i].trongLuong) {
        	sp[i].phuongAn = 1;
        	W -= sp[i].trongLuong;
        	tonggt += sp[i].giaTri;
    	}
	}
	cout << "===> Lay cac vat co trong luong sau: " << endl;
	cout << "  Vat thu " << "- Trong luong" << endl;
	for (int i = 0; i < n; i++) {
		if (sp[i].phuongAn != 0) {
			cout << "\t" << i+1 << "  \t";
			cout << sp[i].trongLuong << endl; 
		}
	}
	cout << "Tong gia tri dat duoc la: " << tonggt;
}

int main()
{
	int n, W;
	cout << "So do vat: ";
	cin >> n;
	cout << "Trong luong toi da: " ;
	cin >> W;
	
	cout << "Trong luong va gia tri cac do vat: " << endl;
	struct DoVat a[10000];
	for (int i=0; i<n; i++) {
		cout << "- Vat thu " << i+1 << endl;
		cin >> a[i].trongLuong;
		cin >> a[i].giaTri;
	}
	
	tinhDonGia(a, n);
	sapXep(a, n);
	layVat(a, n, W);
	
 	return 0;
}
