#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;

char Map[11][11];
char nMap[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Map[i][j] == 'X')
			{
				int cnt = 0;
				for (int d = 0; d < 4; d++)
				{
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni < 0 || ni >= n || nj < 0 || nj >= m)
					{
						cnt++;
						continue;
					}
					if (Map[ni][nj] == '.') cnt++;
				}
				if (cnt >= 3) nMap[i][j] = '.';
				else nMap[i][j] = 'X';
			}
			else
				nMap[i][j] = '.';
		}
	}

	int minx = 987654321, maxx = 0;
	for (int i = 0; i < n; i++)
	{
		bool flag = 0;
		for (int j = 0; j < m; j++)
		{
			if (nMap[i][j] == 'X')
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			minx = min(minx, i);
			maxx = max(maxx, i);
		}
	}

	int miny = 987654321, maxy = 0;
	for (int j = 0; j < m; j++)
	{
		bool flag = 0;
		for (int i = 0; i < n; i++)
		{
			if (nMap[i][j] == 'X')
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			miny = min(miny, j);
			maxy = max(maxy, j);
		}
	}

	for (int i = minx; i <= maxx; i++)
	{
		for (int j = miny; j <= maxy; j++)
		{
			cout << nMap[i][j];
		}
		cout << "\n";
	}
}