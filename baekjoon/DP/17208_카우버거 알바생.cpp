#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int n, m, k;
int dp[101][301][301];

int memo(int n, int m, int k, vector<pair<int, int>> & arr)
{
	if (m < 0 || k < 0) return -INF;
	if (n == 0) return 0;
	int& ret = dp[n][m][k];
	if (ret != -1) return ret;
	return ret = max(memo(n - 1, m - arr[n].first, k - arr[n].second, arr) + 1,
		memo(n - 1, m, k, arr));
}

int main()
{
	FAST;
	cin >> n >> m >> k;
	vector<pair<int, int>> arr(n + 1);
	FOR(i, 1, n + 1) cin >> arr[i].first >> arr[i].second;
	memset(dp, -1, sizeof(dp));
	cout << memo(n, m, k, arr);
}