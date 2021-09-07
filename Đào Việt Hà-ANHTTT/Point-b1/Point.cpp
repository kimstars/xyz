#include <iostream>
#include <vector>
using namespace std;

struct diem
{
    int x, y;
};

int n;
struct diem a[1000];

void nhap()
{
    cout << "Nhap so diem trong mat phang toa do: ";
    cin >> n;
    cout << "Nhap toa do cac diem (x,y): " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x;
        cin >> a[i].y;
    }
}

void minHcn()
{

    int minX= a[0].x;
    int minY = a[0].y;


    int maxX = a[0].x;
    int maxY = a[0].y;
    if (n <=3)
    {
        cout << "n <= 3 thi khong ton tai hinh chu nhat." << endl;
        return 0;
    }


    for (int i = 0; i < n; i++)
    {
        if (a[i].x > maxX) maxX = a[i].x;
        if (a[i].x < minX) minX = a[i].x;
        if (a[i].y > maxY) maxY = a[i].y;
        if (a[i].y < minY) minY = a[i].y;
    }
    cout << "Hinh chu nhat min co cac canh song song voi Ox, Oy : " << endl;
    cout<<"Ta co (minX, minY):" <<endl;
    cout << "(" << minX << "," << minY << ")" << endl;
    cout<<"Ta co (minX, maxY):" <<endl;
    cout << "(" << minX << "," << maxY << ")" << endl;
    cout<<"Ta co (maxX, maxY):" <<endl;
    cout << "(" << maxX << "," << maxY << ")" << endl;
    cout<<"Ta co (maxX, minY):" <<endl;
    cout << "(" << maxX << "," << minY << ")" << endl;
}

int orient(Point p1, Point p2, Point p3)
{
    int rel = (p2.y - p1.y) * (p3.x - p2.x) -
              (p2.x - p1.x) * (p3.y - p2.y);

    if (rel == 0) return 0;
    else if(rel>0) return 1;
    else return 2;
    //return (rel > )
}

void loi()
{
    if (n <= 3)
    {
        cout << "khong co bao loi!!!!";
        return;
    }
    vector<Point> hinhBaoLoi;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (a[i].x < a[l].x)
            l = i;

    int p1 = l;
    int p2;
    while (p1 != l)
    {
        hinhBaoLoi.push_back(a[p1]);
        p2 = (p1 + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (orient(a[p1], a[i], a[p2]) == 2)
                p2 = i;
        }
        p1 = p2;
    }
    while (p1 != l);
    cout << "Dinh loi can tim la: " << endl;
    for (int i = 0; i < hinhBaoLoi.size(); i++)
        cout << "(" << hinhBaoLoi[i].x << ", " << hinhBaoLoi[i].y << ")" << endl;
}

int main()
{
    input();
    minHcn();
    cout << "--------------------------" << endl;
    loi();
    return 0;
}
