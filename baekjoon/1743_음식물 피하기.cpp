#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int a; cin >> a; for(int t=1;t<=a;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool Map[101][101];
bool visit[101][101];

int dfs(int x, int y)
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (Map[nx][ny] && !visit[nx][ny])
		{
			visit[nx][ny] = 1;
			ret += 1 + dfs(nx, ny);
		}
	}
	return ret;
}

int main()
{
	FAST;
	int k;
	cin >> n >> m >> k;
	FOR(i, 0, k)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		Map[a][b] = 1;
	}

	int Max = 0;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (Map[i][j] && !visit[i][j])
			{
				Max = max(Max, dfs(i, j));
			}
		}
	}

	cout << Max;
}