#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int n, m, l, q;
char Map[3000][3000];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
// dir: 0위 1오른 2아래 3왼

int ans1 = 0, ans2 = 0;
void dfs(int x, int y, int dir, int cnt)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (Map[x][y] == '!')
	{
		ans1++;
		ans2 += cnt;
		dfs(x + dx[dir], y + dy[dir], dir, cnt + 1);
	}
	else if (Map[x][y] == '\0')
	{
		dfs(x + dx[dir], y + dy[dir], dir, cnt + 1);
	}
	else if (Map[x][y] == '/')
	{
		if(dir == 0)
			dfs(x + dx[1], y + dy[1], 1, cnt + 1);
		else if (dir == 1)
			dfs(x + dx[0], y + dy[0], 0, cnt + 1);
		else if (dir == 2)
			dfs(x + dx[3], y + dy[3], 3, cnt + 1);
		else if (dir == 3)
			dfs(x + dx[2], y + dy[2], 2, cnt + 1);
	}
	else if (Map[x][y] == '\\')
	{
		if (dir == 0)
			dfs(x + dx[3], y + dy[3], 3, cnt + 1);
		else if (dir == 1)
			dfs(x + dx[2], y + dy[2], 2, cnt + 1);
		else if (dir == 2)
			dfs(x + dx[1], y + dy[1], 1, cnt + 1);
		else if (dir == 3)
			dfs(x + dx[0], y + dy[0], 0, cnt + 1);
	}
}

int main()
{
	FAST;
	cin >> n >> m >> l >> q;

	for (int i = 0; i < 6; i++)
	{
		int x, y;
		char c;
		cin >> x >> y >> c;
		Map[x - 1][y - 1] = c;
	}
	for (int i = 0; i < q; i++)
	{
		ans1 = ans2 = 0;
		char dir;
		int index = 0;
		cin >> dir >> index;
		if (dir == 'U') dfs(0, index - 1, 2, 1);
		else if (dir == 'R') dfs(index-1, m-1, 3, 1);
		else if (dir == 'D') dfs(n-1, index - 1, 0, 1);
		else if (dir == 'L') dfs(index-1, 0, 1, 1);
		cout << ans1 << " " << ans2 << "\n"; 
	}
}