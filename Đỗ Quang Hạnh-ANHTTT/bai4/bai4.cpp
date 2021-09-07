#include <iostream>
#include <iomanip>
using namespace std;
int n, M;
struct Tui {
    int w = 0;
    int v = 0;
};
Tui a[200];
int dp[100][100];
int res = 0;
void xuat()
{
    for (int i = 1; i <= n; i++) {
        cout << setw(3) << i;
        cout << setw(10) << a[i].w;
        cout << setw(10) << a[i].v << endl; 
    }
}
void Solve() 
{
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= M; j++) 
        {
            if(j < a[i].w)
            {
                dp[i][j] = dp[i - 1][j];
            } else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].w] + a[i].v);
            }

            res = max(res, dp[i][j]);
        }
    }
}
void Trace(){
    while(n != 0){
        if(dp[n][M] != dp[n-1][M]){
            cout << n << " ";
            M = M - a[n].w; 
        }
        --n;
    }
}
int main() {
    cout << "Nhap so do vat da mua: ";
    cin >> n;
    cout << "Nhap khoi luong toi da: ";
    cin >> M;
    for (int i = 1; i <= n; i++) 
    {
        cout << endl;
        cout << "Nhap can nang do vat thu " << i << " : ";
        cin >> a[i].w;
        cout << "Nhap gia tri do vat thu " << i << " : ";
        cin >> a[i].v;
    }
    cout << setw(3) << "STT";
    cout << setw(10) << "GIA TRI";
    cout << setw(10) << "CAN NANG" << endl;
    xuat();
    Solve();
    cout << "Gia tri lon nhat la: " << res << endl;
    cout << "STT cua cac vat duoc chon la: " << endl;
    Trace();
    return 0;
}