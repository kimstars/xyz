#include <iostream>
#include <cmath>

using namespace std;
int a[20];

//  xet tung vi tri (x,y)
// - duyet tung hang da xep
// - xep duoc khi thoa : 
//     +a[i] != y
//     +abs(i - x) != abs(a[i] - y)

bool check(int x, int y){
    for (int i = 0; i < x; i++)
    {
        if(a[i] == y || abs(i - x) == abs(a[i] - y)) return false;
    }
    return true;
}

// quay lui xuat ra khi (i == n) -> duyet het ban co -> tim duoc phuong an -> in ra
void Print2(int n){
    printf("\nBAN CO : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i] == j) printf(" 1 ");
            else printf(" 0 ");
        }
        printf("\n");
    } 
} 

void Print(int n){
    printf("Phuong an:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    Print2(n);
    printf("\n");
}




void Try(int i, int n){
    for (int  j = 1; j <= n; j++)
    {
        if(check(i,j)){//nếu tìm được thì lưu lại vị trí và in ra
            a[i] = j;
            if(i == n) Print(n);
            Try(i+1,n);
        }
    }
}


int main(){
    Try(1,8);
    return 0;
}