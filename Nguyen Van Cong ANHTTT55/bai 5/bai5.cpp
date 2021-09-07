#include<iostream>
#include "diem.cpp"
#include "hinhtamgiac.cpp"
#include "hinhchunhat.cpp"
#include "hinhtron.cpp"

int main(){
    int n1,n2,n3;
cout<<"nhap n1 hinh tron"<<endl;
cin>>n1;
cout<<"nhap n2 hinh chu nhat"<<endl;
cin>>n2;
cout<<"nhap n3 hinh tam giac"<<endl;
cin>>n3;
hinhtron Tron[n1];
hinhchunhat CNhat[n2];
hinhtamgiac Tgiac[n3];
int MAXDT=0;//tim dien tich lon nhat
for(int i=0;i<n1;i++){
    cout<<"nhap hinh tron "<<i+1<<endl;

Tron[i].sethinhtron();Tron[i].xuathinhtron();
cout<<endl;
if(Tron[i].dientichHT()>MAXDT){
    MAXDT=Tron[i].dientichHT();
}

}
for(int i=0;i<n2;i++){
    cout<<"nhap hinhchu nhat"<<i+1<<endl;
    CNhat[i].nhaphinhchunhat();
    CNhat[i].xuathinhchunhat();
    cout<<endl;
    if(CNhat[i].dientichCN()>MAXDT){
        MAXDT=CNhat[i].dientichCN();
    }

}
for(int i=0;i<n3;i++){
    cout<<"nhao hinh tam giac"<<i+1<<endl;
    Tgiac[i].sethinhtamgiac();
    Tgiac[i].xuathinhtamgiac();
    cout<<endl;
if(Tgiac[i].dientichTG()>MAXDT){
    MAXDT=Tgiac[i].dientichTG();
}

}

cout<<"dien tich lon nhat la: "<<MAXDT;





}
    
