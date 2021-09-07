#include<iostream>
#include<string>
using namespace std;
class CN
{
    private:
        string name;
        int age;
        long long luong;
    public:
    void nhap()
    {
        cout<<"Name: ";
        cin>>name;
        cout<<"Age:";
        cin>>age;
    }
    void xuat()
    {
        cout<<"\nName:"<<name;
        cout<<"\nAge:"<<age;
    }
};
class CNSX:public CN
{
    private:
    int sp;
    public:
    void nhap()
    {
        CN::nhap();
        {
            cout<<"so sp =\n";
            cin>>sp;
        }
    }
    void xuat()
    {
        CN::xuat();
        {
            cout<<"so sp =\n"<<sp;
        }
    }
    double luong()
    {
        return 5000*sp;
    } 
};
class CNHC:public CN
{
    private:
    int hsluong;
    public:
    void nhap()
    {
        CN::nhap();
        cout<<"hs luong =\n";
        cin>>hsluong;
    }
    void xuat()
    {
        CN::xuat();
        cout<<"hs luong =\n"<<hsluong;
    }
    double luong()
    {
        return hsluong*1400000;
    }
};
int main()
{
    int cn1,cn2; //cn1:cnsx;cn2:cnhc
    cout<<"so cn sx =";
    cin>>cn1;
    cout<<"so cn hc =";
    cin>>cn2;
    CNSX SX[cn1];
    CNHC HC[cn2];
    long long mnluong=99999999;
    long long  tongluong=0;
    for(int i=1;i<=cn1;i++)
    {
        cout<<"nhap CNSX["<<i<<"]:\n";
        SX[i].nhap();
    }
    for(int i=1;i<=cn1;i++)
    {
        if(SX[i].luong()<mnluong)
        {
            mnluong=SX[i].luong();
        }
        tongluong+=SX[i].luong();
    }
    for(int i=1;i<=cn2;i++)
    {
        cout<<"nhap CNHC["<<i<<"]\n";
        HC[i].nhap();
        if(HC[i].luong()<mnluong)
        {
            mnluong=HC[i].luong();
        }
        else continue;
        tongluong+=HC[i].luong();
    }
    cout<<"\nluong it nhat ="<<mnluong;
    cout<<"\ntong luong ="<<tongluong;
    return 0;
}