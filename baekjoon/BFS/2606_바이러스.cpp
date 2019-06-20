#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 187654321
typedef long long ll;
using namespace std;

int n, m;
vector<vector<int>> adj;
bool visit[101];

int bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	int ret = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (auto next : adj[here])
		{
			if (!visit[next])
			{
				visit[next] = 1;
				q.push(next);
				ret++;
			}
		}
	}
	return ret;
}

int main()
{
	FAST;
	cin >> n >> m;
	adj = vector<vector<int>>(n, vector<int>());
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << bfs(0);
}