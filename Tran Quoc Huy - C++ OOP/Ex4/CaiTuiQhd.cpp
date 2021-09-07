//Phuong phap quy hoach dong
#include <bits/stdc++.h>

using namespace std;

int n,M;
struct dat{
	int w=0,v=0;
};
dat a[105];
int dp[110][110];
int res = 0;
void Solve()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= M; j++) {
			if (j < a[i].w)
			    dp[i][j] = dp[i-1][j];
			else
			    dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i].w] + a[i].v);
			res = max(res,dp[i][j]);
		}
	}
}

int main() {
	cin>>n>>M;
	for (int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].v;
    
    Solve();
    cout << res;
	return 0;
}

