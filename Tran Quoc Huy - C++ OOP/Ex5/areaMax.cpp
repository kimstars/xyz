#include <iostream>
#include <math.h>
#define M 1000
using namespace std;

class hTron{
    private: 
        float r;//canh hinh vuong
    public:
        float dienTichHt(float r);
        void setR(float r);
        float getR();
};
class hChuNhat{
    private: 
        float l, w;
    public:
        void setL(float l);
        float getL();
        void setW(float w);
        float getW();
        float dienTichHcn(float l, float w);
};

class tamGiac{
    private: 
        //do dai cac canh
        float a,b,c; 
    public:
        void setA(float a);
        float getA();
        void setB(float b);
        float getB();
        void setC(float c);
        float getC();
        float nuaChuVi(float a, float b, float c);
        float dienTichTg(float a, float b, float c);   
};

//hinh tron
void hTron::setR(float r) {
    this->r = r;
}
float hTron::getR(){
    return r;
}
float hTron::dienTichHt(float r){
    return 3.14*r*r;
}

//hinh tam giac
void tamGiac::setA(float a) {
    this->a = a;
}
float tamGiac::getA(){
    return a;
}
void tamGiac::setB(float b) {
    this->b = b;
}
float tamGiac::getB(){
    return b;
}
void tamGiac::setC(float c) {
    this->c = c;
}
float tamGiac::getC(){
    return c;
}
float tamGiac::nuaChuVi(float a, float b, float c){
    return (a+b+c)/2;
}
float tamGiac::dienTichTg(float a, float b, float c){
    float p = nuaChuVi(a,b,c);
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

//hinh chu nhat
void hChuNhat::setL(float l) {
    this->l = l;
}
float hChuNhat::getL(){
    return l;
}
void hChuNhat::setW(float w) {
    this->w = w;
}
float hChuNhat::getW(){
    return w;
}
float hChuNhat::dienTichHcn(float l, float w){
    return l*w;
}
//diện tích lớn nhất của loại hình
float sMax(float a[M], int n){
    float max = a[0];
    for(int i=0;i<n;i++){
        if(max<a[i]){
            max = a[i];
        }
    }
    return max;
}
//stt của hình có diện tích lớn nhất
float ttSmax(float a[M], int n){
    float max = a[0];
    int m;
    for(int i=0;i<n;i++){
        if(max<a[i]){
            max = a[i];
            m=i;
        }
    }
    return m+1;
}
//ham main
int main(){
    //hinh tron
    int n1;
    cout<<"Nhap so hinh tron: ";
    cin>>n1;
    hTron *hTrons;
    hTrons = new hTron[n1];
    float sT[M];
    for(int i=0;i<n1;i++){
        float r;
        cout<<"\nHinh tron thu: "<<i+1<<":\n";
        cout<<"Ban kinh: ";
        cin>>r;
        hTrons[i].setR(r);
        cout<<"Dien tich: "<<hTrons[i].dienTichHt(r)<<"\n";
        sT[i] = hTrons[i].dienTichHt(r);
    }
    //hinh chu nhat
    int n2;
    cout<<"\nNhap so hinh chu nhat: ";
    cin>>n2;
    hChuNhat *hChuNhats;
    hChuNhats = new hChuNhat[n2];
    float sCn[M];
    for(int i=0;i<n2;i++){
        float l,w;
        cout<<"\nHinh chu nhat thu "<<i+1<<":\n";
        cout<<"Chieu dai: "; cin>>l;
        cout<<"Chieu rong: "; cin>>w;
        hChuNhats[i].setL(l);
        hChuNhats[i].setW(w);
        cout<<"Dien tich: "<<hChuNhats[i].dienTichHcn(l,w)<<"\n";
        sCn[i] = hChuNhats[i].dienTichHcn(l,w);
    }
    //hinh tam giac
    int n3;//so tam giac
    cout<<"\nNhap so hinh tam giac: ";
    cin>>n3;
    tamGiac  *tamGiacs;
    tamGiacs = new tamGiac[n3];//cap phat bo nho cho mang tam giac
    float sTg[M];
    //khoi tao doi tuong tam giac
    for(int i=0;i<n3;i++) {
        float a,b,c;
        cout<<"\nTam giac thu "<<i+1<<":\n";
        do{
        	cout<<"Do dai 3 canh: "; 
        	cin>>a>>b>>c;
		}
        while(a+b<=c||b+c<=a||a+c<=b);
        tamGiacs[i].setA(a);
        tamGiacs[i].setB(b);
        tamGiacs[i].setC(c);
        cout<<"Dien tich: "<<tamGiacs[i].dienTichTg(a,b,c)<<"\n";
        sTg[i] = tamGiacs[i].dienTichTg(a,b,c);
    }

    float maxS[] = {sMax(sT,n1),sMax(sCn,n2),sMax(sTg,n3)};
    if(sMax(maxS,3)==maxS[0]){
        cout<<"\nHinh lon nhat la hinh tron thu "<<ttSmax(sT,n1);
    }
    else if(sMax(maxS,3)==maxS[1]){
        cout<<"\nHinh lon nhat la hinh chu nhat thu "<<ttSmax(sCn,n2);
    }
    else if(sMax(maxS,3)==maxS[2]){
        cout<<"\nHinh lon nhat la hinh tam giac thu "<<ttSmax(sTg,n3);
    }
}
