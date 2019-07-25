#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

void solve(ll n, ll m, vector<ll>::iterator a, vector<ll>::iterator b) {
	if (m == 1) {
		b[0] = n * a[0];
		return;
	}
	if (n % 2 == 1) {
		b[0] = n * a[0];
		solve((n + 1) / 2, m - 1, a + 1, b + 1);
		return;
	}
	solve(n / 2, m - 1, a, b);
	b[m - 1] = (n + (1LL << m) - 2) * a[m - 1];
}

int main()
{
	FAST;

	ll n, m;
	cin >> n >> m;

	vector<ll> a(m), b(m);
	for (ll i = 0; i < m; i++)
		cin >> a[i];

	solve(n, m, a.begin(), b.begin());

	for (ll i = 0; i < m; i++)
		cout << b[i] << ' ';
}