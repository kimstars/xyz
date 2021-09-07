#include <iostream>
#include <cmath>

using namespace std;

void listNumber(int i, int j);
void deleteNumber(int i, int j);
void print(int n);
bool check(int i, int j);
void tryE(int i);


int a[20][20] = {0};
bool ok[20][20] = {0};
int n = 8;
int X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main()
{
    a[5][5] = 1;

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            cout<<a[i][j];
        }
        cout<<"\n";
    }

    cout<<"------------------------------------------";
    
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (a[i][j])
            {
                for (int t = 0; t < 8; t++)
                {
                    int x = i + X[t];
                    int y = j + Y[t];
                    a[x][y] = 1;
                }
                goto LABEL1;
            }
        }
        cout<<"\n";
    }
LABEL1 :

    for (int i = 1; i <= 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            cout<<a[i][j];
        }
        cout<<"\n";
    }

    tryE(1);
    return 0;

}

void listNumber(int i, int j)
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

void deleteNumber(int i, int j)
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

void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<a[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
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

void tryE(int i)
{
    for (int k = 1; k < 8; k++)
    {
        if (check(k, i))
        {
            listNumber(k,i);
            cout <<" ok\n";
            tryE(i + 1);
            if (i <= 8)
                print(8);
            deleteNumber(k,i);
        }
    }
        
}