#include "monhang.h"

class QuanLy
{
private:
    int n; //so loai hang
    int W; //can nang chi dinh
    vector<goiHang*> hang;
    long d[100][100];

public:
    QuanLy(){
        hang.resize(0);
        n = W = 0;
    }
    long chonHang(vector<goiHang*> &hang,int n, int W);
    void Feature();
    void Nhap(vector<goiHang*> &h);
    void Show();
    void Trace(long n, long W);
    void pressAnyKey();
};


long QuanLy::chonHang(vector<goiHang*> &hang, int n, int W)
{
    for (size_t i = 0; i <= n; i++) // trục gói hàng
    {
        for (size_t j = 0; j <= W; j++) // trục khối lượng max
        {
            if (i == 0 || j == 0)
                d[i][j] = 0;
            else if (j < hang[i]->canNang)
            {
                d[i][j] = d[i - 1][j]; // gói hàng được chọn có khối lượng lớn hơn cho phép
            }
            else
            {
                d[i][j] =  max(d[i - 1][j] , d[i - 1][j - hang[i]->canNang] + hang[i]->giaTri);
                // j >= a[i].w ---> gói hàng nhẹ hơn khối lượng cho phép, vẫn cho vào túi được.
                // max(d[i-1][j] , d[i-1][j - a[i].w] + a[i].val) kiểm tra xem bỏ vào túi thì giá trị có lớn hơn không, nếu không vẫn lấy cái cũ
                // d[i-1][j] giá trị hiện tại khi chọn gói hàng i-1 với khối lượng tối đa là j
            }
        }
    }
    return d[n][W];
}



void QuanLy::Nhap(vector<goiHang*> &hang){
    hang.resize(0);
    cout << "So loai hang mang theo: ";
    cin >> this->n;
    cout << "Can nang toi da cho phep: ";
    cin >> this->W;
    hang.push_back(new goiHang);
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap hang thu " << i << endl;
        hang.push_back(new goiHang);
        hang[hang.size()-1]->Nhap();
    }

}


void QuanLy::Show(){

    cout << "______________________________\n";
    cout <<"Cac goi hang ban da nhap la:\n";
    cout << left << setw(5) << "id" << " : "<< setw(10)<< "Ten"  << " : "<< setw(8) << "weight" << " : " << setw(8) << "value"  << endl;

    for (long i = 1; i <= n; i++)
    {
        cout << left << setw(5)<< i  << " : "<< setw(10)<< hang[i]->tenHang  << " : "<< setw(8) << hang[i]->canNang << " : " << setw(8)<< hang[i]->giaTri  << endl;
    }
    cout << "______________________________\n";
}


void QuanLy::Trace(long index, long W){
    int weight = W;

    cout << "\nCac chi so goi hang duoc chon: \n";
    while(index != 0){
        if(d[index][weight] != d[index-1][weight]){
            cout << index << " ";
            weight = weight - hang[index]->canNang; 
        }
        --index;
    }
    cout << endl;
}

void QuanLy::Feature(){
    cout << "Nhap danh sach goi hang.\n";
    Nhap(hang);
    pressAnyKey();


    int CatchKey;
    do
    {
        cout << "\n________________________________________________________\n";
        cout << "Lua chon : \n";
        cout << "\t Press 1. Nhap danh sach goi hang.\n";
        cout << "\t Press 2. Gia tri toi da nhan duoc.\n";
        cout << "\t Press 3. Danh sach goi hang da nhap.\n";
        cout << "\t Press 4. Danh sach goi hang can lua chon.\n";
        
        cout << "\t Press 0. Exit.\n";
        cout << "Press: ";

        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 0 && CatchKey != 4 )
        {
            cout << "\nNO FEATURE!\nAgain: ";
        }

        switch (CatchKey)
        {
        case 1:
            Nhap(hang);
            pressAnyKey();
            break;
        case 2:
            cout << "Ban co nhan gia tri toi da : ";
            cout << chonHang(hang,n,W) << endl;
            pressAnyKey();
            break;
        case 3:
            Show();
            pressAnyKey();
            break;
        case 4:
            Trace(n,W);
            pressAnyKey();
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (CatchKey != 0);
    cout << "Thanks!";
}


void QuanLy::pressAnyKey()
{
    system("pause");
    getchar();
    system("cls");
}