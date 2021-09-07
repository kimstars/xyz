#include<iostream>
using namespace std;
//grid[][]  dai dien cho mang 2 chieu voi gia tri(0 va 1) , grid[i][j]=1 nghia la quan hau i duoc dat tai cot j
//co the lay so luong quan hau tuy y, bai nay lay toi da la 10 (grid[10][10]).
int grid[10][10];

void print(int n) {
    for (int i = 0;i <= n-1; i++) {
        for (int j = 0;j <= n-1; j++) {
            
                cout <<grid[i][j]<< " ";
            
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
// Kiem tra xem vi tri co an toan hay khong
// row chi ra vi tri quan hau .  col dai dien cho cac vi tri an toan
bool isSafe(int col, int row, int n) {
    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    //kiem tra duong cheo phia tren ben trai
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    //kiem tra duong cheo phia tren ben phai
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}

bool solve (int n, int row) {
    if (n == row) {
        print(n);
        return true;
    }
    //res la kha nang quay lui
    bool res = false;
    for (int i = 0;i <=n-1;i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;
            //ham de quy de goi quan hau tiep theo (row+1)
            res = solve(n, row+1) || res;//
			 res ==false ;//thi quay lui xay ra
            
            grid[row][i] = 0;
        }
    }
    return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n;
        cout<<"Nhap so quan hau:"<<endl; 
        // nhap so quan hau
        cin >> n;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                grid[i][j] = 0;
            }
        }
        bool res = solve(n, 0);
        if(res == false) {
            cout << -1 << endl; 
        } else {
            cout << endl;
        }
  return 0;
}
