#include <iostream>
#include "diem.cpp"
using namespace std;

class hinhchunhat : public diem
{
protected:
    diem a;
    diem b;
    diem c;
    diem d;

public:
    hinhchunhat(){};
    hinhchunhat(diem a, diem b, diem c, diem d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    hinhchunhat(int x1, int x2, int y1, int y2)
    {
        a.setdiem(x1, y2);
        b.setdiem(x2, y2);
        c.setdiem(x2, y1);
        d.setdiem(x1, y1);
    }
    void nhaphinhchunhat()
    {
        int x1,x2,y1,y2;
        cout<<"nhap hoanh do 1"<<endl;
        cin>>x1;
        cout<<"nhap hoanh do 2"<<endl;
        cin>>x2;
        cout<<"nhap tung do 1"<<endl;
cin>>y1;
cout<<"nhap tung do 2"<<endl;
cin>>y2;
 a.setdiem(x1, y2);
        b.setdiem(x2, y2);
        c.setdiem(x2, y1);
        d.setdiem(x1, y1);
       
   
   
    }
    void xuathinhchunhat()
    {
        cout << "hinh chu nhat:" << endl;
         c.xuatdiem();
         cout<<"  ";d.xuatdiem();
        
cout<<endl;
         b.xuatdiem();
        cout<<"  ";
       a.xuatdiem();
       
    }
    float dientichCN(){
        return (d.getX()-c.getX())*(c.getY()-b.getY());
    }
};