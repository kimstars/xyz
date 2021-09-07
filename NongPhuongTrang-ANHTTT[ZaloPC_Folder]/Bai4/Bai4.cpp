#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,*X,*C,amount,OK=1,Max=0,S,K;
class Things{
    private:
    int weight;
    int price;
    public:
    Things();
    Things(int weight, int price);
    void setWeight(int weight);
    void setPrice(int price);
    int getWeight();
    int getPrice();
    void Nhap(Things *A);
    int Test(Things *A);

};
Things::Things(){};

Things::Things(int weight, int price){
        this->weight=weight;
        this->price=price;
}
void Things::setWeight(int weight){
    this->weight=weight;
}
void Things::setPrice(int price){
    this->price=price;
}
int Things::getPrice(){
    return price;
}
int Things::getWeight(){
    return weight;
}
void Things::Nhap(Things *A){
    cout << "Nhap so do vat: "; cin >> n;
    cout << "\nNhap trong luong toi da: "; cin >> m;
    X = new int [n];
    C = new int[n];
    cout << "\nTrong luong va gia tri cua do vat: ";
    for ( int i = 1; i <= n; i++) 
    {
    cout << "\n Vat " << i << ":  ";
    cin >> A[i].weight;
    cin >> A[i].price;
    X[i] = 0;  C[i] = 0;
    }                
}


void Next() 
{
  int i = n;
  while ( i > 0 && X[i])
  {
    X[i] = 0;
    --i;
  }
  if ( i > 0)
    X[i] = 1;
  else
    OK = 0; 
}

int Things::Test(Things *A) {
  int S = 0;
  for ( int i = 1; i <= n; i++) 
  {
    S += A[i].weight * X[i];
  }
  if ( S <= m && S != 0)
  {
    int K = 0;
    for (int i = 1; i <= n; i++) K += A[i].price * X[i];
    if (K > Max)
    {
      for (int i = 1; i <= n; i++) C[i] = X[i];
      Max = K;
    }
    return 1;
  }
  return 0;
}
void Result() 
{
  cout << "Cach thu " << ++amount << " mang vat : " ;
  for ( int i = 1; i <= n; ++ i) 
  {
    if (X[i])   cout << " " << i;
  }
  cout << endl;
}
int main(){
    Things* A = new Things[n];
    A->Nhap(A);
    while (1)
  { 
    Next();
    if (OK == 0 )break;
    if (A->Test(A))
      Result();
  }
    cout << "\ncach xep toi uu la : ";
    for (int i = 1; i <= n; i++) 
    {
        if (C[i]) cout << " \nDo vat thu " << i;
    }
    cout << "\n tong gia tri : " << Max << endl;
    return 0;
}
