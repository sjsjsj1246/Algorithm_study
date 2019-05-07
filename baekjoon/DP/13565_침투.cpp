#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool arr[1001][1001];
bool visit[1001][1001];
int dp[1001][1001];

bool dfs(int x, int y)
{
	if (x == n - 1) return 1;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny >= m || ny < 0 || visit[nx][ny]) continue;
		visit[nx][ny] = 1;
		ret += dfs(nx, ny);
		if (ret > 1) ret = 1;
		visit[nx][ny] = 0;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j] - '0';
			visit[i][j] = arr[i][j];
		}
	}
	for (int j = 0; j < m; j++)
	{
		if (visit[0][j]) continue;
		if (dfs(0, j))
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}