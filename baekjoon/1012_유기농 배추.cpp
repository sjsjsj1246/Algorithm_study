#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int m, n;
int map[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


void BFS(pair<int, int> start)
{
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty())
	{
		int hx = q.front().first;
		int hy = q.front().second;
		map[hx][hy] = false;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if (nx >= m || nx < 0 || ny >= n || ny < 0) continue;
			pair<int, int> there = { nx,ny };
			if (map[nx][ny])
			{
				q.push(there);
				map[nx][ny] = false;
			}
		}
	}
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		memset(map, 0, sizeof(map));
		ios::sync_with_stdio(false);
		int k, cnt = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			map[a][b] = 1;
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				while (map[i][j])
				{
					pair<int, int> start = { i,j };
					BFS(start);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}