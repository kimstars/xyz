#include<iostream>

#include "diem.cpp"
 using namespace std;

 class hinhtron:public diem{
     protected:
     diem O;
     int R;
     public:
     hinhtron(){

     }
     hinhtron( diem O, int R){
         this->O=O;
         this->R=R;
     }
     void sethinhtron(){
         O.nhapdiem();
         cout<<"nhap ban kinh"<<endl;
cin>>R;
     }
     void xuathinhtron(){
         O.xuatdiem();
         cout<<"ban kinh:"<<R<<endl;
     }
    
     float dientichHT(){
         return 2*3.14*R;
     }

 };