#include <iostream>
#include <stdlib.h>
#include <time.h>
// chua xong
using namespace std;
int a[1000][1000];
int n, m;
int x, y;
bool ok[1000][1000]={0};
void xuat(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Timduong(int x, int y)
{ //x, y là vị trí đang đứng, m cột, n hàng
    if (a[x][y]==1)
    {
        cout << "Co min!" << endl;
    }
    else
    {
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
        {
            cout << "Chien thang!" << endl;
        }
        if (x < n - 1 && !a[x + 1][y]&& !ok[x + 1][y])
        {
            ok[x][y] = 1;
            cout << "("<<x<<", "<<y<<")-";
            Timduong(x + 1, y);
            ok[x][y] = 0;
        }
        if (y < m - 1 && !a[x][y + 1]&& !ok[x ][y+1])
        {
            ok[x][y] = 1;
            cout << "("<<x<<", "<<y<<")-";
            Timduong(x, y + 1);
            ok[x][y] = 0;
        }
        if (x > 0 && !a[x - 1][y]&& !ok[x-1 ][y])
        {
            ok[x][y] = 1;
            cout << "("<<x<<", "<<y<<")-";
            Timduong(x - 1, y);
            ok[x][y] = 0;
        }
        if (y > 0 && !a[x][y - 1]&& !ok[x ][y-1])
        {
            ok[x][y] = 1;
            cout << "("<<x<<", "<<y<<")-";
            Timduong(x, y - 1);
            ok[x][y] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    { // ma trận n*m
        for (int j = 0; j < m; j++)
        {

            a[i][j] = rand() % 2;
        }
    }
    xuat(n, m);
    cout <<"Nhap vao vi tri dang dung: ";
    cin >> x >> y;
    Timduong(x,y);
   
}