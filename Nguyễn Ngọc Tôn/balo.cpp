#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Su Dung Quy Hoach Dong
long n, W;
struct goihang
{
    long w = 0;
    long val = 0;
};

goihang a[200]; // mang luu goi hang
long d[100][100]; //d[i][j] luu gia tri lon nhat khi chon goi hang i co khoi luong toi da j

long Solve(long index, long W)
{

    for (int i = 0; i <= index; i++) // truc goi hang
    {
        for (int j = 0; j <= W; j++) // truc khoi luong max
        {
            if (i == 0 || j == 0)
                d[i][j] = 0;
            else if (j < a[i].w)
            {
                d[i][j] = d[i - 1][j]; // goi hang duoc chon co khoi luong lon hon cho phep
            }
            else
            {
                d[i][j] =  max(d[i - 1][j] , d[i - 1][j - a[i].w] + a[i].val);
                // j >= a[i].w ---> goi hang khoi luong nho hon cho phep van co the cho vao tui.
                // max(d[i-1][j] , d[i-1][j - a[i].w] + a[i].val) kiem tra xem bo vao tui gia tri co lon hon khong, neu khong van lay cai cu
                // d[i-1][j] gia tri hien tai khi chon goi hang i-1 voi khoi luong toi da j
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
    //dung setw(n) dieu chinh do rong cua du lieu xuat ra cho dep hihi!!
    for (long i = 1; i <= n; i++)
    {
        cout << left << setw(5)<< i  << " : "<< setw(8) << a[i].w << " : " << setw(8)<< a[i].val  << endl;
    }
    cout << "______________________________\n";
}

int main()
{
    long n, W;
    cout << "Nhap so luong tui: ";
    cin >> n ;
    cout<<"Nhap trong luong toi da: ";
    cin>> W;
    for (long i = 1; i <= n; i++)
    {
    	cout<<"Nhap khoi luong tui "<<i<<": ";
        cin >> a[i].w ;
		cout<<"Nhap gia tri tui "<<i<<": ";
		cin>> a[i].val;
    }
    show(n,W);
    cout << "ket qua : ";
    cout << Solve(n, W);
    Trace(n,W);
}
