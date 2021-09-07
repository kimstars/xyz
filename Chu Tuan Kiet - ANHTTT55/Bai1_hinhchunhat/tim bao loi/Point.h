#pragma once
#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
    Point(){x=y=0;}
    Point(int x, int y):x(x),y(y){};

    void operator=(const Point &p)
    {
        x = p.x;
        y = p.y;
    }

    Point operator-(const Point &p)
    {
        Point a;
        a.x = x - p.x;
        a.y = y - p.y;
        return a;
    }
    Point operator+(const Point &p)
    {
        Point a;
        a.x = x + p.x;
        a.y = y + p.y;
        return a;
    }


    bool operator>(const Point &p)
    {
        if (y == p.y)
        {
            return x > p.x;
        }
        else
        {
            return y > p.y;
        }
    }

    void operator-=(const Point &p)
    {
        x -= p.x;
        y -= p.y;
    }
    void operator+=(const Point &p)
    {
        x += p.x;
        y += p.y;
    }

    friend ostream &operator<<(ostream &, Point &p)
    {
        cout << "x=" << p.x << "; y = " << p.y << endl;
    }
    friend istream &operator>>(istream &, Point &p)
    {
        cout << "Nhap toa do x :";
        cin >> p.x;
        cout << "Nhap toa do y:";
        cin >> p.y;
    }

    void show(){
        cout << "("<<x<<","<<y<<")\n";
    }
};