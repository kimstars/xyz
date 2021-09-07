#include<iostream>
#include<vector>
#include<math.h>

#define PI 3.14

using namespace std;

class Rectangular{

    private:
    float width;
    float length;

    public:
    Rectangular(){
    	width=0;
    	length=0;
	}
	Rectangular(float width,float length){
		this-> width = width;
        this-> length = length;
	}
    
    float getLength(){return length;}
	float getWidth(){return width;}
    float areaRectangular(){return width*length;}
    
};

class Triangle{

    private:
    float angle1;
    float angle2;
    float angle3;

    public:
    	Triangle(){
            angle1 = 0;
            angle2 = 0;
            angle3 = 0;
        }
		Triangle(float angle1,float angle2,float angle3){
			this->angle1=angle1;
            this->angle2=angle2;
            this->angle3=angle3;
		}
   
    float getA1(){return angle1;}
    float getA2(){return angle2;}
    float getA3(){return angle3;}

    float areaTriangle(){
        float p = (angle1 + angle2 + angle3)*1.0 / 2;
        return sqrt(p*(p-angle1)*(p-angle2)*(p-angle3));
    }
};

class Circle{

    private:
    float radius;

    public:
    	Circle(){
            radius=0;
        }
		Circle(float radius){
            this->radius=radius;
        }
    
    float getRadius(){return radius;}
    float areaCircle(){return radius*radius*PI;}
};

bool triangle(float& angle1,float& angle2,float& angle3){

    if((angle1 >= angle2 + angle3) || (angle2 >= angle1 + angle3) || (angle3 >= angle1 + angle2))
    {
        return false;
    }

    return true;
}

int main(){

    int n1,n2,n3;
    cout << "n1: ";
    cin >> n1;
    cout << "n2: ";
    cin >> n2;
    cout << "n3: ";
    cin>> n3;

    vector<Rectangular>arrRectangular;
    vector<Triangle>arrTriangle;
    vector<Circle>arrCircle;

    float var1,var2,var3;
    cin.ignore();

    for(int i = 0; i < n1; i++){

        do{cout<<"Rectangular "<<i+1<<" :\n";
        cout<<"width: ";cin>>var1;
        cout<<"length: ";cin>>var2;
        if(var1<=var2){
            arrRectangular.push_back(Rectangular(var1,var2));
		}
        else{
            cout<<"khong hop le";
        }
        } while(var2<var1);
        
    }
    for(int i=0;i<n2;i++)
    {
        do{
		cout<<"Triangle "<<i+1<<" :\n";
        cout<<"canh 1: ";
		cin >> var1;
        cout << "canh 2: ";
		cin >> var2;
        cout << "canh 3: ";
		cin >>var3;
        if(triangle(var1,var2,var3)){
            arrTriangle.push_back(Triangle(var1,var2,var3));
            		}
        else{cout<<"khong hop le \n"<<"Nhap lai ";}
        } while (!triangle(var1,var2,var3));
            }

    for(int i = 0; i < n3; i++){
        cout<< "Circle "<< i+1 << " :\n";
        cout<< "Radius: ";
        cin>> var3;
        arrCircle.push_back(Circle(var3));
        
    }
    float max1=-1;
    int k1=0;

    for(int i=0;i<n1;i++){
        if(arrRectangular[i].areaRectangular() > max1){
            max1=arrRectangular[i].areaRectangular();
            k1 = i+1;
        }

    }
    float max2 = -1;
    int k2 = 0;
    for(int i = 0;i < n2; i++){
        if(arrTriangle[i].areaTriangle() > max2){
            max2 = arrTriangle[i].areaTriangle();
            k2 = i+1;
        }
        
    }
    float max3 = -1;
    int k3 = 0;
    for(int i = 0; i < n1; i++){
        if(arrCircle[i].areaCircle() > max3){
            max3 = arrCircle[i].areaCircle();
            k3 = i+1;
        }
    }
    float maxAll = max(max1,max(max2,max3));
    if(max1==max2&&max2==max3){
        cout << "Rectangular max, Trianglea max, Circle max has Area bang nhau"<<endl;
        
        cout<<"Area la: " << maxAll;
        }else if(max1==max2&&max2!=max3){
            if(maxAll==max1){
                cout<<"Rectangular thu "<<k1<<" va Trianglea thu "<<k2<<" has Area max"<<endl;
                cout<<"Area la: "<<maxAll;
            }else{
                cout<<"Circle thu "<<k3<<" has Area max"<<endl;
                cout<<"Area la: "<<maxAll;
            }
        }else if(max1==max3&&max2!=max3){
            if(maxAll==max1){
                cout<<"Rectangular thu "<<k1<<" va Circle thu "<<k3<<" has Area max "<<endl;
                cout<<"Area la: "<<maxAll;
            }else{
                cout<<"Trianglea thu "<<k2<<" has Area max "<<endl;
                cout<<"Area la: "<<maxAll;
            }
        }else if(max2==max3&&max1!=max3){
            if(maxAll==max2){
                cout<<"Trianglea thu "<<k2<<" va Circle thu "<<k3<<" has Area max "<<endl;
                cout<<"Area la: "<<maxAll;
            }else{
                cout<<"Rectangular thu "<<k1<<" has Area max "<<endl;
                cout<<"Area la: "<<maxAll;
            }
        }else{
            if(maxAll==max1){
                cout<<"Rectangular thu "<<k1<<" has Area max "<<endl;
                cout<<"Area = "<<maxAll;
            }else{
            if(maxAll==max2){
                cout<<"Trianglea thu "<<k2<<" has Area max "<<endl;
                cout<<"Area = "<<maxAll;
            }else{
                cout<<"Circle thu "<<k3<<" has Area max "<<endl;
                cout<<"Area = "<<maxAll;
            }
        }
    }

return 0;
}
