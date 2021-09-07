#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

#include "hinhtron.cpp"
#include "hinhchunhat.cpp"
#include "hinhtamgiac.cpp"



int main()  {
    int n1, n2, n3;
    tron t[1000];
    chuNhat cn[1000];
    tamGiac tg[1000];

    cout << endl << "So hinh tron la: ";
    cin >> n1;
    for(int i = 0; i < n1; i++) {
        cout << "Thong tin hinh tron thu " << i + 1 << endl;
        t[i].set();
    }

    cout << endl << "So hinh chu nhat la: ";
    cin >> n2;
    for (int i = n1; i < n1 + n2; i++) {
        cout << "Thong tin hinh chu nhat thu " << i + 1 - n1 << endl;
        cn[i].set();
    }

    cout << endl << "So hinh tam giac la: ";
    cin >> n3;
    for(int i = n1 + n2; i < n1 + n2 + n3; i++) {
        cout << "Nhap hinh tam giac thu " << i + 1 - n1 - n2 << endl;
        tg[i].set();
    }

    cout << "--------------------THONG TIN CAC HINH DA NHAP--------------------------" << endl;
    cout << setw(5) << right << "STT";
    cout << setw(20) << right << "LOAI HINH";
    cout << setw(20) << right << "KICH THUOC";
    cout << setw(20) << right << "DIEN TICH" << endl;

    float max1 = 0;
    int x1 = 0;
    for (int i = 0; i < n1; i++) {
        cout << setw(5) << right << i + 1;
        t[i].get();
        if (t[i].dientich() > max1) {
            x1 = i;
            max1 = t[i].dientich();
        }
    }

    float max2 = 0;
    int x2 = n1;
    for (int i = n1; i < n1 + n2; i++) {
        cout << setw(5) << right << i + 1;
        cn[i].get();
        if (cn[i].dientich() > max2) {
            x2 = i;
            max2 = t[i].dientich();
        }
    }

    float max3 = 0;
    int x3 = n1 + n2;
    for (int i = n1 + n2; i < n1 + n2 + n3; i++) {
        cout << setw(5) << right << i + 1;
        tg[i].get();
        if (tg[i].dientich() > max3) {
            x3 = i;
            max3 = tg[i].dientich();
        }
    }

    cout << endl << "Hinh co dien tich lon nhat la: " << endl;
    if (max1 >= max2 && max1 > max3) {
        cout << setw(5) << right << "1";
        t[x1].get();
        if(max1 == max2) {
            cout << setw(5) << right << "2";
            cn[x2].get();
        }
    } else if (max2 >= max3 && max2 > max1) {
        cout << setw(5) << right << "1";
        cn[x2].get();
        if(max2 == max3) {
            cout << setw(5) << right << "2";
            tg[x3].get();
        }
    } else if (max3 >= max1 && max3 > max2)  {
        cout << setw(5) << right << "1";
        tg[x3].get();
        if(max3 == max1) {
            cout << setw(5) << right << "2";
            t[x1].get();
        }
    } else {
        cout << setw(5) << right << "1";
        t[x1].get();
        cout << setw(5) << right << "2";
        cn[x2].get();
        cout << setw(5) << right << "3";
        tg[x3].get();
    }
    return 0;
}
