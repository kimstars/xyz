#include <iostream>
#define lCb 1390
#define max 100000
using namespace std;

//lop cong nhan san xuat
class cNhanSx{
    private :
        string ten;
        int soSanPham;
    public :
        void setTen(string ten);
        string getTen() ;
        void setSoSanPham(int soSanPham) ;
        int getSoSanPham() ;
        double luongSx(int soSanPham) ;
};

//lop cong nhan hanh chinh
class cNhanHc{
        private :
            string ten;
            double hSoLuong;
        public :
            void setTen(string ten);
            string getTen() ;
            void setHSoLuong(double hSoLuong);
            double getHSoLuong() ;
            double luongHc(double hSoLuong) ;
};

//dinh nghia phuong thuc cua lop cong nhan san xuat 
void cNhanSx::setTen(string ten){
    this->ten = ten;
}
string cNhanSx::getTen() { 
    return ten;
}
void cNhanSx::setSoSanPham(int soSanPham){
    this->soSanPham = soSanPham;
}
int cNhanSx::getSoSanPham() {
    return soSanPham;
}
double cNhanSx::luongSx(int soSanPham){
    return 5*soSanPham;
}

//dinh nghia phuong thuc cua lop cong nhan hanh chinh
void cNhanHc::setTen(string ten){
    this->ten = ten;
}
string cNhanHc::getTen(){ 
    return ten;
}
void cNhanHc::setHSoLuong(double hSoLuong){
    this->hSoLuong = hSoLuong;
}
double cNhanHc::getHSoLuong(){
    return hSoLuong;
}
double cNhanHc::luongHc(double hSoLuong){
    return hSoLuong* lCb;
}

//ham tim luong thap nhat
double minLuong(double a[], int n) {
    double min = a[0];
    for(int i=1; i<n; i++) {
        if(min>a[i]) min = a[i];
    }
    return min;
}
// id cua nguoi co luong thap nhat
double idMin(double a[], int n){
    double min = a[0];
    int m;
    for(int i=0;i<n;i++){
        if(min>a[i]){
            min = a[i];
            m=i;
        }
    }
    return m+1;
}
//ham tinh tong luong
double tongLuong(double a[], int n){
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    return sum;
}

int main(){
    //cong nhan san xuat
    int n1;
    string ten;
    int soSanPham;
    double luongCnSx[max];
    cout<<"Nhap so cong nhan san xuat: ";
    cin>>n1;
    cNhanSx *cNhanSxs;
    cNhanSxs = new cNhanSx[n1];
    for(int i=0; i<n1; i++) {
        cout<<"\nCong nhan san xuat "<<i+1<<":\n";
        cout<<"Ten: ";
        cin>>ten;
        cNhanSxs[i].setTen(ten);
        cout<<"So san pham lam ra: ";
        cin>>soSanPham;
        cNhanSxs[i].setSoSanPham(soSanPham);
        luongCnSx[i] = cNhanSxs[i].luongSx(soSanPham);
    }
    cout<<"\n=====================CONG NHAN SAN XUAT======================"<<endl;
    cout<<"\nID\t|\tTen\t|\tSo san pham\t|\tLuong"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    for (int i = 0; i < n1; i++)
    {
        cout<<"s"<<i+1<<"\t|\t"<<cNhanSxs[i].getTen()<<"\t|\t"<<cNhanSxs[i].getSoSanPham()<<"\t\t|\t"<<cNhanSxs[i].luongSx(cNhanSxs[i].getSoSanPham())<<"\n";
    }
    
    //cong nhan hanh chinh
    int n2;
    double hSoLuong;
    double luongCnHc[max];
    cout<<"\nNhap so cong nhan hanh chinh: ";
    cin>>n2;
    cNhanHc *cNhanHcs;
    cNhanHcs = new cNhanHc[n2];
    for(int i=0; i<n2; i++) {
        cout<<"\nCong nhan hanh chinh "<<i+1<<":\n";
        cout<<"Ten: ";
        cin>>ten;
        cNhanHcs[i].setTen(ten);
        cout<<"He so luong: ";
        cin>>hSoLuong;
        cNhanHcs[i].setHSoLuong(hSoLuong);
        luongCnHc[i] = cNhanHcs[i].luongHc(hSoLuong);
    }

    cout<<"\n=====================CONG NHAN HANH CHINH======================"<<endl;
    cout<<"\nID\t|\tTen\t|\tHe so luong\t|\tLuong"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    for (int i = 0; i < n2; i++)
    {
        cout<<"h"<<i+1<<"\t|\t"<<cNhanHcs[i].getTen()<<"\t|\t"<<cNhanHcs[i].getHSoLuong()<<"\t\t|\t"<<cNhanHcs[i].luongHc(cNhanHcs[i].getHSoLuong())<<"\n";
    }
    
    double luongMin[] = {minLuong(luongCnSx,n1), minLuong(luongCnHc,n2)};
    if(minLuong(luongMin,2)==luongMin[0]){
        cout<<"\nNhan vien san xuat co ID: s"<<idMin(luongCnSx,n1)<<" luong thap nhat";
    }
    else if(minLuong(luongMin,2)==luongMin[1]){
        cout<<"\nNhan vien hanh chinh co ID: h"<<idMin(luongCnHc,n2)<<" luong thap nhat";
    }
    double luong = tongLuong(luongCnSx, n1) + tongLuong(luongCnHc, n2);
    cout<<"\nTong luong ma cong ty phai tra: "<<luong<<" nghin VND"; 
}
