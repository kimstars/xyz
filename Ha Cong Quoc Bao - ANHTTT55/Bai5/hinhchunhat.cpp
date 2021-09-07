
class HinhChuNhat {
private:
    float chieudai;
    float chieurong;
public: 
    void set() {
        cout << "Nhap chieu dai: ";
        cin >> this->chieudai;
        cout << "Nhap chieu rong: ";
        cin >> this->chieurong;
    }

    float dientich() {
        return chieudai * chieurong;
    }

    void get() {
        cout << setw(20) << right << "Chu nhat";
        cout << setw(15) << right << this->chieudai << "*";
        cout << setw(4) << right << this->chieurong;
        cout << setw(20) << right << dientich() << endl;
    }
};