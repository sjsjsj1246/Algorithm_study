#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1999
#define INF 987654321
typedef long long ll;
using namespace std;

int dp[21] = { 0,1,2,4,7 };

int main()
{
	FAST;
	int n;
	cin >> n;
	for (int i = 5; i <= n; i++)
	{
		dp[i] = dp[i - 1] * 2;
		if (i % 2 == 0) dp[i] -= dp[i - 5] + dp[i - 4];
	}
	cout << dp[n];
}