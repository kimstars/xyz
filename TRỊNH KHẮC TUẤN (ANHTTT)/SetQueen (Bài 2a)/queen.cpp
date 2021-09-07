#include <iostream>
#include <string>
using namespace std;

void in(int a[][20], int n) {
	cout<<"\nVi tri hau:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        	if(a[i][j]!=1){
        		a[i][j]=0;
			}
			cout << a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int testCot(int a[][20], int i, int j, int n) {
    if (i == 0) return 1;
    for (int k = 0; k < i; k++) if (a[k][j] == 1) return 0;
    return 1;
}

int testCheoTren(int a[][20], int i, int j) {
    i--; j--;
    while (i >= 0 && j >= 0) {
        if (a[i][j] == 1) return 0;
        i--; j--;
    }
    return 1;
}

int testCheoDuoi(int a[][20], int i, int j, int n) {
    i--; j++;
    while (i >= 0 && j < n) {
        if (a[i][j] == 1) return 0;
        i--; j++;
    }
    return 1;
}

bool giaiThuat(int a[][20], int i, int n) {
    if (i == n) {
    	in(a, n);
    	return true;
	}
    else {
        for (int j = 0; j < n; j++) {
            if (testCot(a, i, j, n) && testCheoTren(a, i, j) && testCheoDuoi(a, i, j, n)) {
                a[i][j] = 1;
                giaiThuat(a, i + 1, n);
                a[i][j] = 0;
            }
        }
        return false;
    }
}

int main()
{
    int a[20][20], n;
    cout<<"Nhap so con hau: ";
    cin >> n;
    if(giaiThuat(a, 0, n)){
    	in(a, n);
	} 
}
