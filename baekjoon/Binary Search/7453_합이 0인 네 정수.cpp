#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n;
	cin >> n;
	vector<vector<int>> arr(4, vector<int>(n));
	FOR(i, 0, n) FOR(j, 0, 4) cin >> arr[j][i];
	vector<int> ab, cd;

	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			ab.push_back(arr[0][i] + arr[1][j]);
			cd.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(ALL(cd));

	ll ans = 0;
	for (int i = 0; i < ab.size(); i++)
	{
		auto up = upper_bound(ALL(cd), -ab[i]);
		auto lo = lower_bound(ALL(cd), -ab[i]);
		ans += up - lo;
	}

	cout << ans;
}