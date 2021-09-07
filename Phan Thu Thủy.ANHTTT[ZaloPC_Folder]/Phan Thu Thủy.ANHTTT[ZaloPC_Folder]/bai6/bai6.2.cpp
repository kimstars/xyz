#include <iostream>
#define luongCoban 1300
#define max 10000
using namespace std;
// chưa làm trường hợp thêm hoặc bớt công nhân
class CNSX
{
private:
    string name;
    int soSanpham;

public:
    CNSX()
    {
    }
    CNSX(string name, int soSanpham)
    {
        this->name = name;
        this->soSanpham = soSanpham;
    }
    void nhap()
    {
        cout << "Nhap vao ten cnsx: ";
        fflush(stdin);
        getline(cin, this->name);
        cout << "Nhap vao so san pham: ";
        cin >> this->soSanpham;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setSoSanphan(int soSanpham)
    {
        this->soSanpham = soSanpham;
    }
    string getName()
    {
        return name;
    }
    int getSoSanpham()
    {
        return soSanpham;
    }
    double Salary()
    {
        return 500 * soSanpham;
    }
};
class CNHC
{
private:
    string name;
    double hesoLuong;

public:
    CNHC()
    {
    }
    CNHC(string name, double hesoLuong)
    {
        this->name = name;
        this->hesoLuong = hesoLuong;
    }
    void nhap()
    {

        cout << "Nhap vao ten cnhc: ";
        fflush(stdin);
        getline (cin, this->name);
        cout << "Nhap he so luong: ";
        cin >> this->hesoLuong;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setHesoLuong(double hesoLuong)
    {
        this->hesoLuong = hesoLuong;
    }
    string getName()
    {
        return name;
    }
    double gethesoLuong()
    {
        return hesoLuong;
    }
    double Salary()
    {
        return hesoLuong * luongCoban;
    }
};
class Employee
{
private:
    CNSX *cnsxs;
    CNHC *cnhcs;
    int n1;
    int n2;

public:
    Employee(int n1, int n2)
    {
        this->n1 = n1;
        this->n2 = n2;
    }
    Employee(CNSX *cnsxs, CNHC *cnhcs)
    {
        for (int i = 0; i < sizeof(cnsxs); i++)
        {
            this->cnsxs = cnsxs;
        }
        for (int i = 0; i < sizeof(cnhcs); i++)
        {
            this->cnhcs = cnhcs;
        }
    }
    void Nhap()
    { // n1 la so cnsx, n2 la so cnhcs
        cnsxs = new CNSX[n1];
        for (int i = 0; i < n1; i++)
        {
            cnsxs[i].nhap();
        }
        cnhcs = new CNHC[n2];
        for (int i = 0; i < n2; i++)
        {

            cnhcs[i].nhap();
        }
    }
    void minSalary()
    {
        int index1 = 0, index2 = 0;
        double min1 = cnsxs[0].Salary();
        for (int i = 0; i < n1; i++)
        {
            if (min1 > cnsxs[i].Salary())
            {
                min1 = cnsxs[i].Salary();
                index1 = i;
            }
        }
        double min2 = cnhcs[0].Salary();
        for (int i = 0; i < n2; i++)
        {
            if (min2 > cnhcs[i].Salary())
            {
                min2 = cnhcs[i].Salary();
                index2 = i;
            }
        }
        if (min1 > min2)
        {
            cout << "Nhan vien co luong thap nhat la: " << cnhcs[index2].getName() << " voi muc luong: " << cnhcs[index2].Salary() << endl;
        }
        else
        {
            cout << "Nhan vien co luong thap nhat la: " << cnsxs[index1].getName() << " voi muc luong: " << cnsxs[index1].Salary() << endl;
        }
    }
    double SumSalary()
    {
        double sum = 0;
        for (int i = 0; i < n1; i++)
        {
            sum += cnsxs[i].Salary();
        }
        for (int i = 0; i < n2; i++)
        {
            sum += cnhcs[i].Salary();
        }
        return sum;
    }
};
int main()
{
    Employee employee(2, 5);
    employee.Nhap();
    employee.minSalary();
    cout << " Quy ma cong ty phai chi tra la" << employee.SumSalary();
    /*  CNSX cnsx1;
    cnsx1.nhap();
    cnsx1.nhap();
    CNHC cnhc1;
    cnhc1.nhap();
     cnhc1.nhap();
      cnhc1.nhap(); */
}