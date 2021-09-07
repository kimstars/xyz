#include<iostream>
#include<string>
#include<vector>
using namespace std;
class CongNhan{
    protected:
    string HoTen, NgaySinh;
    float LuongCoBan, Luong;
    public:
    void Nhap(){
        fflush(stdin);
        cout<<"\n Nhap ho ten: ";
        getline(cin,HoTen);
        fflush(stdin);
        cout<<"\n Nhap vao ngay sinh: " ;
        getline(cin,NgaySinh);
    };
    void Xuat(){
        cout<<"\n Ho ten: "<<HoTen;
        cout<<"\n Ngay Sinh: "<<NgaySinh;
        
    }
};

class CongNhanSX:public CongNhan {
   int SoNgayLamViec;
   public:
   void Nhap(){
       CongNhan::Nhap();
       cout<<"\n So ngay lam viec: ";
       cin>>SoNgayLamViec;
   }
   void Xuat(){
       CongNhan::Xuat();
       cout<<"\n So ngay lam viec: "<<SoNgayLamViec;
   }
   double TinhLuong();

};
double CongNhanSX::TinhLuong(){
   Luong=5000*SoNgayLamViec;
   return Luong;
}
class CongNhanHC:public CongNhan{
    private:
    double HeSoLuong;
    public:
    void Nhap(){
        CongNhan::Nhap();
        cout<<"\n He so luong: ";
        cin>>HeSoLuong;
    }
    void Xuat(){
        CongNhan::Xuat();
        cout<<"\n He so luong:  "<<HeSoLuong<<endl;
    }
    double TinhLuong();
};
double CongNhanHC::TinhLuong(){
    Luong=HeSoLuong*1400000;
    return Luong;
}
class CongTy{
  vector<CongNhanSX> CNSX;
  vector<CongNhanHC> CNHC;
  public:
  void Nhap(){
      int LuaChon;
      do{
          cout<<"\n-------Menu-------------";
          cout<<"\n 1. Nhap Cong nhan San Xuat: ";
          cout<<"\n 2. Nhap cong nhan Hanh Chinh: ";
          cout<<"\n 3. Thoat"<<endl;
        do{
            cout<<"\n Nhap lua chon: ";
            cin>>LuaChon;
            if(LuaChon<1 || LuaChon>3 )
            cout<<"\n Ban da nhap sai lua chon: ";
        }
        while(LuaChon<1 || LuaChon>3);
        if(LuaChon==1){
            CongNhanSX SX;
            SX.Nhap();
            CNSX.push_back(SX);

        }
        else if (LuaChon==2){
            CongNhanHC HC;
            HC.Nhap();
            CNHC.push_back(HC);
        }
      }
      while(LuaChon!=3);
  }
  void Xuat(){
      cout<<"\n Danh Sach Cong nhan San Xuat: "<<endl;
      for(int i=0;i< CNSX.size();i++){
          CNSX[i].Xuat();
          cout<<endl;
      }
      cout<<"\n Danh Sach conh nhan HANH CHINH: "<<endl;
      for(int i=0;i<CNHC.size();i++){
          CNHC[i].Xuat();
      }
  }
  float TinhTongLuong();
  void TimKiem();
};
void CongTy::TimKiem(){
    
    float min1=CNSX[0].TinhLuong();
    for(int i=0;i<CNSX.size();i++){
        if(CNSX[i].TinhLuong()< min1)
            min1=CNSX[i].TinhLuong();
        
    }

    float min2=CNHC[0].TinhLuong();
    for(int i=0;i<CNHC.size();i++){
        if(CNSX[i].TinhLuong()< min2)
        
            min2=CNHC[i].TinhLuong();
        
    }
    if(min1<=min2){
         for(int i=0;i<CNSX.size();i++){
        if(CNSX[i].TinhLuong()==min1){
            cout<<"\n CONG nhan san xuat co muc luong nho nhat la: ";
            CNSX[i].Xuat();
        }
    }
    }
    if(min2<min1){
         for(int i=0;i<CNHC.size();i++){
        if(CNHC[i].TinhLuong()==min2){
            cout<<"\n Cong Nhan Hanh Chinh Co muc luong nho nhat la: ";
            CNHC[i].Xuat();
        }
    }
    }
}
float CongTy::TinhTongLuong(){
    float Tong=0;
    for(int i=0;i<CNSX.size();i++){
        Tong+=CNSX[i].TinhLuong();
    }
    for(int i=0;i<CNHC.size();i++){
        Tong+=CNHC[i].TinhLuong();
    }
    return Tong;

}
int main(){
    CongTy CT;
    CT.Nhap();
    CT.Xuat();
    cout<<"\n Tong luong Cong Ty = "<<(size_t)CT.TinhTongLuong()<<endl;
    
    CT.TimKiem();
    return 0;
}