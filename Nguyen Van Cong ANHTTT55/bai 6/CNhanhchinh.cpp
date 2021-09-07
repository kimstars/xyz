#include<iostream>
using namespace std;
class CNhanhchinh{
protected:
string hoten;
int tuoi;
string gioitinh;

int hesoluong;
public:
CNhanhchinh(){};
CNhanhchinh(int tuoi,string hoten,string gioitinh,int hesoluong){
    this->tuoi=tuoi;
    this->gioitinh=gioitinh;
    this->hoten=hoten;
    this->hesoluong=hesoluong;
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
int gethesoluong(){
    return hesoluong;
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
void sethesoluong(int hesoluong){
    this->hesoluong=hesoluong;
}
void nhaphesoluong(){
    cin>>hesoluong;
}
void setCNhanhchinh(){
    cout<<"nhap ho ten "<<endl;
    cin>>hoten;
    cout<<"nhap tuoi "<<endl;
    cin>>tuoi;
    cout<<"nhap gioi tinh "<<endl;
    cin>>gioitinh;
    cout<<"nhap hesoluong "<<endl;
    cin>>hesoluong;

}
void getCNhanhchinh(){
    cout<<"hoten :"<<hoten<<endl;
    cout<<"tuoi :"<<tuoi<<endl;
    cout<<"gioi tinh:"<<gioitinh<<endl;
    cout<<"he so luong :"<<hesoluong<<endl;


}
float luongCNhanhchinh(){
    return 1490000*hesoluong;
}
};