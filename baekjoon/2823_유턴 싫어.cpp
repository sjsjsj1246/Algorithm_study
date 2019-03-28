#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

char Map[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

int main()
{
	FAST;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
		}
	}
	bool flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Map[i][j] == '.')
			{
				int cnt = 0;
				for (int d = 0; d < 4; d++)
				{
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
					if (Map[ni][nj] == '.') cnt++;
				}
				if (cnt < 2)
				{
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) break;
	}
	cout << flag;
}