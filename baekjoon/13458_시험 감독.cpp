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
	vector<ll> arr(n);
	FOR(i, 0, n) cin >> arr[i];
	ll a, b;
	cin >> a >> b;

	ll ans = 0;
	for (auto x : arr)
	{
		x -= a;
		ans++;
		if (x > 0)
		{
			ans += x / b + ((x % b) != 0);
		}
	}
	cout << ans;
}