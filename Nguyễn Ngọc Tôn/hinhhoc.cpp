#include<iostream>
#include<vector>
#include<math.h>
#define PI 3.14
using namespace std;
class HCN{
    private:
    float width,lenght;
    public:
    HCN(){
    	width=0;
    	lenght=0;
	}
	HCN(float width,float lenght){
		this->width=width;this->lenght=lenght;
	}
    
    float getLenght(){return lenght;}
	float getWidth(){return width;}
    float areaHCN(){return width*lenght;}
    
};
class HTG{
    private:
    float a1,a2,a3;
    public:
    	HTG(){a1=0;a2=0;a3=0;}
		HTG(float a1,float a2,float a3){
			this->a1=a1;this->a2=a2;this->a3=a3;
		}
//    void setTG(float a1,float a2,float a3){
//        this->a1=a1;
//        this->a2=a2;
//        this->a3=a3;
//    }
    float getA1(){return a1;}
    float getA2(){return a2;}
    float getA3(){return a3;}
    float areaTG(){
        float p=(a1+a2+a3)/2;
        return sqrt(p*(p-a1)*(p-a2)*(p-a3));
    }
};
class HT{
    private:
    float r;
    public:
    	HT(){r=0;}
		HT(float r){this->r=r;}
    //void setR(float r){this->r=r;}
    float getR(){return r;}
    float areaHT(){return r*r*PI;}
};
bool tamgiac(float& a,float& b,float& c){
    if(a>=b+c||b>=a+c||c>=a+b){
        return false;
    }
    return true;
}
int main(){
    int n1,n2,n3;
    cout<<"n1: ";cin>>n1;
    cout<<"n2: ";cin>>n2;
    cout<<"n3: ";cin>>n3;
    vector<HCN>arrHCN;
    vector<HTG>arrHTG;
    vector<HT>arrHT;
    float var1,var2,var3;
    cin.ignore();
    for(int i=0;i<n1;i++){
        do{cout<<"HCN "<<i+1<<" :\n";
        cout<<"width: ";cin>>var1;
        cout<<"length: ";cin>>var2;
        if(var1<=var2){arrHCN.push_back(HCN(var1,var2));//HCN::areaHCN();
		}
        else{cout<<"khong hop le";}
        }while(var2<var1);
        //cout<<HCN::areaHCN(var1,var2);
    }
    for(int i=0;i<n2;i++)
    {
        do{
		cout<<"HTG "<<i+1<<" :\n";
        cout<<"canh 1: ";cin>>var1;
        cout<<"canh 2: ";cin>>var2;
        cout<<"canh 3: ";cin>>var3;
        if(tamgiac(var1,var2,var3)){arrHTG.push_back(HTG(var1,var2,var3));//cout<<HTG::areaTG();
		}
        else{cout<<"khong hop le \n"<<"Nhap lai ";}
        }while(!tamgiac(var1,var2,var3));//cout<<HTG::areaTG(var1,var2,var3);
    }
    for(int i=0;i<n3;i++){
        cout<<"HT "<<i+1<<" :\n";
        cout<<"r: ";cin>>var3;
        arrHT.push_back(HT(var3));
        //cout<<HT::areaHT(var3);
    }
    float max1=-1;
    int k1=0;
    for(int i=0;i<n1;i++){
        if(arrHCN[i].areaHCN()>max1){
            max1=arrHCN[i].areaHCN();
            k1=i+1;
        }
//		else if(arrHCN[i].areaHCN()==max1){
//        	cout<<"2 hinh chu nhat co dien tich bang nhau"<<endl;
//		}
    }
    float max2=-1;
    int k2=0;
    for(int i=0;i<n2;i++){
        if(arrHTG[i].areaTG()>max2){
            max2=arrHTG[i].areaTG();
            k2=i+1;
        }
        
//		else if(arrHTG[i].areaTG()==max2){
//        	cout<<"2 hinh tam giac co dien tich bang nhau"<<endl;
//		}
    }
    float max3=-1;
    int k3=0;
    for(int i=0;i<n1;i++){
        if(arrHT[i].areaHT()>max3){
            max3=arrHT[i].areaHT();
            k3=i+1;
        }
    }
    float maxall = max(max1,max(max2,max3));
    if(max1==max2&&max2==max3){
        cout<<"hinh chu nhat lon nhat, hinh tam giac lon nhat, hinh tron lon nhat co dien tich bang nhau"<<endl;
        cout<<"dien tich la: "<<maxall;
        }else if(max1==max2&&max2!=max3){
            if(maxall==max1){
                cout<<"hinh chu nhat thu "<<k1<<" va hinh tam giac thu "<<k2<<" co dien tich lon nhat"<<endl;
                cout<<"dien tich la: "<<maxall;
            }else{
                cout<<"hinh tron thu "<<k3<<" co dien tich lon nhat"<<endl;
                cout<<"dien tich la: "<<maxall;
            }
        }else if(max1==max3&&max2!=max3){
            if(maxall==max1){
                cout<<"hinh chu nhat thu "<<k1<<" va hinh tron thu "<<k3<<" co dien tich lon nhat "<<endl;
                cout<<"dien tich la: "<<maxall;
            }else{
                cout<<"hinh tam giac thu "<<k2<<" co dien tich lon nhat "<<endl;
                cout<<"dien tich la: "<<maxall;
            }
        }else if(max2==max3&&max1!=max3){
            if(maxall==max2){
                cout<<"hinh tam giac thu "<<k2<<" va hinh tron thu "<<k3<<" co dien tich lon nhat "<<endl;
                cout<<"dien tich la: "<<maxall;
            }else{
                cout<<"hinh chu nhat thu "<<k1<<" co dien tich lon nhat "<<endl;
                cout<<"dien tich la: "<<maxall;
            }
        }else{
            if(maxall==max1){
                cout<<"hinh chu nhat thu "<<k1<<" co dien tich lon nhat "<<endl;
                cout<<"dien tich = "<<maxall;
            }else{
            if(maxall==max2){
                cout<<"hinh tam giac thu "<<k2<<" co dien tich lon nhat "<<endl;
                cout<<"dien tich = "<<maxall;
            }else{
                cout<<"hinh tron thu "<<k3<<" co dien tich lon nhat "<<endl;
                cout<<"dien tich = "<<maxall;
            }
        }
    }
return 0;
}
