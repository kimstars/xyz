#pragma once
#include<iostream>
using namespace std;
class dovat{
protected:
string ten;
float Trongluong;
float giatri;
public:
dovat(){

}
dovat( string ten ,float Trongluong,float giatri){
    this->giatri=giatri;
    this->Trongluong=Trongluong;
    this->ten=ten;
}
int getTrongluong(){
    return Trongluong;
}
void setTrongluong(float){
    this->Trongluong=Trongluong;
}
int getGiatri(){
    return giatri;
}
void setGiatri(float Giatri){
    this->giatri=giatri;
}
string getTen(){
    return ten;
}
void setDovat(){
    cout<<"nhap ten do vat"<<endl;
    cin>>ten;
    cout<<"nhap trong luong"<<endl;
    cin>>Trongluong;
    cout<<"nhap gia tri"<<endl;
    cin>>giatri;


}
void xuatDovat(){
    cout<<" do vat:"<<ten <<endl;
    cout<<"trong luong: "<<Trongluong<<endl;
    cout<<"gia tri: "<<giatri<<endl;
    
}
float getdongia(){
    return giatri/Trongluong;
}
};