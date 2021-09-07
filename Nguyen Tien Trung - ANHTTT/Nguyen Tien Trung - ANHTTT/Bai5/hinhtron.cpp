
class tron {
private:
    float bankinh;
public:
    void set() {
        cout << "Nhap ban kinh: ";
        cin >> this->bankinh;
    }

    float dientich() {
        return bankinh * bankinh * 3.14;
    }

    void get() {
        cout << setw(20) << right << "Tron";
        cout << setw(20) << right << this->bankinh;
        cout << setw(20) << right << dientich() << endl;
    }
};
