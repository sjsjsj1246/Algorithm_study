#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
bool visit[2000][2000];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int dfs(int x, int y, int cnt, int tx, int ty)
{
	if (cnt > n) return 0;
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 2000 || ny < 0 || ny >= 2000) continue;
		if (x % 2)
		{
			if (y % 2 && nx == x - 1) continue;
			else if (y % 2 == 0 && nx == x + 1) continue;
		}
		else
		{
			if (y % 2 && nx == x + 1)	continue;
			else if (y % 2 == 0 && nx == x - 1) continue;
		}
		
		if (!visit[nx][ny])
		{
			visit[nx][ny] = 1;
			ret += dfs(nx, ny, cnt + 1, x, y);
			visit[nx][ny] = 0;
		}
		else if (cnt == n && !(nx == tx && ny == ty))
		{
			ret++;
		}
	}
	return ret;
}

int main()
{
	FAST;
	cin >> n;
	visit[1001][1000] = 1;
	cout << dfs(1000, 1000, 1, 1001, 1000);
}