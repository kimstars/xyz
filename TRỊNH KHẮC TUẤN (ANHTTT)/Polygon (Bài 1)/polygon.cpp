#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

typedef pair<int, int> ii;
#define X first
#define Y second

ii origin;
void operator-=(ii &A, ii B)
{
    A.X -= B.X;
    A.Y -= B.Y;
}
bool ccw(ii O, ii A, ii B)
{
    A -= O, B -= O;
    return A.X * B.Y > A.Y * B.X;
}
bool cmp(ii A, ii B) { return ccw(origin, A, B); }

int n;
ii a[12309];

int main()
{
    srand(time(NULL));
    cout << "Nhap so luong diem: ";
    cin >> n;

    if (n <= 2)
    {
        cout << "khong co bao loi\n";
        return 0;
    }
    cout << "Cac diem duoc tao ngau nhien la :" << endl;
    for (int i = 1; i <= n; i++)
    {
        a[i].X = rand() % 20 + 1;
        a[i].Y = rand() % 20 + 1;
        printf("%d %d\n", a[i].X, a[i].Y);
    }

    sort(a + 1, a + n + 1);
    origin = a[1];
    sort(a + 2, a + n + 1, cmp);
    a[0] = a[n];
    a[n + 1] = a[1];
    int j = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        while (j > 2 && !ccw(a[j - 2], a[j - 1], a[i]))
            j--;
        a[j++] = a[i];
    }
    n = j - 2;
    cout << "List cac diem bao loi\n";
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", a[i].X, a[i].Y);
}