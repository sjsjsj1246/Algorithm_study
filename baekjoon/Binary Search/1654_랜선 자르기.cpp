#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int main() 
{
	FAST;
	int k, n;
	cin >> k >> n;
	vector<int> arr(k);
	FOR(i, 0, k) cin >> arr[i];
	ll l = 1, r = (1ll << 31) - 1ll;
	ll ans = 0;
	while (l <= r)
	{
		ll mid = (l + r) / 2ll;
		ll cnt = 0;
		for (auto x : arr) cnt += x / mid;
		if (cnt >= n)
		{
			l = mid + 1;
			ans = max(ans, mid);
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
}