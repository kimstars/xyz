
class chuNhat {
private:
    float dai;
    float rong;
public: 
    void set() {
        cout << "Nhap chieu dai: ";
        cin >> this->dai;
        cout << "Nhap chieu rong: ";
        cin >> this->rong;
    }

    float dientich() {
        return dai * rong;
    }

    void get() {
        cout << setw(20) << right << "Chu nhat";
        cout << setw(15) << right << this->dai << "*";
        cout << setw(4) << right << this->rong;
        cout << setw(20) << right << dientich() << endl;
    }
};
