#include<iostream>
#include<cmath>
using namespace std;

int a[8];
int dem=0;
bool OK(int x2,int y2){
    for(int i=1;i<x2;i++)
if(a[i]==y2|| abs(i-x2)==abs(a[i]-y2))return false;
return true;
}
void xuat (int n){
    for(int i=1;i<=n;i++)cout<< "  "<<a[i];
    cout<<endl;

}
void Try(int i,int n){
    for(int j=1;j<=n;j++){
        if(OK(i,j)){
        a[i]=j;
        if(i==n) xuat(n);
        Try(i+1,n);

        }
    }
}
int main(){
    int n=8;
    cout<<"  C1 C2 C3 C4 C5 C6 C7 C8"<<endl;
    Try(1,n);
    return 0;
}