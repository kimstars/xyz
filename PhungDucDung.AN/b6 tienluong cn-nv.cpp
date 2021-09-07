#include<iostream>
#include<math.h>
using namespace std;

class NhanCong{
	protected:
		double tienluong;
	public:
		NhanCong();
		~NhanCong();
		void nhapLuong();
		void setLuong();
		void printLuong();
		double getLuong();	
};
NhanCong::NhanCong(){
	
}
NhanCong::~NhanCong(){
	
}
double NhanCong::getLuong(){
	return tienluong;
}
void NhanCong::printLuong(){
	cout<<this->tienluong<<endl;
}
//lop Nhan vien ke thua

class NhanVien: public NhanCong{
	private:
		double hesoluong;
		string name;
	public:
		NhanVien();
		NhanVien(double h,string n);
		void nhapLuong();
		void setLuong();
		void printLuong();
		double getLuong(){
			NhanCong::getLuong();
		}	
};
NhanVien::NhanVien(){
	
}
NhanVien::NhanVien(double h, string n){
	this->hesoluong=h;
	this->name=n;
	setLuong();
}
void NhanVien::nhapLuong(){
	cout<<"\nNhap ten nhan vien: ";
	fflush(stdin);
	getline(cin, name);
	cout<<"Nhap he so luong co ban: ";
	cin>>hesoluong;
	setLuong();
}
void NhanVien::setLuong(){
	tienluong=this->hesoluong*1300;
}
void NhanVien::printLuong(){
	cout<<"Tien luong co ban cua nhan vien la(don vi: 1000 dong): ";
	NhanCong::printLuong();
}

//lop Cong nhan ke thua
class CongNhan: public NhanCong{
	private:
		string name1;
		double soSanPham;
	public:
		CongNhan();
		CongNhan(double s, string n1);
		void nhapLuong();
		void setLuong();
		double getLuong(){
			NhanCong::getLuong();
		}
		void printLuong();
			
};
CongNhan::CongNhan(){
	
}
CongNhan::CongNhan(double s, string n1 ){
	this->soSanPham=s;
	this->name1=n1;
	setLuong();
}
void CongNhan::nhapLuong(){
	cout<<"\nNhap ten cong nhan: ";
	cin>>name1;
	cout<<"Nhap so san pham binh quan: ";
	cin>>soSanPham;
	setLuong();
}
void CongNhan::setLuong(){
	tienluong=this->soSanPham*5;
	
}
void CongNhan::printLuong(){
	cout<<"Tien luong co ban cua cong nhan(don vi: 1000 dong) la: ";
	NhanCong::printLuong();
}


int main(){
	//nhap thong tin
	NhanVien a[100];
	CongNhan b[100];
	int x,y;
	cout<<"Nhap so nhan vien: ";
	cin>>x;
	for(int i=0; i<x; i++){ //arr Nhanvien
		a[i].nhapLuong();
		a[i].setLuong();
		a[i].printLuong();
	}
	//tim min luong NV
	double minNV= a[0].getLuong();
	for(int i=0; i<x; i++){
		if(a[i].getLuong()<minNV){
			minNV=a[i].getLuong();
		}	
	}
	cout<<"\nTien luong nho nhat cua 1 nhan vien(don vi: 1000 dong) la: "<<minNV<<endl;

	cout<<"\nNhap so cong nhan: ";
	cin>>y;
	for(int i=0;i<y;i++){ //arr Cong nhan
		
		b[i].nhapLuong();
		b[i].setLuong();
		b[i].printLuong();
		
	}
	//tim min luong CN
	double minCN= b[0].getLuong();
	for(int i=0;i<y;i++){
		if(b[i].getLuong()<minCN){
			minCN=b[0].getLuong();
		}
	}
	cout<<"Tien luong nho nhat cua 1 cong nhan(don vi: 1000 dong) la: "<<minCN<<endl;
	//so sanh 2 min luong nho nhat
	if(minCN>minNV){
		
		cout<<"\nNguoi huong luong nho nhat trong cong ty: "<<minNV<<endl;	
	}
	else
		cout<<"\nNguoi huong luong nho nhat trong cong ty: "<<minCN<<endl;	
	//tinh tong luong arrNV
	double sumNV=0;
	for(int i=0;i<x;i++){
		sumNV+=a[i].getLuong();
	}
	cout<<"\nTong luong cong ty da chi tra cho "<<x<<" nhanvien(don vi: 1000 dong) la:"<<sumNV<<endl;	
	//tinh tong luong arrCN
	double sumCN=0;
	for(int i=0;i<y;i++){
		sumCN+=b[i].getLuong();
	}
	cout<<"\nTong luong cong ty da chi tra cho "<<y<<" cong nhan (don vi: 1000 dong) la:"<<sumCN<<endl;	
	//tong thiet hai 1 thang cua cty
	cout<<"\nSo tien phai tra "<<x+y<<" nhan cong cua ho trong 1 thang(30 ngay) (don vi 1000 dong): "<<(sumCN+sumNV)*30;
	
	
}
