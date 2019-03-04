#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int nomal_map[101][101];
int rg_map[101][101];
bool visit[101][101];

void bfs(pair<int, int> start, int Map[][101])
{
	queue<pair<int, int>> q;
	q.push(start);
	visit[start.first][start.second] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (!visit[nx][ny] && Map[nx][ny] == Map[start.first][start.second])
			{
				q.push({ nx, ny });
				visit[nx][ny] = 1;
			}
		}
	}
}

int main()
{
	int ans = 0;
	char temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			if (temp == 'R') nomal_map[i][j] = 1, rg_map[i][j] = 1;
			if (temp == 'G') nomal_map[i][j] = 2, rg_map[i][j] = 1;
			if (temp == 'B') nomal_map[i][j] = 3, rg_map[i][j] = 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				bfs({ i,j }, nomal_map);
				ans++;
			}
		}
	}
	cout << ans;
	memset(visit, 0, sizeof(visit));
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				bfs({ i,j }, rg_map);
				ans++;
			}
		}
	}
	cout << " " << ans;
}