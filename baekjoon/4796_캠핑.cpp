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
	int cnt = 1;
	while (1)
	{
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 & v == 0) return 0;
		int ans = 0;
		ans += v / p * l;
		ans += (v % p) > l ? l : v % p;
		cout << "Case " << cnt << ": " << ans << "\n";
		cnt++;
	}
} 