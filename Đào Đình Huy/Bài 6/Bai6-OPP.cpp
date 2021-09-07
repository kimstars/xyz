#include <iostream>
#include<math.h>

using namespace std;

class HinhTron{
    protected:
        double r;
    public:
        HinhTron(){

        }
        ~HinhTron(){
            this->r = 0;
        }
        HinhTron(double r){
            this->r = r;
        }
        double getArea(){
            return 2*3.14*r;
        }
        void input(){
            cin>>r;
        }
};

class HinhChuNhat{
    protected:
        double dai;
        double rong;
    public:
        HinhChuNhat(){

        }
        ~HinhChuNhat(){
            this->dai = this->rong = 0;
        }
        HinhChuNhat(double dai, double rong){
            this->dai = dai;
            this->rong =rong;
        }
        double getArea(){
            return dai*rong;
        }
        void input(){
            cout<<"Chieu dai: "; cin>>dai;
            cout<<"Chieu rong: "; cin>>rong;
        }
};

class TamGiac{
    protected:
        double a, b, c;
    public:
        TamGiac(double a, double b, double c){
            this->a = a;
            this->b =b;
            this->c = c;
        }
        TamGiac(){}
        ~TamGiac(){
            this->a = this->b = this->c = 0;
        }
        void input(){
            cin>>a>>b>>c;
            if((a+b)<=c || (b+c)<=a || (a+c)<=b){
                cout<<"Nhap lai: ";
                input();
            }
        }
        double getArea(){
            int p = (a + b + c)/2;
            return sqrt(p*(p - a)*(p - b)*(p - c));
        }
};

void max(HinhTron a[], HinhChuNhat b[], TamGiac c[], int n1, int n2, int n3){
    int max1 = 0;
    int max2 = 0; int max3 = 0;
    int k1, k2, k3;
    for(int i = 0; i < n1; i++){
        if(max1 < a[i].getArea()){
            max1 = a[i].getArea();
            k1 = i;
        }
    }
    for(int i = 0; i < n2; i++){
        if(max2 < b[i].getArea()){
            max2 = b[i].getArea();
            k2 = i;
        }
    }
    for(int i = 0; i < n3; i++){
        if(max3 < c[i].getArea()){
            max3 = c[i].getArea();
            k3 = i;
        }
    }
    if(a[k1].getArea() >= b[k2].getArea() && a[k1].getArea() >= c[k3].getArea()){
        cout<<"Hinh tron so "<<k1 + 1<<" co dien tich lon nhat";
    }else if(b[k2].getArea() >= a[k1].getArea() && b[k2].getArea() >= c[k3].getArea()){
        cout<<"Hinh chu nhat so "<<k2 + 1<<" co dien tich lon nhat";
    }else if(c[k3].getArea() >= a[k1].getArea() && c[k3].getArea() >= b[k2].getArea()){
        cout<<"Tam giac so "<<k3 + 1<<" co dien tich lon nhat";
    }
}

int main(){
    int n1, n2, n3;
    cout<<"Nhap so luong hinh tron: "; cin>>n1;
    HinhTron *a = new HinhTron[n1];
    for(int i = 0; i < n1; i++){
        cout<<"Ban kinh hinh tron "<<i+1<<": ";
        a[i].input();
    }
    cout<<endl<<"Nhap so luong hinh chu nhat: "; cin>>n2;
    HinhChuNhat *b = new HinhChuNhat[n2];
    for(int i = 0; i < n2; i++){
        cout<<"HCN "<<i+1<<": ";
        b[i].input();
    }
    cout<<endl<<"Nhap so luong hinh tam giac: "; cin>>n3;
    TamGiac *c = new TamGiac[n3];
    for(int i = 0; i < n3; i++){
        cout<<"Do dai 3 canh tam giac "<<i+1;
        c[i].input();
    }
    max(a, b, c, n1, n2, n3);

    return 0;
}