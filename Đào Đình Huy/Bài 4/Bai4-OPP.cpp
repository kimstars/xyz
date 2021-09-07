#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int a[100][100];
bool ok[100][100];
int n;
vector <string> res;
void Try(int i, int j, string s ){
    //ra biên
    if(i == n || j == n){
        res.push_back(s);
        return;
    }
    //đi xuống
    if(i < n && a[i+1][j] == 0 && !ok[i+1][j]){
        ok[i][j] = true;
        Try(i + 1, j, s + "X");
        ok[i][j] = false;
    }
    //sang phải
    if( j < n && a[i][j+1] == 0 && !ok[i][j+1]){
        ok[i][j] = true;
        Try(i, j + 1, s + "P");
        ok[i][j] = false;
    }
    //sang trái
    if(j != 1 && a[i][j-1] == 0 && !ok[i][j-1]){
        ok[i][j] = true;
        Try(i, j - 1, s+"T");
        ok[i][j] = false;
    }
    //đi lên
    if(i != 1 && a[i - 1][j] == 0 && !ok[i-1][j]){
        ok[i][j] = true;
        Try(i-1, j, s+"L");
        ok[i][j] = false;
    }
}

void solve(){
    res.clear();
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
            ok[i][j] = false;
        }
    }
    cout<<"Nhap vi tri bat dau: ";
    int x, y;
    cin>>x>>y;
    Try(x, y, "");
    if(res.size() == 0) cout<< -1;
    else{
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int t = 1;
    while (t--){
        solve();
    }
    return 0;
}