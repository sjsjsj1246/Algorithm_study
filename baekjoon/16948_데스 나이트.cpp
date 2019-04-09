#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int n;
int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };

int dfs(pair<int,int> start, pair<int,int> des)
{
	vector<vector<bool>> visit(n, vector<bool>(n, 0));
	queue<pair<int, int>> q;
	queue<int> cnt;
	q.push(start);
	cnt.push(0);
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int h_cnt = cnt.front();

		if (x == des.first && y == des.second) return h_cnt;

		q.pop();
		cnt.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!visit[nx][ny])
			{
				q.push({ nx,ny });
				cnt.push(h_cnt + 1);
				visit[nx][ny] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	FAST;
	cin >> n;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << dfs({ a,b }, { c,d });
}