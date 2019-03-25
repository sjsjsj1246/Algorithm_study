#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int Map[1001][1001];
bool visit[2][1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;

struct node 
{
	int x, y, k, cnt;
};

int bfs(pair<int, int> start)
{
	queue<node> q;
	q.push({ start.first, start.second, 1, 1 });
	visit[0][start.first][start.second] = 1;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int h_cnt = q.front().cnt;
		int k = q.front().k;
		if (x == n - 1 && y == m - 1) return h_cnt;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (!visit[k][nx][ny] && Map[nx][ny] == 0)
			{
				q.push({ nx,ny,k,h_cnt + 1 });
				visit[k][nx][ny] = 1;
			}

			if (!visit[1][nx][ny] && Map[nx][ny] == 1 && k > 0)
			{
				q.push({ nx,ny,k-1,h_cnt + 1 });
				visit[1][nx][ny] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			Map[i][j] = s[j] - '0';
		}
	}
	
	cout << bfs({ 0, 0 });
}