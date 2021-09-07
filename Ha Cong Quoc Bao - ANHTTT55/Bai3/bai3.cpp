#include <bits/stdc++.h>
#include <cmath>
#include <fstream>

using namespace std;
vector<string> res;
int a[100][100];
bool ok[100][100] = {0};
bool check = false;   
int m, n;

void nhap(ifstream &filein, int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            filein >> a[i][j];
        }
    }
}

void xuat(ofstream &fileout, int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << "  ";
            fileout << a[i][j] << "  ";
        }
        cout << endl;
        fileout << endl;
    }
}



void Try(int i, int j, string s)
{
    if (a[i][j])
    {
        return;
    }
    else
    {
        if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
        {
            check = true;
            res.push_back(s);
            return;
        }

        if (i < n - 1 && !a[i + 1][j] && !ok[i + 1][j])
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

int main() {
    ifstream filein;
    ofstream fileout;
    filein.open("input.txt", ios_base :: in);                                                                         
    fileout.open("output.txt", ios_base :: out);

    int i, j;
    res.clear();
    cout << "Nhap ma tran a[m][n]" << endl;
    cout << "Nhap so hang m = ";
    cin >> m;
    cout << "Nhap so cot n = ";
    cin >> n;
    nhap(filein, a, m, n);
    xuat(fileout, a, m, n);
    
    do {
        cout << "Nhap vi tri can tim duong di a[i][j] " << endl;
        cout << "Nhap i = ";
        cin >> i;
        cout << "Nhap j = ";
        cin >> j;
        if (a[i][j] == 1) {
            cout << "Vi tri ban chon la bom. xin nhap lai!" << endl << endl;
        }
    } while (a[i][j] == 1);  

    Try(i, j, "");

    if (!res.size())
    {
        cout << "-1";
    }
    else
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Tu vi tri a[" << i <<"][" << j << "] so phuong an tim duoc la : " << res.size() << endl;
        fileout << "Tu vi tri a[" << i <<"][" << j << "] so phuong an tim duoc la : " << res.size() << endl;
        for (int i = 0; i < res.size(); i++)
        {
            cout << i + 1 << ". " <<  res[i] << endl;
            fileout << i + 1 << ". " <<  res[i] << endl;
        }
    }

    cout << "Xem chi tiet ket qua trong file output.txt" << endl;
    filein.close();
    fileout.close();

    return 0;
}