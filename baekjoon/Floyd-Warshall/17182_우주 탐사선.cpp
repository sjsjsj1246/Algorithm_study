#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int adj[11][11];
bool visit[11];
int n, k, ans = INF;

void dfs(int cnt, int i, int sum)
{
	if (cnt == n - 1)
	{
		ans = min(ans, sum);
		return;
	}
	for (int j = n - 1; j >= 0; j--)
	{
		if (!visit[j])
		{
			visit[j] = 1;
			dfs(cnt + 1, j, sum + adj[i][j]);
			visit[j] = 0;
		}
	}
}

int main()
{
	FAST;
	cin >> n >> k;
	FOR(i, 0, n) FOR(j, 0, n) cin >> adj[i][j];
	FOR(k, 0, n) FOR(i, 0, n) FOR(j, 0, n) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	visit[k] = 1;
	dfs(0, k, 0);
	cout << ans;
}