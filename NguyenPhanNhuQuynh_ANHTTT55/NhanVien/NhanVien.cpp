#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;
class NgayThangNam
{
public:
	NgayThangNam();
	~NgayThangNam();
	friend istream& operator >>(istream &,NgayThangNam &);
	friend ostream& operator <<(ostream &,NgayThangNam);
private:
	int Ngay_,Thang_,Nam_;
};
NgayThangNam::NgayThangNam()
{
	Ngay_=Thang_=Nam_=0;
}
NgayThangNam::~NgayThangNam()
{
}
istream& operator >>(istream &is,NgayThangNam &ngay)
{
	cout<<"\nNhap Ngay :";is>>ngay.Ngay_;
	cout<<"\nNhap Thang :";is>>ngay.Thang_;
	cout<<"\nNhap Nam :";is>>ngay.Nam_;
	return is;
}
ostream& operator <<(ostream &os,NgayThangNam ngay)
{
	cout<<ngay.Ngay_<<"/"<<ngay.Thang_<<"/"<<ngay.Nam_<<endl;
	return os;
}
class NhanVien
{
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual unsigned int TinhTienLuong()=0;
protected:
	string HoTen_;
	NgayThangNam NgaySinh_;
	string DiaChi;
};
void NhanVien::Nhap()
{
	cout<<"\nNhap Ho Ten:";fflush(stdin);getline(cin,HoTen_);
	cout<<"\nNhap Ngay Sinh:";cin>>NgaySinh_;
	cout<<"\nNhap Dia Chi :";cin>>DiaChi;
}
void NhanVien::Xuat()
{
	cout<<"\nHo Ten:"<<HoTen_;
	cout<<"\nNgay Sinh:"<<NgaySinh_;
	cout<<"\nDia Chi:"<<DiaChi;
}
class NhanVienSX:public NhanVien
{
public:
	void Nhap();
	void Xuat();
	unsigned int TinhTienLuong();
private:
	int SoSanPham_;
};
void NhanVienSX::Nhap()
{
	NhanVien::Nhap();
	cout<<"\nNhap So San Pham:";cin>>SoSanPham_;
}
unsigned int NhanVienSX::TinhTienLuong()
{
	return SoSanPham_*5000;
}
void NhanVienSX::Xuat()
{
	NhanVien::Xuat();
	cout<<"\nSo San Pham:"<<SoSanPham_;
	cout<<"\nTien Luong:"<<TinhTienLuong();
}

 
class NhanVienHanhChinh:public NhanVien
{
public:
	void Nhap();
	void Xuat();
	unsigned int TinhTienLuong();
private:
	int LuongCoBan_;
	int HeSoLuong_;
};
void NhanVienHanhChinh::Nhap()
{
	NhanVien::Nhap();
	cout<<"\nNhap Luong Co ban:";cin>>LuongCoBan_;
	cout<<"\nNhap He So Luong:";cin>>HeSoLuong_;
}
unsigned int NhanVienHanhChinh::TinhTienLuong()
{
	return LuongCoBan_*HeSoLuong_;
}
void NhanVienHanhChinh::Xuat()
{
	NhanVien::Xuat();
	cout<<"\nLuong Co Ban:"<<LuongCoBan_;
	cout<<"\nHe So Luong:"<<HeSoLuong_;
	cout<<"\nLuong:"<<TinhTienLuong();
}
struct Node
{
	unsigned int luong;
	int vt;
	int kieu;
};
class QuanLyNhanVien
{
public:
	void ThemNhanVien();
	void XuatNhanVien();
	void TinhTienLuong();
	void TimNhanVien();
private:
	vector<NhanVien*> nhanviensx_;
	vector<NhanVien*> nhanvienhanhchinh_;
};
void QuanLyNhanVien::ThemNhanVien()
{
	NhanVien* nhanvien;
	int choose;
	do
	{
		system("cls");
		cout<<"\n1.Them Nhan Vien San Xuat.";
		cout<<"\n2.Them nhan vien hanh chinh.";
		cout<<"\n3.Quay Lai";
		cin>>choose;
		switch (choose)
		{
		case 1:
			{
				nhanvien=new NhanVienSX;
				nhanvien->Nhap();
				nhanviensx_.push_back(nhanvien);
			}
			break;
		
		case 2:
			{
				nhanvien=new NhanVienHanhChinh;
				nhanvien->Nhap();
				nhanvienhanhchinh_.push_back(nhanvien);
			}
			break;
		default:
			break;
		}
	} while (choose!=3);
}
void QuanLyNhanVien::XuatNhanVien()
{
	int choose;
	do
	{
		system("cls");
		cout<<"\n1.Xuat nhan vien san xuat.";
		cout<<"\n2.Xuat nhan vien hanh chinh.";
		cout<<"\n3.Quay Lai";
		cin>>choose;
		switch (choose)
		{
		case 1:
			{
				system("cls");
				cout<<"\nDanh sach nhan vien san xuat.";
				for(int i=0;i<nhanviensx_.size();i++)
				{
					nhanviensx_[i]->Xuat();
				}
				system("pause>pls");
			}
			break;
		case 2:
			
			{
				system("cls");
				cout<<"\nDanh sach nhan vien hanh chinh.";
				for(int i=0;i<nhanvienhanhchinh_.size();i++)
				{
					nhanvienhanhchinh_[i]->Xuat();
				}
				system("pause>pls");
			}
			break;
		default:
			break;
		}
	} while (choose!=3);
}
void QuanLyNhanVien::TinhTienLuong()
{
	int choose;
	unsigned int s1=0,s2=0;
	do
	{
		system("cls");
		cout<<"\n1.Tinh tong tien luong cua nhan vien san xuat.";
		cout<<"\n2.Tinh tong tien luong cua nhan vien hanh chinh.";
		cout<<"\n3.Tinh tong tien luong cua tat ca nhan vien.";
		cout<<"\n4.Quay Lai";
		cin>>choose;
		switch (choose)
		{
		case 1:
			{
				system("cls");
				for(int i=0;i<nhanviensx_.size();i++)
				{
					s1+=nhanviensx_[i]->TinhTienLuong();
				}
				cout<<"\n Tong tien luong cua nhan vien san xuat la.";
				cout<<"\nLuong:"<<s1;
				system("pause>pls");
			}
			break;
		case 2:
			{
				system("cls");
				for(int i=0;i<nhanvienhanhchinh_.size();i++)
				{
					s2+=nhanvienhanhchinh_[i]->TinhTienLuong();
				}
				cout<<"\n Tong tien luong cua nhan vien hanh chinh la.";
				cout<<"\nLuong:"<<s2;
				system("pause>pls");
			}
			break;
		
		case 3:
			{
				system("cls");
				cout<<"\nTong tien luong cua tat ca nhan vien la:";
				cout<<"\nTong Luong:"<<s1+s2;
				system("pause>pls");
			}
			break;
		default:
			break;
		}
	} while (choose!=4);
}
void QuanLyNhanVien::TimNhanVien()
{
	system("cls");
	Node node;
	cout<<"\nNhan vien co Luong Thap nhat la:";
	node.luong=nhanviensx_[0]->TinhTienLuong();
	node.vt=0;
	node.kieu=1;
	for(int i=1;i<nhanviensx_.size();i++)
	{
		if(nhanviensx_[i]->TinhTienLuong()<node.luong)
		{
			node.luong=nhanviensx_[i]->TinhTienLuong();
			node.vt=i;
			node.kieu=1;
		}
	}
	
	
	for(int i=0;i<nhanvienhanhchinh_.size();i++)
	{
		if(nhanvienhanhchinh_[i]->TinhTienLuong()<node.luong)
		{
			node.luong=nhanvienhanhchinh_[i]->TinhTienLuong();
			node.vt=i;
			node.kieu=2;
		}
	}
	if(node.kieu==1)
		nhanviensx_[node.vt]->Xuat();
	else if(node.kieu==2)
		nhanvienhanhchinh_[node.vt]->Xuat();
	cout<<"\nNhan vien co Luong cao nhat la:";
	node.luong=nhanviensx_[0]->TinhTienLuong();
	node.vt=0;
	node.kieu=1;
	for(int i=1;i<nhanviensx_.size();i++)
	{
		if(nhanviensx_[i]->TinhTienLuong()>node.luong)
		{
			node.luong=nhanviensx_[i]->TinhTienLuong();
			node.vt=i;
			node.kieu=1;
		}
	}
	
	
	for(int i=0;i<nhanvienhanhchinh_.size();i++)
	{
		if(nhanvienhanhchinh_[i]->TinhTienLuong()>node.luong)
		{
			node.luong=nhanvienhanhchinh_[i]->TinhTienLuong();
			node.vt=i;
			node.kieu=2;
		}
	}
	
	if(node.kieu==1)
		nhanviensx_[node.vt]->Xuat();
	else if(node.kieu==2)
		nhanvienhanhchinh_[node.vt]->Xuat();
	system("pause>pls");
}
void Menu(QuanLyNhanVien quanlynhanvien)
{
	int choose;
	do
	{
		system("cls");
		cout<<"\n1.Them Nhan vien.";
		cout<<"\n2.Xuat Nhan Vien.";
		cout<<"\n3.Tinh Luong.";
		cout<<"\n4.Nhan vien co luong thap nhat va cao nhat.";
		cout<<"\n5.Thoat!"<<"\n";
		cin>>choose;
		switch (choose)
		{
		case 1:
			quanlynhanvien.ThemNhanVien();
			break;
		case 2:
			quanlynhanvien.XuatNhanVien();
			break;
		case 3:
			quanlynhanvien.TinhTienLuong();
			break;
		case 4:
			quanlynhanvien.TimNhanVien();
			break;
		default:
			break;
		}
	} while (choose!=5);
}
int main()
{
	QuanLyNhanVien quanlynhanvien;
	Menu(quanlynhanvien);
	system("pause");
	return 0;
}
