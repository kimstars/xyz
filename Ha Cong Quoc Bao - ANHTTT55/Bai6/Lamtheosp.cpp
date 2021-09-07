#include "Nguoi.cpp"

class Lamtheosp : public Nguoi {
private:
    int sosanpham;
public:
    void set() {
        Nguoi :: set();
        cout << "Nhap so san pham: ";
        cin >> this->sosanpham;
    }

    double tinhtien2() {
        return sosanpham * 5000;
    }

    void get() {
        Nguoi :: get();
        cout << setw(20) << right << this->sosanpham;
        cout << setw(10) << right << "5000";
        cout << setw(20) << right << tinhtien2() << endl;
    }
};