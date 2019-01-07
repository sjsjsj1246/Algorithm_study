#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int map[101][101], visited[101][101], area[100];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int m, n, cnt;

int dfs(int x, int y) {
	int nextX = 0, nextY = 0;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		nextX = dx[i] + x; nextY = dy[i] + y;
		if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n)
			if (map[nextX][nextY] == 0 && visited[nextX][nextY] == 0) {
				area[cnt]++;
				dfs(nextX, nextY);
			}
	}
	return area[cnt];
}

int main()
{
	int k;
	vector<int> res;
	cin >> m >> n >> k;
	for(int i = 0; i < k; i++)
	{
		int ax, bx, ay, by;
		cin >> ax >> ay >> bx >> by;
		for (int dx = ax; dx < bx; dx++)
			for (int dy = ay; dy < by; dy++)
				map[dy][dx] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!map[i][j] && !visited[i][j])
			{
				area[cnt] = dfs(i, j) + 1;
				cnt++;
			}
		}
	}
	sort(area, area + cnt);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		printf("%d ", area[i]);
	}
}