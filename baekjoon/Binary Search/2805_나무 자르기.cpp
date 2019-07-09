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

	ll n, m;
	cin >> n >> m;
	vector<ll> arr(n);
	FOR(i, 0, n) cin >> arr[i];

	ll l = 0, r = 2000000000, mid, ans;
	while (l <= r)
	{
		mid = (l + r) / 2;
		ll sum = 0;
		for (auto x : arr)
		{
			if (x - mid > 0) sum += x - mid;
		}
		if (sum >= m)
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
}