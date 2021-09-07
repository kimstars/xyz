#include<iostream>
#include<cmath>
using namespace std;
int a[20];
bool kiemtra(int x,int y){
    //kiem tra c�ch dat c� thoa m�n kh�ng
    for(int i = 1; i < x ;i++)
        if(a[i] == y || abs(i-x) == abs(a[i] - y) )
            return false;
    //Neu kiem tra het c�c truong hop van kh�ng sai th� tra ve true
    return true;
}
void Print(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i] == j) cout<<" 1 ";
            else cout<<" 0 ";
        }
        cout<<"\n";
    } 
} 
 
void Xuat(int n){
    //in ra mot ket qua
    cout<<"\nvi tri cac quan hau : ";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";}
        cout<<"\n";
        Print(n);
        cout<<"\n";
    
}
 
void Try(int i,int n){
    for(int j = 1;j<=n;j++){
        // thu dat qu�n hau v�o c�c cot tu 1 den n
        if(kiemtra(i,j)){
            //neu c�ch dat n�y thoa m�n th� luu lai vi tr�
            a[i] = j;
                        //neu dat xong qu�n hau thi n th� xuat ra mot ket qua
            if(i==n) Xuat(n);
            Try(i+1,n);
        }
    }
}
 
int main(){
	int n;
	cout<<"nhap kich thuoc ban co n*n :";
	cin>>n;
    Try(1,n);
    return 0;
}
