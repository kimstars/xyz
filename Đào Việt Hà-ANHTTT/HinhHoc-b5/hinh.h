#include<iostream>
#include<vector>

using namespace std;
class htron {
protected:
	int n1;
	float bk[100];
	float dt1[100];
	float max1;
public:
	htron() {
		this->n1 = 0;
		this->bk[100] = 0;
		this->dt1[100] = 0;
		this->max1 = 0;
	}
	void nhap() {
		cout << "Nhap so hinh tron: ";
		cin >> this->n1;
		this->bk[this->n1];
		this->dt1[this->n1];
		for (int i = 0; i < this->n1; i++) {
			cout << "Nhap bk thu " << i + 1<<": ";
			cin >> this->bk[i];
		}
		
	}
	void xuat() {
		for (int i = 0; i < this->n1; i++) {
			this->dt1[i] = this->bk[i] * this->bk[i] * 3.14;
			cout << "Dien tich hinh tron thu " << i + 1<< " voi bk = "<< this->bk[i]<< ": ";
			cout << this->dt1[i]<<endl;
		}
	}
	void maxDt1() {
		int dem1 = 0;
		for (int i = 0; i < this->n1; i++) {
			if (this->max1 == this->dt1[i]) {
				dem1 = i;
			}
		}
		cout << "Hinh tron co dien tich lon nhat voi bk = " << this->bk[dem1] << " la: " << this->max1;
	}
	float maxhtron() {
		for (int i = 0; i < this->n1; i++) {
			if (this->max1 <= this->dt1[i]) {
				this->max1 = this->dt1[i];
			}
		}
		return this->max1;
	}
};

class hcn {
protected:
	int n2;
	float cd[100], cr[100] ;
	float dt2[100];
	float max2;
public:
	hcn() {
		this->n2 = 0;
		this->cd[100] = 0;
		this->cr[100] = 0;
		this->dt2[100] = 0;
		this->max2 = 0;
	}
	void nhap() {
		cout << "Nhap so hinh CN: ";
		cin >> this->n2;
		this->cd[this->n2];
		this->cr[this->n2];
		this->dt2[this->n2];
		for (int i = 0; i < this->n2; i++) {
			cout << "Nhap chieu dai, chieu rong thu " << i + 1 << ": ";
			cin >> this->cd[i]>> this->cr[i];
		}

	}
	void xuat() {
		for (int i = 0; i < this->n2; i++) {
			this->dt2[i] = this->cd[i] * this->cr[i];
			cout << "Dien tich hinh CN thu " << i + 1 << " voi cd = " << this->cd[i] << ", cr = "<<this->cr[i]<<": ";
			cout << this->dt2[i] << endl;
		}
	}
	void maxDt2() {
		int dem2 = 0;
		for (int i = 0; i < this->n2; i++) {
			if (this->max2 == this->dt2[i]) {
				dem2 = i;
			}
		}
		cout << "HCN co dien tich lon nhat voi cd = " << this->cd[dem2] << " cr = " << this->cr[dem2] << " la: "<<this->max2;
	}
	float maxhcn() {
		for (int i = 0; i < this->n2; i++) {
			if (this->max2 <= this->dt2[i]) {
				this->max2 = this->dt2[i];
			}
		}
		return this->max2;
	}
};


class htamgiac {
protected:
	int n3;
	float c[100], d[100];
	float dt3[100];
	float max3;
public:
	htamgiac() {
		this->n3 = 0;
		this->c[100] = this->d[100] = 0;
		this->dt3[100] = 0;
		this->max3 = 0;
	}
	void nhap() {
		cout << "Nhap so hinh tam giac: ";
		cin >> this->n3;
		this->c[this->n3];
		this->d[this->n3];
		this->dt3[this->n3];
		for (int i = 0; i < this->n3; i++) {
			cout << "Nhap canh day, chieu cao thu " << i + 1 << ": ";
			cin >> this->c[i]>> this->d[i];
		}

	}
	void xuat() {
		for (int i = 0; i < this->n3; i++) {
			this->dt3[i] = (this->c[i]) * (this->d[i]) / 2.0;
			cout << "Dien tich hinh tam giac thu " << i + 1 << " voi c = " << this->c[i] <<"va d = "<< this->d[i]<< ": ";
			cout << this->dt3[i] << endl;
		}
	}
	void maxDt3() {
		int dem3 = 0;
		for (int i = 0; i < this->n3; i++) {
			if (this->max3 == this->dt3[i]) {
				dem3 = i;
			}
		}
		cout << "Hinh tam giac co dien tich lon nhat voi c = " << this->c[dem3] << " d = " << this->d[dem3] << " la: " << this->max3;
	}
	float maxhtg() {
		for (int i = 0; i < this->n3; i++) {
			if (this->max3 <= this->dt3[i]) {
				this->max3 = this->dt3[i];
			}
		}
		return this->max3;
	}
};

class hinh: public htron, hcn, htamgiac {
protected:
	htron* htr;
	hcn* cn;
	htamgiac* tg;
public:
	void dientichMax() {
		/*float m[3] = {htr->maxhtron(), cn->maxhcn(), tg->maxhtg()};
		float result = 0;
		int dem = 0;
		for (int i = 0; i < 3; i++) {
			if (result <= m[i] ) {
				result = m[i];
				dem = i;
			}
		}
		cout << "Hinh co dien tich lon nhat: " << result<<endl;
		if (dem == 0) htr->maxDt1();
		else if (dem == 1) cn->maxDt2();
		else tg->maxDt3();
		*/
	}
};