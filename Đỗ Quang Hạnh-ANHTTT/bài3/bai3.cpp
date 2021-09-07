#include<iostream>
#define mx 100
using namespace std;
int dem=0;
void nhap(int n,int m,int a[mx][mx])
{
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       {
           do{
               cout<<"nhap a["<<i<<"]["<<j<<"] = "<<endl;
               cin>>a[i][j];
             }
             while (a[i][j]<0||a[i][j]>1);
       }
}
void timduong(int n,int m,int a[mx][mx],int x,int y)
{
    if((x==1||x==n||y==1||y==m) && a[x][y]==0)
    {
        dem++;
    }
    if(a[x][y]==1) return;
    a[x][y]=1;
    if( x>1 && x<n && y>1 && y<n )
    {
        timduong(n,m,a,x+1,y);
        timduong(n,m,a,x-1,y);
        timduong(n,m,a,x,y-1);
        timduong(n,m,a,x,y+1);
    }
}
int main()
{
    int n,m,x,y;
    int a[mx][mx];
    cout<<"nhap n,m ="<<endl;
    cin>>n>>m;
    nhap(n,m,a);
    cout<<"nhap x,y ="<<endl;
    cin>>x>>y;
    timduong(n,m,a,x,y);
    cout<<dem;
    return 0;
}