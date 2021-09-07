#pragma once
#include <iostream>
using namespace std;

class diem
{
private:
    int x;
    int y;

public:
    diem(){}
    diem(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setdiem(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    void setX(int x)
    {
        this->x = x;
    }
    int getY()
    {
        return y;
    }
    void setY()
    {
        this->y = y;
    }
    void nhapdiem()
    {
        cout << "nhap toa do x:" << endl;
        cin >> x;
        cout << "nhap toa do y:" << endl;
        cin >> y;
    }
    void xuatdiem()
    {
        cout << "(" << x << ";" << y << ")" ;
    }
};