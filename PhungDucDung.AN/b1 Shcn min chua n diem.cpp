#include<iostream>
#include<math.h>
using namespace std;
#define N 100

void nhap(int a[], int b[], int &n){
	do{
		cout<<"Nhap so diem: ";
		cin>>n;
		if(n<0 || n>N){
			cout<<"\nKiem tra lai dieu kien ";
		}
	}
	while(n<0 || n>N);
	cout<<endl;
	for(int i=0; i<n; i++){
		
		cout<<"Nhap toa do M"<<i<<"(x"<<i<<" ; y"<<i<<"): "; //nhap  thong tin toa do
		cin>>a[i]>>b[i];
	}
}
void xuat(int a[],int b[], int n){
	cout<<endl;
	for(int i=0; i<n;i++){
		cout<<"M"<<i<<"("<<a[i]<<";"<<b[i]<<")" "  "; //xuat toa do
	}
}

int distance(int a[], int n){
	int max=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n; j++){
			if(max<abs(a[i]-a[j])){
				max=abs(a[i]-a[j]); //tim k/c lon nhat giua cac phan tu trong mang
			}	
		}
	}	
	return max;
}
void xuatToaDo(int a[], int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" "; //xuat tap hop cac toa do
	}
	cout<<endl;
}
int main(){
	int a[N], b[N],n;
	nhap(a,b,n);
	xuat(a,b,n); 
	cout<<endl;
	cout<<"\nMang tap hop x tren truc hoanh: ";
	xuatToaDo(a,n);
	int maxX=distance(a,n);
	cout<<"\nKhoang cach mang x lon nhat: "<<maxX<<endl;
	cout<<"\nMang tap hop y tren truc tung: ";
	xuatToaDo(b,n);
	int maxY=distance(b,n);
	cout<<"\nKhoang cach mang y lon nhat: "<<maxY<<endl;
	int Smin=maxX*maxY;
	cout<<"\nDien  tich hcn nho nhat co the chua "<<n<<" diem da cho la: "<<Smin;//tim dien  tich hinh chu nhat chua cac diem da cho
	return 0;
}
