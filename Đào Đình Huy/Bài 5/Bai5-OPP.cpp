#include<iostream>

using namespace std;
int k, n;
double m;

class Dovat{
    //lớp đồ vật gồm các thuộc tính tên, trọng lượng(kg) và giá trị(vnd)
    protected:
        string ten;
        double trongluong;
        double giatri;
    public:
        Dovat(){

        }
        Dovat(string ten, double trongluong, double giatri){
            this->giatri = giatri;
            this->trongluong = trongluong;
            this->ten = ten;
        }
        ~Dovat(){
            this->ten = "";
            this->trongluong = 0;
            this->giatri = 0;
        }

        double getDongia(){
            return giatri/trongluong;
        }

        double getTrongluong(){
            return trongluong;
        }
        double getGiatri(){
            return giatri;
        }
        string getName(){
            return ten;
        }

        friend istream &operator>>(istream &is, Dovat &obj){
            cout<<"Nhap ten: "; fflush(stdin); getline(cin, obj.ten);
            cout<<"Nhap trong luong: "; cin>>obj.trongluong;
            cout<<"Nhap gia tri do vat: "; cin>>obj.giatri;
        }

        friend ostream &operator<<(ostream &os, Dovat &obj){
            os<<"Ten: "<<obj.ten<<endl;
            os<<"Trong luong: "<<obj.getTrongluong()<<endl;
            os<<"Gia tri: "<<obj.getGiatri()<<endl;
        }
};

void swap(Dovat &a, Dovat &b){ 
    Dovat temp;
    temp = a;
    a = b;
    b = temp;
}

//sắp xếp các đồ vật thành dãy giảm dần theo đơn giá(giá trị/trọng lượng)
void BubbleSort(Dovat a[], int &n){
    for(int i = n - 1; i >= 1; i--){
        for(int j = 0; j < i; j++){
            if(a[j].getDongia() < a[j+1].getDongia()){
                swap(a[j], a[j+1]);
            }
        }
    }
}

//thuật toán tham ăn, trừ khối lượng cho phép m cho các trọng lượng của các đồ vật có đơn giá từ cao xuống thấp, sao cho chọn được nhiều đồ nhất
void Greedy(Dovat a[], int &n, double &m){
    double sum1 = 0;
    double sum2 = 0;
    cout<<endl<<"Cac do vat duoc chon: "<<endl;
    int i = 0;
    while( m >= 0){
        if(m/a[i].getTrongluong() < 1){
            i++;
            continue;
        }else if(m < 0){
            break;
        }else{
            m -= a[i].getTrongluong();
            cout<<a[i].getName()<<endl;
            sum1 += a[i].getTrongluong();
            sum2 += a[i].getGiatri();
        }
        i++;
    }

    cout<<"Tong trong luong: "<<sum1<<endl;
    cout<<"Tong gia tri: "<<sum2<<endl;
}

int main()
{
    cout<<"Nhap so do vat: ";
    cin>>n;
    Dovat *a = new Dovat[n];
    for(int i = 0; i < n; i++){
        cout<<"_______________"<<endl;
        cout<<"Nhap do vat "<<i+1<<endl;
        cin>>a[i];
    }
    cout<<"Nhap trong luong cho phep: ";
    cin>>m;

    BubbleSort(a, n);

    Greedy(a, n, m);

    return 0;
}
