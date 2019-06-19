#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

struct P
{
	int x, y, z, cnt;
};

int l, r, c;
char Map[31][31][31];
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 1,-1,0,0,0,0 };

int bfs(P start)
{
	queue<P> q;
	q.push(start);
	bool visit[31][31][31] = { 0 };
	visit[start.x][start.y][start.z] = 1;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int cnt = q.front().cnt;
		q.pop();
		if (Map[x][y][z] == 'E')
		{
			return cnt;
		}
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
			if (!visit[nx][ny][nz] && Map[nx][ny][nz] != '#')
			{
				q.push({ nx,ny,nz,cnt + 1 });
				visit[nx][ny][nz] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	FAST;

	while (1)
	{
		cin >> l >> r >> c;
		if ((l|r|c) == 0) return 0;
		P start;
		string temp;
		FOR(i, 0, l)
		{
			FOR(j, 0, r)
			{
				cin >> temp;
				FOR(k, 0, c)
				{
					Map[j][k][i] = temp[k];
					if (temp[k] == 'S') start = { j,k,i,0 };
				}
			}
		}
		int ans = bfs(start);
		if (ans == -1) cout << "Trapped!\n";
		else cout << "Escaped in " << ans << " minute(s).\n";
	}
}