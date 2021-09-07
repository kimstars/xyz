#include<iostream>
#include<string>
using namespace std;
class CNsanxuat{
protected:
string hoten;
int tuoi;
string gioitinh;

int sosanpham;
public:
CNsanxuat(){};
CNsanxuat(int tuoi,string hoten,string gioitinh,int sosanpham){
    this->tuoi=tuoi;
    this->gioitinh=gioitinh;
    this->hoten=hoten;
    this->sosanpham=sosanpham;
}
int gettuoi(){
    return tuoi;
}
string getten(){
    return hoten;
}
string getgioitinh(){
    return gioitinh;
}
int getsosanpham(){
    return sosanpham;
}
void settuoi(int tuoi){
    this->tuoi=tuoi;
}
void sethoten(string hoten){
    this->hoten=hoten;
}
void setgioitinh(string gioitinh){
    this->gioitinh=gioitinh;
}
void setsosanpham(int sosanpham){
    this->sosanpham=sosanpham;
}
void nhapsosanpham(){
    cin>>sosanpham;
}

void setCNsanxuat(){
    cout<<"nhap ho ten "<<endl;
    cin>>hoten;
    cout<<"nhap tuoi "<<endl;
    cin>>tuoi;
    cout<<"nhap gioi tinh "<<endl;
    cin>>gioitinh;
    cout<<"nhap sosanpham "<<endl;
    cin>>sosanpham;

}
void getCNsanxuat(){
    cout<<"hoten :"<<hoten<<endl;
    cout<<"tuoi :"<<tuoi<<endl;
    cout<<"gioi tinh:"<<gioitinh<<endl;
    cout<<"so san pham :"<<sosanpham<<endl;


}
float luongCNsx(){
    return 5000*sosanpham;
}

};