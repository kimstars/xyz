#include <iostream>

using namespace std;

class CongNhan{
    protected:  
        int sogio;
    public:
        CongNhan(){

        }
        ~CongNhan(){
            sogio = 0;
        }
        CongNhan(int sogio){
            this->sogio = sogio;
        }
        int getSalary(){
            return sogio * 5000;
        }
        void input(){
            cin>>this->sogio;
        }
};

class HanhChinh{
    protected:
        int heso;
    public:
        HanhChinh(){

        }
        ~HanhChinh(){
            this->heso = 0;
        }
        HanhChinh(double heso){
            this->heso = heso;
        }
        int getSalary(){
            return heso*1300000;
        }
        void input(){
            cin>>this->heso;
        }
};

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void min(CongNhan a[], HanhChinh b[], int m, int p){
    int min = a[0].getSalary();
    int c = 1;
    for(int i = 0; i < m; i++){
        if(min > a[i].getSalary()){
            min = a[i].getSalary();
            c = i + 1;
        }
    }  
    int min2 = b[0].getSalary();
    int d = 1;
    for(int i = 0; i < p; i++){
        if(min2 < b[i].getSalary()){
            min2 = b[i].getSalary();
            d = i + 1;
        }
    }
    if(min < min2){
        cout<<endl<<"Nguoi co luong thap nhat cong ty la cong nhan so "<<c;
    }else if(min > min2){
        cout<<endl<<"Nguoi co luong thap nhat cong ty la nhan vien hanh chinh so "<<d;
    }
}

int main()
{
    int n, m, p;
    cout<<"Nhap so nhan vien cua cong ty: "; cin>>n;
    cout<<"Nhap so cong nhan san xuat: "; cin>>m;
    CongNhan *a = new CongNhan[m];
    for(int i = 0; i < m; i++){
        cout<<"Nhap so gio lam cua cong nhan "<<i+1<<": ";
        a[i].input();
    }
    p = n - m;
    HanhChinh *b = new HanhChinh[p];
    for(int j = 0; j < p; j++){
        cout<<"Nhap he so cua nhan vien "<<j+1<< ": ";
        b[j].input();
    }
    min(a, b, m, p);
    cout<<endl<<"_______________________"<<endl;
    cout<<"Tien luong cong ty phai tra hang thang la: ";
    int sum1, sum2;
    sum1 = sum2 =0;
    for(int i = 0; i < m; i++){
        sum1 += a[i].getSalary();
    }
    for(int i = 0; i < p; i++){
        sum2 += b[i].getSalary();
    }
    int sum = sum1 + sum2;
    cout<<sum;
    
    return 0;
}