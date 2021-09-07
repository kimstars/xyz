#include <iostream>
#include <algorithm>

using namespace std;

int soluong, khoiluong;
struct dat
{
    int w = 0, v = 0;
};
dat a[105];
int dp[110][110];
int res = 0;
void solve()
{
    for (int i = 1; i <= soluong; i++)
    {
        for (int j = 1; j <= khoiluong; j++)
        {
            if (j < a[i].w)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].w] + a[i].v);
            res = max(res, dp[i][j]);
        }
    }
}

int main()
{
    cin >> soluong >> khoiluong;
    for (int i = 1; i <= soluong; i++)
        cin >> a[i].w >> a[i].v;
    solve(); 
    cout << res;
    return 0;
}
