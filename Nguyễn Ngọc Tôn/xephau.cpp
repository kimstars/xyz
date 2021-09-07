#include<iostream>
#include<cmath>
using namespace std;
int a[20];
bool kiemtra(int x,int y){
    //kiem tra cách dat có thoa mãn không
    for(int i = 1; i < x ;i++)
        if(a[i] == y || abs(i-x) == abs(a[i] - y) )
            return false;
    //Neu kiem tra het các truong hop van không sai thì tra ve true
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
        // thu dat quân hau vào các cot tu 1 den n
        if(kiemtra(i,j)){
            //neu cách dat này thoa mãn thì luu lai vi trí
            a[i] = j;
                        //neu dat xong quân hau thi n thì xuat ra mot ket qua
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
