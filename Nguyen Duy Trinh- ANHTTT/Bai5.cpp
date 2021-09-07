#include<iostream>
#include<string>
#include<math.h>
#include<vector>
using namespace std;
class Hinh{
    protected:
    double dientich;
    double chuvi;
};

class HinhTron: public Hinh{
    private:
    
    double bankinh;
    public:
    
    
    double TinhChuVi(){
         chuvi=bankinh*2*3.14;
         return chuvi;

    }
    double TinhDienTich(){
         dientich=bankinh*bankinh*3.14;
         return dientich;
    }
    void Nhap();
    void Xuat();


};
void HinhTron::Nhap(){
    cout<<"\n Nhap ban kinh hinh tron : ";
    cin>>bankinh;
}
void HinhTron::Xuat(){
    cout<<"\n Dien Tich Cua Hinh Tron La:  "<<TinhDienTich()<<endl;
    cout<<"\n Chu Vi Cua Hinh Tron La: "<<TinhChuVi()<<endl;

}
class HinhChuNhat:public Hinh{
    private:
    double chieudai;
    double chieurong;
    
    public:
    double TinhChuVi();
    double TinhDienTich();
    void Nhap();
    void Xuat();
};
double HinhChuNhat::TinhChuVi(){
    chuvi=chieudai+chieurong;
    return chuvi;
}
double HinhChuNhat::TinhDienTich(){
    dientich=chieudai*chieurong;
    return dientich;
}
void HinhChuNhat::Nhap(){
    cout<<"\n Nhap chieu dai HCN: ";
    cin>>chieudai;
    cout<<"\n Nhap chieu rong HCN: ";
    cin>>chieurong;
}
void HinhChuNhat::Xuat(){
    cout<<"\n Chu vi hinh chu nhat la: "<<TinhChuVi()<<endl;
    cout<<"\n Dien tich hinh chu nhat la: "<<TinhDienTich();
}

class HinhTamGiac:public Hinh{
    private:
    double canha;
    double canhb;
    double canhc;
    
    
    public:
    double TinhChuVi();
    double TinhDienTich();
    void Nhap();
    void Xuat();
};
double HinhTamGiac::TinhChuVi(){
    chuvi=canha+canhb+canhc;
    return chuvi;
}
double HinhTamGiac::TinhDienTich(){
    double a=chuvi/2;
    dientich=sqrt(a*(a-canha)*(a-canhb)*(a-canhc));
    return dientich;
}
void HinhTamGiac::Nhap(){
    cout<<"\n Nhap canh a:  ";
    cin>>canha;
    cout<<"\n Nhap canh b: ";
    cin>>canhb;
    cout<<"\n Nhap canh c: ";
    cin>>canhc;
}
void HinhTamGiac::Xuat(){
    cout<<"\n Chu Vi cua hinh tam giac la: "<<TinhChuVi()<<endl;
    cout<<"\n Dien tich cua hinh tam giac la: "<<TinhDienTich()<<endl;
}
class HinhHoc{
    private:
    vector<HinhTron> HT;
    vector<HinhChuNhat> HCN;
    vector<HinhTamGiac> HTG;
    public:
    void Nhap(){
         int LuaChon;
      do{
          cout<<"\n-------Menu-------------";
          cout<<"\n 1. Nhap Hinh Tron: ";
          cout<<"\n 2. Nhap Hinh Chu Nhat: ";
          cout<<"\n 3. Nhap Hinh Tam Giac: ";
          cout<<"\n 4.Thoat "<<endl;
        do{
            cout<<"\n Nhap lua chon: ";
            cin>>LuaChon;
            if(LuaChon<1 || LuaChon>4 )
            cout<<"\n Ban da nhap sai lua chon: ";
        }
        while(LuaChon<1 || LuaChon>4);
        if(LuaChon==1){
            HinhTron T;
            T.Nhap();
            HT.push_back(T);

        }
        else if (LuaChon==2){
            HinhChuNhat CN;
            CN.Nhap();
            HCN.push_back(CN);
        }
        else if (LuaChon==3){
            HinhTamGiac TG;
            TG.Nhap();
            HTG.push_back(TG);
        }
      }
      while(LuaChon!=4);
    }
    void Xuat(){
        cout<<"\n Hinh Tron: "<<endl;
    for(int i=0;i<HT.size();i++){
        HT[i].Xuat();
        cout<<endl;
    }
    cout<<"\n Hinh Chu Nhat: "<<endl;
    for(int i=0;i<HCN.size();i++){
        HCN[i].Xuat();
        cout<<endl;
    }
    cout<<"\n Hinh TAM Giac: "<<endl;
    for(int i=0;i<HTG.size();i++){
        HTG[i].Xuat();
    }
    }
    void TimKiem(){
        double max1=HT[0].TinhDienTich();
    for(int i=0;i<HT.size();i++){
        if(HT[i].TinhDienTich()> max1)
            max1=HT[i].TinhDienTich();
        
    }
    
    double max2=HCN[0].TinhDienTich();
    for(int i=0;i<HCN.size();i++){
        if(HCN[i].TinhDienTich()> max2)
        
            max2=HCN[i].TinhDienTich();
        
    }

     double max3=HTG[0].TinhDienTich();
    for(int i=0;i<HTG.size();i++){
        if(HTG[i].TinhDienTich()> max3)
        
            max3=HTG[i].TinhDienTich();
        
    }
    
    if(max1>=max2 && max1>=max3){
        for(int i=0;i<HT.size();i++){
        if(HT[i].TinhDienTich()==max1){
            cout<<"\n Hinh Tron Co Dien Tich Lon Nhat La: "<<endl;
            HT[i].Xuat();
        }
    }
    }
    if(max2>=max1 && max2>=max3 ){
        for(int i=0;i<HCN.size();i++){
        if(HCN[i].TinhDienTich()==max2){
            cout<<"\n Hinh Chu Nhat Co Dien Tich Lon Nhat la: "<<endl;
            HCN[i].Xuat();
        }
    }
    }
    if(max3>=max1 && max3>=max2){
        for(int i=0;i<HTG.size();i++){
        if(HTG[i].TinhDienTich()==max2){
            cout<<"\n Hinh Tam Giac Co Dien Tich Lon Nhat la: "<<endl;
            HTG[i].Xuat();
        }
    }
    }
    }

};


int main(){
    HinhHoc hh;
    hh.Nhap();
    hh.Xuat();
    hh.TimKiem();
    return 0;
}