#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,1,1,1,-1,-1,-1 };
int dy[] = { 1,-1,0,1,-1,0,1,-1 };
bool map[50][50]; //x,y
int h, w;

void BFS(pair<int, int> start)
{
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty())
	{
		int hx = q.front().first;
		int hy = q.front().second;

		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if (nx >= h || nx < 0 || ny >= w || ny < 0) continue;
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
	ios::sync_with_stdio(false);
	while (1)
	{
		memset(map, 0, sizeof(map));
		cin >> w >> h;
		if (w == 0 && h == 0) return 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j])
				{
					map[i][j] = false;
					pair<int, int> start = { i,j };
					BFS(start);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}