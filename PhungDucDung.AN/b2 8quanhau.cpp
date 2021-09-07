#include<stdlib.h>
#include<iostream>
#include<cstring>
using namespace std;
int row[8],lineCounter;
bool kiemtra_dieukien(int r,int c){
	for(int i = 0; i <c;i++){
		if(row[i] == r || (abs(row[i]-r)==abs(i-c))){ //dk cung hang doc, hang cheo
			return false;
		}
	}
	return true;
}
void quaylui(int c){
	if(c == 8){
		for(int j = 0 ; j < 8;j++){ 
			printf(" %d ",row[j]+1);//du 8 quan hau thi in
		}
		cout<<"\n";
	}
	else for(int r = 0; r < 8;r++){
		if(kiemtra_dieukien(r,c)){//neu dk dung
			row[c] = r;
			quaylui(c+1); //de qui 
		}
	}
}
int main(){
	memset(row,0,sizeof row);
	lineCounter = 0;
	cout<<"Vi tri co the dat cac con Hau la:\n";
	cout<<"cot:\n";
	cout<<" 1  2  3  4  5  6  7  8\n";
	cout<<"hang:\n";
	quaylui(0);
	return 0;
}
