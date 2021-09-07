
#include <iostream> // vì hậu ăn ngang, chéo, và dọc nên đặt được tối đa n quân hậu trên bàn cơ vua nxn
#include <math.h>
using namespace std;
int a[20]; //khoi tao mot mang bang 0;

bool check(int x, int y)
{ // x và y là vi tri quan hau
    for (int i = 0; i < x; i++)
    {
        if (a[i] == y || abs(i - x) == abs(a[i] - y))
            return false; // a[i]==y: quân hậu có thể ăn được theo cột y và theo đường chéo
    }
        return true;
}
void xuat1(int n) 
{
    cout << "\nBAN CO : \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == j)
                cout << " 1 ";
            else
                cout << " 0 ";
        }
        cout << "\n";
    }
}
void xuat2(int n)
{
    cout <<"Cach:\n" ;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i]<<" ";
    }
    xuat1(n);
    cout << "\n";
}

//thuật toán quay lui
void Try(int i, int n)
{
    for (int j = 1; j <= n; j++)
    { // các quân hậu được đặt thử từ cột 1 đến cột n
        if (check(i, j))
        {
            a[i] = j; // nếu đặt được thì lưu lại giá trị
            if (i == n)
                xuat2(n);
            Try(i + 1, n);
        }
    }
}
int main()
{
    Try(1, 8);
    return 0;
}
