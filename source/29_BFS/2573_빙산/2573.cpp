#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int visited[301][301];
int map[301][301];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) 
{

	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) 
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if (map[nx][ny] <= 0 && !visited[nx][ny]) 
		{
			map[x][y]--;
			if (map[x][y] < 0)
				map[x][y] = 0;
		}

	}
	for (int i = 0; i < 4; i++) 
	{

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if (map[nx][ny] > 0 && !visited[nx][ny]) 
			dfs(nx, ny);
	}

}



int main() {

	int area = 0;
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];

	while (1) 
	{

		memset(visited, 0, sizeof(visited));
		if (area >= 2) 
		{
			cout << cnt - 1;
			break;
		}

		cnt++;
		area = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > 0 && !visited[i][j]) {
					area++;
					dfs(i, j);
				}
			}
		}

		if (!area)
		{
			cout << 0;
			break;
		}
	}
}