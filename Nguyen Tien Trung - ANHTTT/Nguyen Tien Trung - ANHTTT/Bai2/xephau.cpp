#include<stdio.h>
#include<math.h>
int a[20];
bool Check(int x,int y){
    for(int i = 1; i <x ;i++)
        if(a[i] == y || abs(i-x) == abs(a[i] - y) )
            return false;
    return true;
}
 
void Xuat(int n){
    for(int i=1;i<=n;i++){
         printf(" %d ",a[i]); }
		 printf("\n");
}
 
void Test(int i,int n){
    for(int j = 1;j<=n;j++){
        if(Check(i,j)){
            a[i] = j;
            if(i==n) Xuat(n);
            Test(i+1,n);
        }
    }
}
int main(){
    int n = 8;
    Test(1,n);
    return 0;
}
