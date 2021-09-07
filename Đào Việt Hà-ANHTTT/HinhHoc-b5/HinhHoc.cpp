#include "hinh.h"
#include <iostream>
using namespace std;
int main()
{

	htron htr;
	htr.nhap();
	htr.xuat();

	hcn cn;
	cn.nhap();
	cn.xuat();

	htamgiac tg;
	tg.nhap();
	tg.xuat();
	
	int max = 0;

	if (max <= htr.maxhtron()) max = htr.maxhtron();
	if (max <= cn.maxhcn()) max = cn.maxhcn();
	if (max <= tg.maxhtg()) max = tg.maxhtg();
	cout << "Hinh co dien tich lon nhat: " << max;
}



