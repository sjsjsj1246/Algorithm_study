#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1999
#define INF 987654321
typedef long long ll;
using namespace std;

int n;

int parent[100001];
bool visit[100001];

void dfs(int here, vector<vector<int>> &adj)
{
	visit[here] = 1;
	for (auto next : adj[here])
	{
		if (!visit[next])
		{
			parent[next] = here;
			visit[next] = 1;
			dfs(next, adj);
		}
	}
}

int main()
{
	FAST;
	cin >> n;
	vector<vector<int>> adj(n+1, vector<int>());
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, adj);
	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}
}