#include<iostream>
using namespace std;
#define MAX 100
int dem=0;
void nhapmatran(int arr[MAX][MAX],int n,int m){
    cout<<"vui long nhap so 0 || 1:"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            do{
                cout<<"nhap arr["<<i<<"]["<<j<<"]: "<<endl;
                cin>>arr[i][j];

            }while(arr[i][j]>1||arr[i][j]<0);
        }
    }
}
void xuatmatran(int arr[MAX][MAX],int n,int m){
    for(int i=1;i<=n;i++){
        cout<<endl;
        for(int j=1;j<=m;j++){
            cout<<arr[i][j]<<"  ";

        }
    }
}
void timduong(int arr[MAX][MAX],int n,int m,int x,int y)
{
    if((x==1||x==n||y==1||y==m)&&arr[x][y]==0){
dem++;
return ;
    }
    if(arr[x][y]==1){
return ;
    }
    arr[x][y]=1;
   if(x>1&&x<n&&y>1&&y<n){
       
    
timduong( arr,n,m,x+1,y);
timduong(arr,n,m,x-1,y);
timduong(arr,n,m,x,y-1);
timduong(arr,n,m,x,y+1);

}
return;
}
int main(){
    int n,m,x,y;
    cout<<"nhap ma tran "<<endl;
    cout<<"nhap n:"<<endl;
    cin>>n;
    cout<<"nhap m:"<<endl;
    cin>>m;
    int arr[MAX][MAX];
    nhapmatran(arr,n,m);
    xuatmatran(arr,n,m);
cout<<"nhap diem xuat phat"<<endl;
do{
 cout<<"vui long nhap diem có a[i][j]=0"<<endl; 
cout<<"toa do hang:"<<endl;
cin>>x;
cout<<"toa do cot:"<<endl;
cin>>y;
}while(arr[x][y]==1);
 
timduong(arr,n,m,x,y);
cout<<"so duong di co the di ra la:"<<dem;


}
