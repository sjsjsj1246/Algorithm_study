#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 187654321
typedef long long ll;
using namespace std;

ll seg[4 * 1000000];
ll update(ll pos, ll val, ll node, ll x, ll y) 
{

	if (y < pos || pos < x) return seg[node];
	if (x == y) return seg[node] = val;
	ll mid = (x + y) >> 1;
	return seg[node] = (update(pos, val, node * 2, x, mid) * update(pos, val, node * 2 + 1, mid + 1, y)) % MOD;
}
ll query(ll lo, ll hi, ll node, ll x, ll y) 
{
	if (y < lo || hi < x) return 1;
	if (lo <= x && y <= hi) return seg[node];
	ll mid = (x + y) >> 1;
	return (query(lo, hi, node * 2, x, mid) * query(lo, hi, node * 2 + 1, mid + 1, y)) % MOD;
}
int main() 
{
	FAST;
	ll n, m, k, t, x, y, z;
	cin >> n >> m >> k;
	for (ll i = 1; i <= n; i++) 
	{
		cin >> t;
		update(i, t, 1, 1, n);
	}
	for (ll i = 0; i < m + k; i++) 
	{
		cin >> x >> y >> z;
		if (x == 1) update(y, z, 1, 1, n);
		else cout << query(y, z, 1, 1, n) << "\n";
	}
}