#include<iostream>
#include<string>
#include<vector>
using namespace std;

class NhanVien{
	private:
		string name;
		int ID;
	public:
		virtual void getdata();
		virtual void display();
		virtual unsigned int tinhLuong()=0;	
};
void NhanVien::getdata(){
	cout << "\nNhap ID: "; cin>> ID;
	cout << "\nNhap ho va ten: ";fflush(stdin);getline(cin,name);
}
void NhanVien::display(){
	cout << "ID: " << ID;
	cout << "\nHo ten: " << name; 
}

class NhanVienSX:public NhanVien{
	private:
		int soSP;
	public:
	void getdata();
	void display();
	unsigned int tinhLuong();	
};
void NhanVienSX::getdata(){
	NhanVien::getdata();
	cout << "\nSo san pham: "; cin >> soSP;
}
unsigned int NhanVienSX::tinhLuong(){
	return soSP*5000;
}
void NhanVienSX::display(){
	NhanVien::display();
	cout << "\nSo san pham: " << soSP;
	cout << "\nTien luong: " << tinhLuong() << "\n";
}

class NhanVienHC:public NhanVien{
	private:
		int luongCB;
		int hesoLuong;
	public:
		void display();
		void getdata();
		unsigned int tinhLuong();		
};
void NhanVienHC::getdata(){
	NhanVien::getdata();
	cout << "\nNhap he so luong: ";cin>>hesoLuong;
	cout << "\nNhap luong co ban: "; cin>>luongCB;
}
unsigned int NhanVienHC::tinhLuong(){
	return hesoLuong*luongCB;
}
void NhanVienHC::display(){
	NhanVien::display();
	cout << "\nHe so luong: " << hesoLuong;
	cout << "\nLuong co ban: " << luongCB;
	cout << "\nTien luong: " << tinhLuong() << "\n";
}

struct Node{
	unsigned int luong;
	int vt;
	int kieu;
};
class QuanLyNV{
	private:
		vector<NhanVien*> nhanviensx;
		vector<NhanVien*> nhanvienhc;
	public:
		void themNV();
		void xuatNV();
		void tinhLuong();
		void search();	
};
void QuanLyNV::themNV(){
	NhanVien* nv;
	int choose;
	do{
		system("cls");
		cout << "\n1.Them nhan vien san xuat.";
		cout << "\n2.Them nhan vien hanh chinh.";
		cout << "\n3.Quay lai.";
		cin>>choose;
		switch(choose){
			case 1:
				nv=new NhanVienSX;
				nv->getdata();
				nhanviensx.push_back(nv);
				break;
			case 2:
				nv=new NhanVienHC;
				nv->getdata();
				nhanvienhc.push_back(nv);
				break;
			default:
				break;
		}
	} while (choose!=3);
}
void QuanLyNV::xuatNV(){
	int choose;
	do{
		system("cls");
		cout << "\n1.Xuat nhan vien san xuat.";
		cout << "\n2.Xuat nhan vien hanh chinh.";
		cout << "\n3.Quay lai.";
		cin>>choose;
		switch(choose){
		case 1:
			system("cls");
			cout << "\nDanh sach nhan vien san xuat." << endl;
			for (int i=0;i<nhanviensx.size();i++){
				nhanviensx[i]->display();
			}
			system("pause>pls");
			break;
		case 2:
			system("cls");
			cout << "\nDanh sach nhan vien hanh chinh." <<endl;
			for(int i=0;i<nhanvienhc.size();i++){
				nhanvienhc[i]->display();
			}
			system("pause>pls");
			break;
		default:
			break;
		}
	} while (choose !=3);
}
void QuanLyNV::tinhLuong(){
	unsigned int s1=0,s2=0,s;
	for(int i=0;i<nhanviensx.size();i++){
		s1+=nhanviensx[i]->tinhLuong();
	}
	for(int i=0;i<nhanvienhc.size();i++){
		s2+=nhanvienhc[i]->tinhLuong();
	}
	s=(s1+s2)*12;
	cout << "\nTong tien luong cong ty phai chi tra trong 1 nam la: " << s;
	system("pause>pls");
}
void QuanLyNV::search(){
	system("cls");
	Node node;
	cout << "\nNhan vien co luong thap nhat la: ";
	node.luong=nhanviensx[0]->tinhLuong();
	node.vt=0;
	node.kieu=1;
	for(int i=1;i<nhanviensx.size();i++){
		if(nhanviensx[i]->tinhLuong()<node.luong){
			node.luong=nhanviensx[i]->tinhLuong();
			node.vt=i;
			node.kieu=1;
		}
	}
	for(int i=0;i<nhanvienhc.size();i++){
		if(nhanvienhc[i]->tinhLuong()<node.luong){
			node.luong=nhanvienhc[i]->tinhLuong();
			node.vt=i;
			node.kieu=2;
		}
	}
	if(node.kieu=1){
		nhanviensx[node.vt]->display();
	} else if (node.kieu=2){
		nhanvienhc[node.vt]->display();
	}
	system("pause>pls");
}
void Menu(QuanLyNV quanlynhanvien){
	int choose;
	do{
		system("cls");
		cout << "\n1.Them nhan vien.";
		cout << "\n2.Xuat nhan vien.";
		cout << "\n3.Tinh luong 1 nam.";
		cout << "\n4.Nhan vien co luong thap nhat.";
		cout << "\n5.Thoat.";
		cin>>choose;
		switch(choose){
			case 1:
			quanlynhanvien.themNV();
			break;
			case 2:
			quanlynhanvien.xuatNV();
			break;
			case 3:
			quanlynhanvien.tinhLuong();
			break;
			case 4:
			quanlynhanvien.search();
			break;
			default:
			break;
		}
	} while (choose !=5);
}

int main(){
	QuanLyNV quanlynhanvien;
	Menu(quanlynhanvien);
	system("pause");
	return 0;
}