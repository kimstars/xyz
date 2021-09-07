#include <bits/stdc++.h>

using namespace std;
int n, W;
struct goihang
{
    long w;
    long val;
};
vector<int> chiso;

goihang arr[200];

bool cmp(goihang a, goihang b)
{
    return (float)a.val / a.w > (float)b.val / b.w;
}

long Try(int i, long w, long val)
{
    long m = val;
    if (w > W){
        return 0; // TH vượt quá cân nặng
    }

    if (i == n && w <= W)
    { // TH lấy hết hàng
        return val;
    }
    //cho goi hang thu i
    long k = Try(i + 1, w + arr[i].w, val + arr[i].val); // neu chon goi hang i
    

    long t = Try(i + 1, w, val);                         // neu khong chon goi i

    return max(k, t);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //nhap so goi hang, can nang gioi han
    cin >> n >> W;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].w >> arr[i].val;
    }

    sort(arr, arr + n, cmp);

    cout << "kq : " << Try(0, 0, 0) << endl;

    int temp = -1;

    for (int i = 0; i < chiso.size(); i++)
    {
        cout << chiso[i] << " ";
    }
}