
class HinhTamGiac {
private:
    float a;
    float b;
    float c;
public:
    void set() {
        do {
            cout << "Nhap chieu dai canh thu 1: ";
            cin >> this->a;
            cout << "Nhap chieu dai canh thu 2: ";
            cin >> this->b;
            cout << "Nhap chieu dai canh thu 3: ";
            cin >> this->c;
            if ((a + b <= c) || (a + c <= b) || (b + c <= a)) {
                cout << "Nhap chieu dai cac canh sai! Nhap lai..." << endl;
            }
        } while ((a + b <= c) || (a + c <= b) || (b + c <= a));
    }

    float chuvi() {
        return (a + b + c); 
    }

    float dientich() {
        float p = chuvi() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void get() {
        cout << setw(20) << right << "Tam giac";
        cout << setw(10) << right << this->a << "*";
        cout << setw(4) << right << this->b << "*";
        cout << setw(4) << right << this->c;
        cout << setw(20) << right << dientich() << endl;
    }
};