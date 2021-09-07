#include<iostream>
#include "CNhanhchinh.cpp"
#include "CNsanxuat.cpp"
using namespace std;

int main(){
    int n1,n2; 
    float MinLSX=100000000;
    float MinLHC=100000000;

cout<<"nhap so luong cong nhan san xuat"<<endl;
cin>>n1;
CNsanxuat SX[n1];
cout<<"nhap so luong cong nhan hanh chinh"<<endl;
cin>>n2;
CNhanhchinh HC[n2];int n;float Tongluong=0;
do{
cout<<"1.nhap thong tin cong nhan san xuat"<<endl;
cout<<"2.nhap thong tin cong nhan hanh chinh"<<endl;
cout<<"3.nhap so san pham cua cac cong nhan san xuat"<<endl;
cout<<"4.nhap he so luong cua cac cong nhan hanh chinh"<<endl;
cout<<"5.muc luong toi thieu cua cong nhan:"<<endl;
cout<<"6.tong muc luong cong ty chi tra"<<endl;
cout<<"0. thoat chuong trinh"<<endl;
cin>>n;
switch(n){
    case(1):
        for(int i=0;i<n1;i++){
            cout<<"nhap thong tin cua cong nhan san xuat"<<i+1<<endl;
        SX[i].setCNsanxuat();
       }break;
    case(2):
    for(int i=0;i<n2;i++){
        cout<<"nhan thong tin cua cong nhan hanh chinh "<<i+1<<endl;
        HC[i].setCNhanhchinh();
    }  break; 
    case(3):
    for(int i=0;i<n1;i++){
        cout<<"nhap so san phan cua cong nhan san xuat "<<i+1<<endl;
        SX[i].nhapsosanpham();
    }break;
    case(4):
    for(int i=0;i<n2;i++){
        cout<<"nhap he so luong cua cong nhan hanh chinh"<<i+1<<endl;
        HC[i].nhaphesoluong();
    }break;
    case(5):
   
    for(int i=0;i<n1;i++){
        if(SX[i].luongCNsx()<MinLSX){
            MinLSX=SX[i].luongCNsx();
        }
    }
    for(int i=0;i<n2;i++){
        if(HC[i].luongCNhanhchinh()<MinLHC){
            MinLHC=HC[i].luongCNhanhchinh();
        }}
      if(MinLHC>MinLSX){
          cout<<"luong toi thieu la"<<MinLSX<<endl;
      }  else{
          cout<<"luong toi thieu la"<<MinLHC<<endl;
      }
break;
    case(6):
   
    for(int i=0;i<n1;i++){
        Tongluong=Tongluong+SX[i].luongCNsx();
    }
    for(int i=0;i<n2;i++){
        Tongluong=Tongluong+HC[i].luongCNhanhchinh();
    }
    cout<<"tong luong cong ty phai chi tra:"<<Tongluong<<endl;
    break;
  default:
            break;

}
}while(n!=0);
}
