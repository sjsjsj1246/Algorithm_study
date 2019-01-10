#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#define INF 987654321
#define MOD 1000000000
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int LL;
using namespace std;

int n;
int map[500][500], dp[500][500];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


/*
1937 욕심쟁이 판다
dp, top-down / DFS
LIS  problem
-----------------
dp[][] LIS 저장

memo()
for(i:4) ret = max(ret,memo()+1)
return ret

-----------------
LIS의 2차원화 기본원리는 같음
*/

int memo(int x, int y, int cnt)
{
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (map[x][y] >= map[nx][ny]) continue;
		ret = max(ret, memo(nx, ny, cnt + 1) + 1);
	}
	return ret;
}

int main()
{
	fast;
	int max = 0;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			memo(i, j, 0);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < dp[i][j]) max = dp[i][j];
		}
	}
	cout << max + 1;
}