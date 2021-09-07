#include "HanhChinh.h"
#include "SanXuat.h"

class CongTy
{
private:
    vector<NhanVien *> NV;
    long tongluong;

public:
    CongTy()
    {
        NV.resize(0);
        tongluong = 0;
    }
    void ListFeature();
    void Nhap(vector<NhanVien *> &NV);
    void InputMore(vector<NhanVien *> &NV);
    void Xuat();
    void tongLuong();
    void XoaNV(vector<NhanVien *> &NV, int i);
    void LoadSalary(vector<NhanVien *> &NV);
    void Khac(vector<NhanVien *> &NV);
    void pressAnyKey();
};

void CongTy::ListFeature()
{
    int CatchKey;
    do
    {
        cout << "\n________________________________________________________\n";
        cout << "Quan ly nhan su: \n";
        cout << "\t Press 1. Them mot nhan vien.\n";
        cout << "\t Press 2. Them nhieu nhan vien.\n";
        cout << "\t Press 3. Danh sach nhan vien.\n";
        cout << "\t Press 4. Tong luong phai chi tra cho nhan vien.\n";
        cout << "\t Press 5. Xoa mot nhan vien theo id.\n";
        cout << "\t Press 6. Khac\n";
        cout << "\t Press 0. Exit.\n";
        cout << "Press:";

        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 0 && CatchKey != 4 && CatchKey != 5 && CatchKey != 6)
        {
            cout << "\nNO FEATURE!\nAgain: ";
        }

        switch (CatchKey)
        {
        case 1:
            Nhap(NV);
            break;

        case 2:
            InputMore(NV);
            break;
        case 3:
            Xuat();
            break;
        case 4:
            tongLuong();
            break;
        case 5:
            Xuat();
            cout << "\n______________________________\n";
            int i;
            while (1)
            {
                cout << "Nhap id nhan vien muon xoa\n";
                cin >> i;
                string name = NV[i]->getName();
                if (name == "")
                {
                    cout << "Khong co id do!!\n";
                }
                else
                {
                    break;
                }
            }
            XoaNV(NV, i);

            break;
        case 6:
            Khac(NV);
            break;
        default:
            break;
        }
    } while (CatchKey != 0);
    cout << "Thanks!";
}

void CongTy::InputMore(vector<NhanVien *> &NV)
{
    int n;
    cout << "Ban muon nhap bao nhieu nhan vien ?\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhan vien thu " << i + 1 << endl;
        Nhap(NV);
    }
}

void CongTy::Nhap(vector<NhanVien *> &NV)
{
    int temp = 0;
    while (1)
    {
        cout << endl
             << "Loai nhan vien : " << endl;
        cout << " 1. Nhan vien van phong." << endl;
        cout << " 2. Nhan vien san xuat." << endl;
        cout << " 3. Thoat" << endl;
        cout << "Chon : ";
        while (cin >> temp && temp != 1 && temp != 2 && temp != 3)
        {
            cout << "\nJust press 1,2 or 3!\nAgain: ";
        }
        cout << "___________________________________________\n";
        switch (temp)
        {
        case 1:
            cout << "nhan vien van phong : " << endl;
            NV.push_back(new HanhChinh());
            NV[NV.size() - 1]->Nhap();
            tongluong += NV[NV.size() - 1]->GetSalary();
            pressAnyKey();
            return;
            break;
        case 2:
            cout << "nhan vien san xuat :" << endl;
            NV.push_back(new SanXuat());
            NV[NV.size() - 1]->Nhap();
            tongluong += NV[NV.size() - 1]->GetSalary();
            pressAnyKey();
            return;
            break;
        case 3:
            cout << "Ban chon thoat. Tam biet\n";
            getchar();
            return;
        default:
            break;
        }
    }
}

void CongTy::Xuat()
{
    cout << endl
         << "DANH SACH NHAN VIEN CONG TY" << endl;

    cout << left << setw(5) << "id" << setw(15) << "Loai NV" << setw(30) << "Ho va Ten" << setw(30) << "Luong" << endl;
    for (int i = 0; i < NV.size(); i++){
        cout << left << setw(5) << i;
        NV[i]->Print();
    }
    cout << endl;
}

void CongTy::XoaNV(vector<NhanVien *> &NV, int i)
{
    string name = NV[i]->getName();
    char c;
    while (1)
    {
        cout << "Ban co cach xoa " << name << " khoi danh sach nhan vien cong ty ?(y/n) \n";
        cin >> c;
        if (c == 'y')
            break;
    }
    NV.erase(NV.begin() + i);
    cout << "Ban vua xoa " << name << " khoi danh sach nhan vien cong ty !!\n";
    LoadSalary(NV);
}

void CongTy::LoadSalary(vector<NhanVien *> &NV)
{
    long temp = 0;
    for (int i = 0; i < NV.size(); i++)
    {
        temp += NV[i]->GetSalary();
    }
    tongluong = temp;
}

void CongTy::tongLuong()
{
    cout << "Tong so luong cong ty phai chi tra cho nhan vien la: ";
    cout << tongluong << endl;
}

void CongTy::Khac(vector<NhanVien *> &NV){
    int temp;
    while(1){
        cout << "\n________________________________________________________\n";
        cout << "Chuc nang KHAC: \n";
        cout << "\t Press 1. NHAN VIEN LUONG CAO NHAT ?.\n";
        cout << "\t Press 2. NHAN VIEN LUONG THAP NHAT?.\n";
        cout << "\t Press 0. THOAT.\n";
         while (cin >> temp && temp != 1 && temp != 2 && temp != 0)
        {
            cout << "\nJust press 1,2 or 3!\nAgain: ";
        }
        cout << "___________________________________________\n";
        int indexmax, indexmin;
        long max = NV[0]->GetSalary();
        long min = NV[0]->GetSalary();

        for (size_t i = 0; i < NV.size(); i++)
        {
            long temp1 = NV[i]->GetSalary();
            if(max < temp1){
                max = temp1;
                indexmax = i;
            }

            long temp2 = NV[i]->GetSalary();
                if(min > temp2){
                    min = temp2;
                    indexmin = i;
                }
        }
        switch (temp)
        {
        case 1:
            cout << NV[indexmax]->getName() << "---------> Salary : "<< max << endl;
            pressAnyKey();
            break;
        case 2:
            cout << NV[indexmin]->getName() << "---------> Salary : "<< min << endl;
            pressAnyKey();
            return;
            break;
        case 0:
            cout << "Ban chon thoat. Tam biet\n";
            getchar();
            return;
        default:
            break;
        }
    }

}



void CongTy::pressAnyKey()
{
    printf("\n\nBam phim bat ky de tiep tuc...");
    getchar();
    system("cls");
}