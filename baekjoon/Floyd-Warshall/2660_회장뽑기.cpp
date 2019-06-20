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
	int n;
	cin >> n;
	int adj[51][51];
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (i == j) adj[i][j] = 0;
			else adj[i][j] = INF;
		}
	}
	while (1)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		a--, b--;
		adj[a][b] = 1;
		adj[b][a] = 1;
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

	vector<int> ans(n);
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (adj[i][j] == INF) continue;
			ans[i] = max(ans[i], adj[i][j]);
		}
	}

	int ans_min = *min_element(ALL(ans));
	int ans_min_cnt = 0;
	for (auto x : ans) if (x == ans_min) ans_min_cnt++;
	cout << ans_min << " " << ans_min_cnt << "\n";
	for (int i = 0; i < ans.size(); i++) if (ans[i] == ans_min) cout << i + 1 << " ";
}