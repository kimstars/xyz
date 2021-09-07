#include<iostream>
#include "dovat.cpp"
#include<bits/stdc++.h>
 using namespace std;
void xapxep (dovat arr[],int n)
{
    int j;
    dovat t;
    for(int i=1;i<n;i++)
    {
       j=i-1;
       t=arr[i];
       while(j >= 0 && t.getdongia() < arr[j].getdongia())
       {
           arr[j+1]=arr[j];
           j--;
       }
      arr[j+1]=t;
    }  
}
int n,M;
dovat a[105];
int dp[110][110];
int res=0;
void Solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=M;j++){
            if(j<a[i].getTrongluong()){
                dp[i][j]=dp[i-1][j];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].getTrongluong()]+a[i].getGiatri());

            }
            res=max(res,dp[i][j]);
        }
    }}

 
 int main(){
     //luu do vat da duoc chon
     
     
     cout<<"nhap so luong do vat"<<endl;
     cin>>n;
   
   
     
     for(int i=1;i<=n;i++){
         a[i].setDovat();

     }
    
   
cout<<"nhap khoi luong M co the mang toi da"<<endl;
cin>>M;
Solve();
cout<<"gia tri co the mang toi da la"<<res;




     

     

 }