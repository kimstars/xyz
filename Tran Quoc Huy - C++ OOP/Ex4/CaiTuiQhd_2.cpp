#include <bits/stdc++.h>

using namespace std;
long n, W;
struct goihang
{
    long w = 0;
    long val = 0;
};

goihang a[200]; // mang luu gói hàng
long d[100][100]; //d[i][j] bang luu gia tri lon nhat khi chon den goi hang thu i có khoi luong toi da j

long Solve(long index, long W)
{

    for (size_t i = 0; i <= index; i++) // tr?c gói hàng
    {
        for (size_t j = 0; j <= W; j++) // tr?c kh?i lu?ng max
        {
            if (i == 0 || j == 0)
                d[i][j] = 0;
            else if (j < a[i].w)
            {
                d[i][j] = d[i - 1][j]; // goi hang duoc chon co khoi luong lon hon cho phép
            }
            else
            {
                d[i][j] =  max(d[i - 1][j] , d[i - 1][j - a[i].w] + a[i].val);
                // j >= a[i].w ---> goi hang nho hon khoi luong cho phep, van cho vao tui duoc.
                // max(d[i-1][j] , d[i-1][j - a[i].w] + a[i].val) kiem tra xem bo vào tui thì giá tri co lon hon không, neu không van lay cai cu
                // d[i-1][j] gia tri hien tai khi ch?n gói hàng i-1 v?i kh?i lu?ng t?i da là j
            }
        }
    }
    return d[index][W];
}


void Trace(long index, long W){
    cout << "\nCac chi so goi hang duoc chon: \n";
    while(index != 0){
        if(d[index][W] != d[index-1][W]){
            cout << index << " ";
            W = W - a[index].w; 
        }
        --index;
    }
}


void show(long n, long W){
    cout << "______________________________\n";
    cout <<"Cac goi hang ban da nhap la:\n";
    cout << left << setw(5)<< "id" << " : "<< setw(8) << "weight" << " : " << setw(8) << "value"  << endl;

    for (long i = 1; i <= n; i++)
    {
        cout << left << setw(5)<< i  << " : "<< setw(8) << a[i].w << " : " << setw(8)<< a[i].val  << endl;
    }
    cout << "______________________________\n";
}

int main()
{
    long n, W;
    cout << "Nhap so luong tui  va trong luong toi da :\n";

    cin >> n >> W;
    for (long i = 1; i <= n; i++)
    {
        cin >> a[i].w >> a[i].val;
    }
    show(n,W);
    cout << "ket qua : ";
    cout << Solve(n, W);
    Trace(n,W);
}
