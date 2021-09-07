#include <iostream>
#include <vector>
#include <math.h>
#define n 100
using namespace std;

class Circle
{
private:
    double radius;

public:
    Circle()
    {
    }
    Circle(double radius)
    {
        this->radius = radius;
    }
    void setRadius(double radius)
    {
        this->radius = radius;
    }
    void nhap()
    {
        cout << "nhap ban kinh: ";
        cin >> this->radius;
    }
    double getRadius()
    {
        return radius;
    }
    double getArea()
    {
        return 3.14 * pow(radius, 2);
    }
};
class Triangle
{
private:
    double a;
    double b;
    double c;

public:
    Triangle()
    {
        this->a = 0;
        this->b = 0;
        this->c = 0;
    }
    Triangle(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void nhap(){
        cout << "Nhap vao lan luot do dai ba canh cua tam giac"<<endl;
        cout << "a: ";
        cin >> this->a;
        cout << "b: ";
        cin >>this->b ;
        cout << "c: ";
        cin >> this->c;
    }
    void setA(double a)
    {
        this->a = a;
    }
    void setB(double b)
    {
        this->b = b;
    }
    void setC(double c)
    {
        this->c = c;
    }

    double getA()
    {
        return a;
    }
    double getB()
    {
        return b;
    }
    double getC()
    {
        return c;
    }
    double getArea()
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Rectangular
{
private:
    double length;
    double width;

public:
    Rectangular()
    {
        this->length = 0;
        this->width = 0;
    }
    Rectangular(double length, double width)
    {
        this->length = length;
        this->width = width;
    }
    void nhap()
    {
        cout << "nhap chieu dai: ";
        cin >> this->length;
        cout << "Nhap chieu rong: ";
        cin >> this->width;
    }
    void setLength(double length)
    {
        this->length = length;
    }
    void setWidth(double width)
    {
        this->width = width;
    }
    double getLength()
    {
        return length;
    }
    double getWidth()
    {
        return width;
    }
    double getArea()
    {
        return length * width;
    }
};
int main(){

    Circle c[n];
    Rectangular r[n];
    Triangle t[n];
    int n1, n2, n3;
    cout << "Nhap vao so hinh tron:";
    cin >> n1;
    for(int i =0; i <n1; i++){
        //c= new Circle;
        c[i].nhap();
    }
    cout << "Nhap so hinh tam giac: ";
    cin >> n2;
    for(int i =0;i < n2; i ++){
        t[i].nhap();
    }
    cout <<"Nhap vao so hinh chu nhat:";
    cin >> n3;
    for(int i =0; i < n3; i++){
        r[i].nhap();
    }
    int index1=0, index2=0, index3=0;
    double max1=c[0].getArea();
    //cout << max1;
    for(int i = 0 ; i< n1; i++){
        if(max1 < c[i].getArea()){
            max1 = c[i].getArea();
            index1=i;
        }
    }
    double max2=t[0].getArea();
     for(int i = 0 ; i< n2; i++){
        if(max2 < t[i].getArea()){
            max2= t[i].getArea();
            index2=i;
        }
    } 
    double max3=r[0].getArea();
    for(int i = 0 ; i< n3; i++){
        if(max3 < r[i].getArea()){
            max3 = r[i].getArea();
            index3=i;
        }
    }
   if( max1 >= max2 && max1 >=max3){
       cout <<"Hinh co dien tich lon nhat la hinh tron co ban kinh: " <<c[index1].getRadius()<<endl;
   }
   else if(max2>=max3&&max2>=max1){
       cout <<"Hinh co dien tich lơn nhat la hinh tam giac co 3 canh  lan luot la: " << t[index2].getA()<<" "<< t[index2].getB() << " " << t[index3].getC();
   }
    else {
        cout <<"Hinh co dien tich lon nhat la hcn co chieu dai va chieu rong lan luot la: " << r[index3].getLength()<<" "<<r[index3].getWidth();
    }
}