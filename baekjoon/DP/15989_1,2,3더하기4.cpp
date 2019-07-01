#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int dp[2][10001];

int main()
{
	FAST;
	dp[0][2] = 1;
	for (int i = 3; i <= 10000; i++) 
	{
		dp[0][i] = dp[0][i - 2] + 1;
		dp[1][i] = dp[0][i - 3] + dp[1][i - 3] + 1;
	}
	CASES(t)
	{
		int n;
		cin >> n;
		cout << 1 + dp[0][n] + dp[1][n] << "\n";
	}
}