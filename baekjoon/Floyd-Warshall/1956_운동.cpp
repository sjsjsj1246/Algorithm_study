#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 187654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	int adj[401][401];
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			adj[i][j] = INF;
		}
	}
	FOR(i, 0, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		adj[a][b] = c;
	}

	FOR(k, 0, n)
	{
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	int ans = INF;
	FOR(i, 0, n) ans = min(ans, adj[i][i]);
	if (ans == INF) cout << -1;
	else cout << ans;
}