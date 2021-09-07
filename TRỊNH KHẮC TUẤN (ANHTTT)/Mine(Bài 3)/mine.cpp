#include <bits/stdc++.h>
#include <cmath>

using namespace std;
vector<string> res;
int a[100][100] = {0};
bool ok[100][100] = {0};
bool check = false;
int m, n;
int x, y;

void nhapMang()
{
    cout << "Nhap kich thuoc ma tran : (m,n) ";
    cin >> m >> n;
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            a[i][j] = rand() % 2;
        }
    }
}

void inMang(int m, int n)
{
    cout << "______________________" << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "______________________" << endl;
    cout << endl;
}

void Test(int i, int j, string s)
{
    if (a[i][j])
    {
        cout << "This's Trap'! you die\n";
        return;
    }
    else
    {
        if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
        {
            check = true;
            res.push_back(s);
            return;
        }

        if (i < m - 1 && !a[i + 1][j] && !ok[i + 1][j])
        {
            ok[i][j] = 1;
            Try(i + 1, j, s + "D"); //down
            ok[i][j] = 0;
        }

        if (j < n - 1 && !a[i][j + 1] && !ok[i][j + 1])
        {
            ok[i][j] = 1;
            Try(i, j + 1, s + "R"); // right
            ok[i][j] = 0;
        }

        if (j > 0 && !a[i][j - 1] && !ok[i][j - 1])
        {
            ok[i][j] = 1;
            Try(i, j - 1, s + "L"); //left
            ok[i][j] = 0;
        }

        if (i > 0 && !a[i - 1][j] && !ok[i - 1][j])
        {
            ok[i][j] = 1;
            Try(i - 1, j, s + "T"); // top
            ok[i][j] = 0;
        }
    }
}

void inToado()
{
    for (int i = 0; i < res.size(); i++)
    {
        int a = y, b = x;
        string t = res[i];
        for (int j = 0; j < t.length(); j++)
        {
            if (t[j] == 'D')
            {
                cout << "(" << a << "," << b + 1 << ") ";
                b++;
            }

            if (t[j] == 'T')
            {
                cout << "(" << a << "," << b - 1 << ") ";
                b--;
            }

            if (t[j] == 'R')
            {
                cout << "(" << a + 1 << "," << b << ") ";
                a++;
            }

            if (t[j] == 'L')
            {
                cout << "(" << a - 1 << "," << b << ") ";
                a--;
            }
        }
        cout << endl;
    }
}

void inHuong()
{
    cout << "(Diem hien tai se la diem bat dau ban di)\n(D: Down, T: Top, L: Left, R: Right)\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}

int main()
{
    srand(time(0));
    res.clear();

    nhapMang();

    inMang(m, n);
    cout << "nhap vi tri hien tai (j : so cot, i : so hang ):";
    cin >> y >> x;

    Test(x, y, "");

    if (!res.size())
    {
        cout << "lewlew";
    }
    else
    {
        cout << "So phuong an tim duoc la : " << res.size() << endl;
        int k;
        do
        {
            cout << "Chon kieu in ra ket qua:\n";
            cout << "1. In theo toa do\n";
            cout << "2. In theo huong (D: Down, T: Top, L: Left, R: Right) \n";
            cout << "3. Show ma tran \n";
            cout << "0. Thoat \n";
            cout << "> ";
            while (cin >> k && k != 1 && k != 2  && k != 3 && k != 0)
            {
                cout << "\nNO FEATURE!\nAgain: ";
            }
            switch (k)
            {
            case 1:
                inToado();
                system("pause");
                system("cls");
                continue;

            case 2:
                inHuong();
                system("pause");
                system("cls");
                continue;
             case 3:
                inMang(m,n);
                system("pause");
                system("cls");
                continue;
            case 0:
                cout << "Tam biet\n";
                break;
            default:
                break;
            }
        }while(k != 0);
    }
}
