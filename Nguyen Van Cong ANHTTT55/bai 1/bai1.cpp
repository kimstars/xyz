#include<iostream>
#include "diem.cpp"
#include "hinhchunhat.cpp"
using namespace std;


int main(){
    int n;
    cout<<"nhap so diem"<<endl;
    cin>>n;
    diem G[n];
    for(int i=0;i<n;i++){
        cout<<"nhap diem "<<i<<endl;
        G[i].nhapdiem();
    }
    for(int i=0;i<n;i++){
        G[i].xuatdiem();

    }
    cout<<endl;
 // tim diem co tung do lon nhat
 int Tmax=0;
  int Tmin=100;
  int Hmax=0;
  int Hmin=100;
 for(int i=0;i<n;i++){
     if(G[i].getY()>Tmax){
         Tmax=G[i].getY();
     }
     if(G[i].getY()<Tmin){
         Tmin=G[i].getY();
     }
     if(G[i].getX()>Hmax){
         Hmax=G[i].getX();
     }
     if(G[i].getX()<Hmin){
         Hmin=G[i].getX();
     }
 }
 hinhchunhat H(Hmax,Hmin,Tmax,Tmin);
 H.xuathinhchunhat();

 
return 0;

}
