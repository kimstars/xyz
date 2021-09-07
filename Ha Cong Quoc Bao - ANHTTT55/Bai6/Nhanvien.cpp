#include "Nguoi.cpp"

class Nhanvien : public Nguoi{
private:
    double hesoluong;
public:
    void set() {
        Nguoi :: set();
        cout << "He so luong la: ";
        cin >> this->hesoluong;
    }

    double tinhtien1() {
        return hesoluong * 1300000;
    }

    void get() {
        Nguoi :: get();
        cout << setw(20) << right << this->hesoluong;
        cout << setw(10) << right << "1300000";
        cout << setw(20) << right << tinhtien1() << endl;
    }
};