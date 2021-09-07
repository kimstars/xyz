#include <iostream>
#include <math.h>

using namespace std;

class chess{
    public:
        int a[10];
    public:
        bool Check(int x, int y);
        void Export(int n);
        void Try(int i, int n);
};

bool chess :: Check(int x, int y) {
    for(int i = 1; i < x; i++){
        if(a[i] == y || abs(i - x) == abs(a[i] - y)) return false;
    }
    return true;
}

void chess :: Export(int n) {
    for (int i = 1; i <= n; i++ ) {
        cout<<" "<<a[i];
    }
    cout<<endl;
}

void chess :: Try(int i, int n) {
    for(int j = 1; j <= n; j++)
    if(Check(i, j)){
        a[i] = j;
        if(i == n) Export(n);
        Try(i + 1, n);
    }
}

int main(){
    chess ch;
    int n=8;
    ch.Try(1, n);
    return 0;
}
