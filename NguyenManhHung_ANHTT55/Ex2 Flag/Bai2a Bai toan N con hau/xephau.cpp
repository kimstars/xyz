#include<iostream>
#include<cmath>

using namespace std;

bool check(int x,int y);
void print(int n);
void display(int n);
void tryE(int i,int n);

int a[20];

int main() {

	int n;
	cout << "Enter size chessboard n * n :";
	cin >> n;
    tryE(1,n);
    return 0;

}

bool check(int x,int y){
    //Kiem tra cach dat co thoa man
    for(int i = 1; i < x ;i++)
        if(a[i] == y || abs(i-x) == abs(a[i] - y) )
            return false;
    return true;
}

void print(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i] == j) 
                cout << " 1 ";
            else 
                cout << " 0 ";
        }
        cout << "\n";
    } 
} 
 
void display(int n){
    // In ra ket qua
    cout<<"\nVi tri cac quan hau: ";
    for(int i = 1;i <= n; i++){
        cout << a[i]<<" ";}
        cout << "\n";
        print(n);
        cout << "\n";
    
}
 
void tryE(int i,int n){
    for(int j = 1;j<=n;j++){
        if(check(i,j)){           
            a[i] = j;                   
            if(i==n) 
            display(n);
            tryE(i+1,n);
        }
    }
}