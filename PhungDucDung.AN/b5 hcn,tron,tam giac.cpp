#include<iostream>
#include<math.h>
using namespace std;

class DaGiac{
	protected:
		float dientich;
	public:
		DaGiac();
		~DaGiac();
		void nhapDT();
		void setDT();
		float getDT();
		void printDT();
};
DaGiac::DaGiac(){
	
}
DaGiac::~DaGiac(){
	
}
float DaGiac::getDT(){
	return dientich;
}
void DaGiac::printDT(){
	cout<<this->dientich<<endl;
}
//lop Chu nhat
class ChuNhat: public DaGiac{
	private:
		int chieudai;
		int chieurong;
	public:
		ChuNhat();
		ChuNhat(int x,int y);
		void nhapDT();
		 void setDT();
		float getDT(){
			DaGiac::getDT();
		}
		void printDT();	
};
ChuNhat::ChuNhat(){
	
}
ChuNhat::ChuNhat(int x, int y){
	this->chieudai=x;
	this->chieurong=y;
	setDT();
}
void ChuNhat::nhapDT(){
	cout<<"Nhap chieu dai: ";
	cin>>chieudai;
	cout<<"Nhap chieu rong: ";
	cin>>chieurong;
	setDT();
}
void ChuNhat::setDT(){
	dientich=this->chieudai *this->chieurong;
}
void ChuNhat::printDT(){
	cout<<"Dien tich hinh chu nhat: ";
	DaGiac::printDT();
}
//lop tam giac
class TamGiac: public DaGiac{
	private:
		float a,b,c;
	public:
		TamGiac();
		TamGiac(float A,float B, float C);

		void nhapDT();
		void setDT();
		void printDT();
		float getDT(){
			DaGiac::getDT();
		}		
};
TamGiac::TamGiac(){
	
}

TamGiac::TamGiac(float A, float B, float C){
	this->a=A;
	this->b=B;
	this->c=C;
	setDT();
}
void TamGiac::nhapDT(){
	do{
		cout<<"Nhap canh a: ";
		cin>>a;
		cout<<"Nhap canh b: ";
		cin>>b;
		cout<<"Nhap canh c: ";
		cin>>c;
			if(a+b<=c || b+c<=a || c+a<=b){
				cout<<"Kiem tra lai dieu kien tam giac!"<<endl;
			}
	}
	while(a+b<=c || b+c<=a || c+a<=b);
	setDT();
	
}
void TamGiac::setDT(){
	float p=(this->a+this->b+this->c)/2;
	float area=sqrt(p*(p-this->a)*(p-this->b)*(p-this->c));
	this->dientich=area;
	
}
void TamGiac::printDT(){
	cout<<"Dien tich hinh tam giac: ";
	DaGiac::printDT();
}
//lop hinh tron
class Tron: public DaGiac{
	private:
		float bankinh;
	public:
		Tron();
		Tron(float r);
		void nhapDT();
		void setDT();
		float getDT(){
			DaGiac::getDT();
		}
		void printDT();	
};
Tron::Tron(){
	bankinh=0;
	setDT();
}
Tron::Tron(float r){
	this->bankinh=r;
	setDT();
}
void Tron:: nhapDT(){
	cout<<"Nhap ban kinh hinh: ";
	cin>>bankinh;
	setDT();
}
void Tron::setDT(){
	dientich=this->bankinh*this->bankinh*3.14;
}
void Tron::printDT(){
	cout<<"Dien tich ban kinh: ";
	DaGiac::printDT();
}
int main(){
	//nhap thong tin
	ChuNhat a[100];
	TamGiac b[100];
	Tron c[100];
	int n1,n2,n3;

	cout<<"\nNhap so luong hinh chu nhat: ";
	cin>>n1;
	for(int i=0;i<n1;i++){ // arr Chu nhat
		a[i].nhapDT();
		a[i].setDT();
		a[i].printDT();
	}
	//tim Smax hinh cn
	float maxChuNhat= a[0].getDT();
	for(int i=0;i<n1;i++){
		if (a[i].getDT()>maxChuNhat){
			maxChuNhat=a[i].getDT();
		}
	}
	cout<<"\nDien tich hcn lon nhat: "<<maxChuNhat<<endl;	

	cout<<"\nNhap so luong hinh tam giac: ";
	cin>>n2;
	for(int i=0;i<n2;i++){ // arr tam giac
		b[i].nhapDT();
		b[i].setDT();
		b[i].printDT();
	}
	//tim Smax tam giac
	float maxTamGiac= b[0].getDT();
	
	for(int i=0;i<n2;i++){
		if (b[i].getDT()>maxTamGiac){
			maxTamGiac=b[i].getDT();
		}
	}
	cout<<"\nDien tich hinh tam giac lon nhat: "<<maxTamGiac<<endl;	
	
	
	cout<<"\nNhap so luong hinh tron: ";
	cin>>n3;
	
	for(int i=0;i<n3;i++){ //arr hinh tron
		c[i].nhapDT();
		c[i].setDT();
		c[i].printDT();
	}
	//tim Smax hinh tron
	float maxTron= c[0].getDT();
	
	for(int i=0;i<n3;i++){
		if (c[i].getDT()>maxTron){
			maxTron=c[i].getDT();
		}
	}
	cout<<"\nDien tich htron lon nhat: "<<maxTron<<endl;	
	//so sanh 3 Smax tim S lon nhat

	float max=maxChuNhat;
	if(max <maxTamGiac ){
		max=maxTamGiac;
	}
	if(max < maxTron ){
		max= maxTron;
	}
	
	cout<<"\nDien tich lon nhat trong cac hinh da nhap:"<<max;
}
