#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool Map[51][51];
bool visit[51][51];

int bfs(pair<int, int> start)
{
	int ret = 0;
	queue<pair<int, int>> q;
	queue<int> cnt;
	q.push(start);
	cnt.push(0);
	visit[start.first][start.second] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int h_cnt = cnt.front();
		ret = h_cnt;
		q.pop();
		cnt.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (!visit[nx][ny])
			{
				q.push({ nx, ny });
				cnt.push(h_cnt + 1);
				visit[nx][ny] = 1;
			}
		}
	}
	return ret;
}

int main()
{
	int ans = 0;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'L') Map[i][j] = 0;
			if (s[j] == 'W') Map[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = Map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!Map[i][j])
			{
				ans = max(ans, bfs({ i,j }));
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						visit[i][j] = Map[i][j];
					}
				}
			}
		}
	}
	cout << ans;
}