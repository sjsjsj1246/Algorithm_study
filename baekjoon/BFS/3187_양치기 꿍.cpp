#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int r, c;
char Map[251][251];
bool visit[251][251];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

pair<int, int> bfs(pair<int, int> start)
{
	queue<pair<int, int>> q;
	q.push(start);
	visit[start.first][start.second] = 1;
	int k = 0;
	int v = 0;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (Map[x][y] == 'v') v++;
		if (Map[x][y] == 'k') k++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (!visit[nx][ny])
			{
				visit[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	return { k, v };
}

int main()
{
	FAST;
	cin >> r >> c;
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			cin >> Map[i][j];
			if (Map[i][j] == '#') visit[i][j] = 1;
		}
	}

	vector<int> ans(2);
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			if (!visit[i][j])
			{
				pair<int, int> ret = bfs({ i, j });
				if (ret.first <= ret.second) ans[1] += ret.second;
				else ans[0] += ret.first;
			}
		}
	}
	cout << ans[0] << " " << ans[1];
}