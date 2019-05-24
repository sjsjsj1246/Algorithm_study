#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n;
	cin >> n;
	vector<int> c(n, 0);
	vector<ll> l(n, 0), r(n, 0);
	FOR(i, 0, n) cin >> c[i];
	FOR(i, 1, n) cin >> l[i], l[i] += l[i - 1];
	FOR(i, 1, n) cin >> r[i], r[i] += r[i - 1];

	int pos = 0;
	ll ans = 1ll << 60;
	FOR(i, 0, n)
	{
		ll val = l[i] + c[i] + (r[n - 1] - r[i]);
		if (ans > val) pos = i, ans = val;
	}
	cout << pos + 1 << " " << ans;
}