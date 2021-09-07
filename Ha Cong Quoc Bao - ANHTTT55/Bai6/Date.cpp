class Date {
private:
    int ngay;
    int thang;
    int nam;
public:
    void set() {
        cout << "Nhap ngay thang nam sinh " << endl;
        cout << "Nhap ngay: ";
        cin >> this->ngay;
        cout << "Nhap thang: ";
        cin >> this->thang;
        cout << "Nhap nam: " ;
        cin >> this->nam;
    }
    void get() {
        cout << setw(11) << right << this->ngay << "/";
        cout << setw(3) << right << this->thang << "/";
        cout << setw(4) << right << this->nam;
    }
};