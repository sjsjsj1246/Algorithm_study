#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
using namespace std;

int n, k;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int arr[9][9];

int dfs(int x, int y)
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		for (int a = 0; a <= k; a++)
		{
			arr[nx][ny] -= a;
			int temp = k;
			if (a != 0) k = 0;
			if (arr[x][y] > arr[nx][ny])
			{
				ret = max(ret, 1 + dfs(nx, ny));
			}
			arr[nx][ny] += a;
			k = temp;
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t, cnt = 0;
	cin >> t;
	while (t--)
	{
		cnt++;
		int ans = 0, max_num;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				max_num = max(max_num, arr[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == max_num)
				{
					ans = max(ans, dfs(i, j));
				}
			}
		}
		cout << "#" << cnt << " " << ans << "\n";
	}
}