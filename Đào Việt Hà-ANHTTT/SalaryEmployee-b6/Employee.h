#include <string>
#include <iostream>
#include<vector>
using namespace std;

class NhanVien
{
protected:
    string hoTen;
    double luong;

public:
    NhanVien()
    {
        this->hoTen = "";
        this->luong = 0.0;
    }

     virtual void nhap()
    {
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, this->hoTen);
    }

     virtual void xuat()
    {
        cout << "Ho ten: ";
        cout << this->hoTen << endl;
    }

    virtual double tinhLuong() = 0;
};
class Employee : public NhanVien
{
private:
    int soSP;
    double tien1SP;

public:
    Employee() : NhanVien()
    {
        this->soSP = 0;
        this->tien1SP = 5000;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "So san pham cong nhan lam duoc : ";
        cin >> this->soSP;
        cout << "Tien cong 1 san pham: " << this->tien1SP << endl;
    }

    void xuat()
    {
        cout << "So san pham: ";
        cout << this->soSP << endl;
        cout << "Tien cong 1 san pham: ";
        cout << this->tien1SP << endl;
        cout << "Luong: "<< this->tinhLuong()<< endl;
        //cout << this->luong << endl;
    }
    double tinhLuong()
    {
        return this->luong = this->soSP * this->tien1SP;
    }
    
    
 
};
class Staff : public NhanVien
{
private:
    double luongCoBan;
    float heso;
 

public:
    Staff() : NhanVien()
    {
        this->luongCoBan = 13000;
        this->heso = 0.0;
    }

    void nhap()
    {
        NhanVien::nhap();
        cout << "Luong co ban : "<< this->luongCoBan<< endl;
        cout << "He so luong : ";
        cin >> this->heso;
    }

    void xuat()
    {
        NhanVien::xuat();
        cout << "Luong co ban : " << this->luongCoBan << endl;
        cout << "He so luong : ";
        cout << this->heso << endl;
        cout << "Luong cua Staff : "<< this->tinhLuong() << endl;
       // cout << this->luong << endl;
    }
    double tinhLuong()
    {
        return this->luong = (this->heso) * (this->luongCoBan);
        
    }
};

class Ketoan {
private:
    vector<NhanVien*>nv;
public:
    void nhap() {
        cout << "Nhap so nhan vien: ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Staff: nhap '1', Employee: nhap '2' : ";
            int k;
            cin >> k;
            NhanVien* nv;
            
            if (k == 1)
                nv = new Staff;
            else
                nv = new Employee;
            nv->nhap();    
            this->nv.push_back(nv);
            cout << endl;
        }
    }
    void xuat() {
        int j = 0;
        cout << "Nhan Vien: " << endl;
        for(int i = 0; i< this->nv.size(); i++){
            cout << "STT :"<< j+1 << endl;
            this->nv.at(i)->xuat();
            j++;
            cout << endl;
            cout << "----------------------------------"<<endl;
        }

    }
    void minLuong() {
        double min = this->nv.at(0)->tinhLuong();
        int dem;
        for (int i = 0; i < this->nv.size(); i++) {
            if (min >= this->nv.at(i)->tinhLuong()) {
                min = this->nv.at(i)->tinhLuong();
                dem = i;
            }
        }
        cout << "Voi min Salary: " << min << endl;
        cout << "Ly lich:"<< endl;
        this->nv.at(dem)->xuat();
    }
    void sumOfSalary() {
        double sum = 0;
        for (int i = 0; i < this->nv.size(); i++) {
            sum += this->nv.at(i)->tinhLuong();
        }
        cout << "Tong so tien ma Ke toan phai tra cho Nhan vien:" << sum << endl;
    }
};
