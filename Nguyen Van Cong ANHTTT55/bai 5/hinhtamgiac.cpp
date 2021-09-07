#include<iostream>
#include<cmath>
#include "diem.cpp"
using namespace std;
class hinhtamgiac:public diem{
protected:
diem a;
diem b;
diem c;
public:
hinhtamgiac(){

}
hinhtamgiac(diem a,diem b,diem c){
    this->a=a;
    this->b=b;
    this->c=c;
}
void sethinhtamgiac(){
    do{
    cout<<"nhap diem 1"<<endl;

        a.nhapdiem();
        cout<<"nhap diem 2"<<endl;
        b.nhapdiem();
        cout<<"nhap diem 3"<<endl;
        c.nhapdiem();
   
    }while(a.getX()==b.getX()==c.getX()|| a.getY()==b.getY()==c.getY());
    
}
float dientichTG(){
    return 1/2* abs((b.getX()-a.getX())*(c.getY()-a.getY())-(c.getX()-a.getX())*(b.getY()-a.getY()));

}
void xuathinhtamgiac(){
    a.xuatdiem();
    cout<<"    ";
    b.xuatdiem();
    cout<<endl;
cout<<"  ";
    c.xuatdiem();
}
};