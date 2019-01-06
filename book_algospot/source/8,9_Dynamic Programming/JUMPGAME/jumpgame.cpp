#include <iostream>
#include <cstring>
using namespace std;

int n;
int map[100][100];
int dp[100][100];

int memo(int y, int x)
{
	if (x >= n || y >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;
	return dp[y][x] += memo(y + map[y][x], x) + memo(y, x + map[y][x]);
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];
		printf("%s\n", memo(0, 0) ? "YES" : "NO");
	}
}