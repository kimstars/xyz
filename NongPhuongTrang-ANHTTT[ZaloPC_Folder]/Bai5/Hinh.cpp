#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

class Hinh{
    public:
    virtual void getdata(){};
    virtual void display(){};
    virtual double getArea()=0;
};

class Tron: public Hinh{
    private:
    double radius;
    public:
    double getArea();
    void getdata();
    void display();
};
void Tron::getdata(){
    cout << "\nNhap ban kinh hinh tron: ";
    cin >> radius;
}
double Tron::getArea(){
    return radius*radius*3.14;
}
void Tron::display(){
    cout << "Dien tich: " << getArea() ;
}

class ChuNhat:public Hinh{
    private:
    double dai;
    double rong;
    public:
    double getArea();
    void getdata();
    void display();
};
void ChuNhat::getdata(){
    cout << "\nNhap chieu dai: "; cin>>dai;
    cout << "Nhap chieu rong: "; cin>>rong;
}
double ChuNhat::getArea(){
    return dai*rong;
}
void ChuNhat::display(){
    cout << "Dien tich: " << getArea() ;
}

class TamGiac:public Hinh{
    private:
    double a1,a2,a3;
    public:
    double getArea();
    void getdata();
    void display();
};
void TamGiac::getdata(){
    cout << "\nNhap do dai ba canh cua tam giac: " ;
    cout << "\na1= ";cin>>a1; 
    cout << "a2= ";cin>>a2; 
    cout << "a3= ";cin>>a3; 
    if((a1+a2)<=a3||(a2+a3)<=a1||(a1+a3)<=a2){
        cout << "Nhap lai: ";
        TamGiac::getdata();
    }
}
double TamGiac::getArea(){
    double p=(a1+a2+a3)/2;
    return sqrt(p*(p-a1)*(p-a2)*(p-a3)); 
}
void TamGiac::display(){
    cout << "Dien tich: " << getArea();
}
struct Node{
    double area;
    int vt;
    int kieu;
};

void searchMax(Tron tron[], ChuNhat cn[], TamGiac tg[], int n1, int n2, int n3){
    Node node;
    cout << "\nHinh co dien tich lon nhat la: ";
    node.area=tron[0].getArea();
    node.vt=1;
    node.kieu=1;
    for(int i=1;i<n1;i++){
        if(tron[i].getArea()>(node.area)){
            node.area=tron[i].getArea();
            node.vt=i+1;
            node.kieu=1;
        }
    }
    for(int i=0;i<n2;i++){
        if(cn[i].getArea()>(node.area)){
            node.area=cn[i].getArea();
            node.vt=i+1;
            node.kieu=2;
        }
    }
    for(int i=0;i<n3;i++){
        if(tg[i].getArea()>(node.area)){
            node.area=tg[i].getArea();
            node.vt=i+1;
            node.kieu=3;
        }
    }
    if(node.kieu==1){
        cout << "\nHinh tron thu " << node.vt << endl;
        tron[node.vt-1].display();
    } else if (node.kieu==2){
        cout << "\nHinh chu nhat thu " << node.vt << endl;
        cn[node.vt-1].display();
    } else if (node.kieu==3){
        cout << "\nHinh tam giac thu " << node.vt << endl;
        tg[node.vt-1].display();
    }
}
/*
    double max1=0,max2=0,max3=0,M;
    int k1,k2,k3;
    cout << "\nHinh co dien tich lon nhat la: ";
    for(int i=0;i<n1;i++){
        if(tron[i].getArea()>max1){
            max1=tron[i].getArea();
            k1=i+1;
        }
    }
    for(int i=0;i<n2;i++){
        if(cn[i].getArea()>max2){
            max1=cn[i].getArea();
            k2=i+1;
        }
    }
    for(int i=0;i<n3;i++){
        if(tg[i].getArea()>max3){
            max3=tg[i].getArea();
            k3=i+1;
        }
    }      
    M=max(max(max1,max2),max3);
    if(M==max1){
        cout << "\nHinh tron thu " << k1;
        tron[k1-1].display();
    } else if (M==max2){
        cout << "\nHinh chu nhat thu " << k2;
        cn[k2-1].display();
    } else if (M==max3){
        cout << "\nHinh tam giac thu " << k3;
        tg[k3-1].display();
    }    
} 
*/

int main(){
    int n1, n2, n3;
    cout << "\nNhap so hinh tron: "; cin >> n1; 
    Tron* tron = new Tron[n1];
    cout << "\nNhap thong tin hinh tron." << endl ;
    for(int i=0;i<n1;i++){
        cout << "\nHinh tron " << i+1 << ":" ;
        tron[i].getdata();
        tron[i].display();
    }
    cout << endl;
    cout << "\nNhap so hinh chu nhat: "; cin >> n2; 
    ChuNhat* cn = new ChuNhat[n2];
    cout << "\nNhap thong tin hinh chu nhat." << endl ;
    for(int i=0;i<n2;i++){
        cout << "\nHinh chu nhat " << i+1 << ":" ;
        cn[i].getdata();
        cn[i].display();
    }
    cout << endl;
    cout << "\nNhap so hinh tam giac: "; cin >> n3; 
    TamGiac* tg = new TamGiac[n3];
    cout << "\nNhap thong tin hinh tam giac." << endl ;
    for(int i=0;i<n3;i++){
        cout << "\nHinh tam giac " << i+1 << ":" ;
        tg[i].getdata();
        tg[i].display();
    }
    cout << endl;
    searchMax(tron,cn,tg,n1,n2,n3);
}
