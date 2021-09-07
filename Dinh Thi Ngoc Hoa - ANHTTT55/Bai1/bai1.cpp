//HCN va bao loi

#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x, y;
};

int n;
struct Point a[10000];

void input() {
	cout << "Nhap so diem trong toa do: ";
	cin >> n;
	cout << "Nhap toa do cac diem: " << endl;
	for (int i=0; i<n; i++) {
		cin >> a[i].x;
		cin >> a[i].y;
	}
}

void HCNmin() {
	if (n < 3) {
		cout << "---Khong tao duoc hinh chu nhat!---" << endl;
		return;
	}
	
	cout << "---Hinh chu nhat nho nhat co cac canh song song voi cac truc toa do chua tat ca cac diem co toa do 4 dinh la: " << endl;
	
	int maxX = a[0].x;
	int minX = a[0].x;
	int maxY = a[0].y;
	int minY = a[0].y;
	
	for (int i=0; i<n; i++) {
		if (a[i].x > maxX) maxX = a[i].x;
		if (a[i].x < minX) minX = a[i].x;
		if (a[i].y > maxY) maxY = a[i].y;
		if (a[i].y < minY) minY = a[i].y;
	}

	cout << "(" << minX << "," << minY << ")" << endl;
	cout << "(" << minX << "," << maxY << ")" << endl;
	cout << "(" << maxX << "," << maxY << ")" << endl;
	cout << "(" << maxX << "," << minY << ")" << endl;
}

int dinhHuong(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
}

void baoLoi()
{
    if (n < 3) {
    	cout << "---Khong tao duoc bao loi!---";
		return;	
	}
    vector<Point> bao;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (a[i].x < a[l].x)
            l = i;

    int p = l;
	int q;
    do {
        bao.push_back(a[p]);
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
           if (dinhHuong(a[p], a[i], a[q]) == 2)
               q = i;
        }
        p = q;
    } while (p != l);  
    cout << "---Cac dinh cua bao loi la: " << endl;
    for (int i = 0; i < bao.size(); i++)
        cout << "(" << bao[i].x << ", " << bao[i].y << ")" << endl;
}

int main()
{
	input();   
	HCNmin();
    baoLoi();
    return 0;
}
