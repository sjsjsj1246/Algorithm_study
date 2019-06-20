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
	CASES(t)
	{
		int n;
		cin >> n;
		n += 2;
		vector<pair<int, int>> node(n);
		FOR(i, 0, n) cin >> node[i].first >> node[i].second;

		vector<vector<int>> adj(n, vector<int>(n));

		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				if (i == j) adj[i][j] = 0;
				else
				{
					int dis = abs(node[i].first - node[j].first)
						+ abs(node[i].second - node[j].second);
					if (dis <= 1000) adj[i][j] = dis;
					else adj[i][j] = INF;
				}
			}
		}

		FOR(k, 0, n)
		{
			FOR(i, 0, n)
			{
				FOR(j, 0, n)
				{
					int dis = INF;
					if (adj[i][k] != INF) dis = adj[k][j];
					adj[i][j] = min(adj[i][j], dis);
				}
			}
		}

		if (adj[0][n - 1] != INF) cout << "happy\n";
		else cout << "sad\n";
	}
}