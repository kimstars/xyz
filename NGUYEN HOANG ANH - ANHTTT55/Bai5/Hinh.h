#pragma once 
#include <bits/stdc++.h>

using namespace std;

class Hinh{
    protected:
        double dientich;
    public:
        virtual string getName()=0;
        virtual void Nhap()=0;
        
        double getDienTich(){ return dientich;}
        virtual void Print(){
            cout <<fixed << setprecision(3)<< "Dien tich = " << dientich << endl;
        }
        virtual void setDienTich()= 0;
};