#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int n, k;

int bfs(vector<int> & adj)
{
	queue<pair<int, int>> q;
	vector<bool> visit(n);
	q.push({ 0, 0 });
	visit[0] = 1;
	while (!q.empty())
	{
		int here = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (here == k) return cnt;
		int next = adj[here];
		if (!visit[next])
		{
			q.push({ next, cnt + 1 });
			visit[next] = 1;
		};
	}
	return -1;
}

int main()
{
	FAST;
	cin >> n >> k;
	vector<int> adj(n);
	FOR(i, 0, n)
	{
		cin >> adj[i];
	}
	cout << bfs(adj);
}