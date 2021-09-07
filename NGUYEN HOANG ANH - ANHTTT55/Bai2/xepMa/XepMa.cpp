#include <iostream>
#include <cmath>

using namespace std;
int a[20][20] = {0};
bool ok[20][20] = {0};
int n = 8;

int X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void danhso(int i, int j)
{
    ok[i][j] = 1;
    for (int t = 0; t < 8; t++)
    {
        int x = i + X[t];
        int y = j + Y[t];
        if (x < n && x >= 0 && y < n && y >= 0 && ok[x][y] == 0)
        {
            ok[x][y] = 2;
        }
    };
}

void huyso(int i, int j)
{
    ok[i][j] = 0;
    for (int t = 0; t < 8; t++)
    {
        int x = i + X[t];
        int y = j + Y[t];
        if (x < n && x >= 0 && y < n && y >= 0 && ok[x][y] == 0)
        {
            ok[x][y] = 0;
        }
    };
}

void Print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool check(int i, int j)
{
    for (int t = 0; t < 8; t++)
    {
        int x = i + X[t];
        int y = j + Y[t];
        if (x >= n || x < 0 || y >= n || y < 0 || a[x][y] || ok[x][y] )
        {
            return false;
        }
    };
    return true;
}

void Try(int i)
{
    for (int k = 1; k < 8; k++)
    {
        if (check(k, i))
        {
            danhso(k,i);
            cout <<" ok\n";
            Try(i + 1);
            if (i <= 8)
                Print(8);
            huyso(k,i);
        }
    }
        
}

int main()
{
    Try(1);
    return 0;
}