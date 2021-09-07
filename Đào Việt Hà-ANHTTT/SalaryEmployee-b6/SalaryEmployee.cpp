// SalaryEmployee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Employee.h"
using namespace std;
int main()
{
    Ketoan kt;
    kt.nhap();
    kt.xuat();
    cout << "Nhan vien co MIn SALARY: " << endl;
    kt.minLuong();
    cout << "----------------------------"<<endl;
    kt.sumOfSalary();
    return 0;
}
