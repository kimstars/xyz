#include<iostream>
#include<math.h>
using namespace std;
#pragma once
class diem{
    private:
        int x;
        int y;
    public:
        diem(){};
        diem(int x,int y)
        {
            this->x=x;
            this->y=y;
        }
        void setdiem(int x, int y)
        {
        this->x = x;
        this->y = y;
        }
        void setX(int x)
        {
            this->x=x;
        }
        int getX()
        {
            return x;
        }
        void setY(int y)
        {
            this->y=y;
        }
        int getY()
        {
            return y;
        }
        
        void nhaptd()
        {
            cout<<"nhap td1 = "<<endl;cin>>x;
            cout<<"nhap td2 = "<<endl;cin>>y;
        }
        void xuattd()
        {
            cout<<"("<<x<<";"<<y;
        }
};