#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

#include <stdio.h>

int main()
{
	FAST;
	int r, c;
	cin >> r >> c;
	int ans[5] = { 0, };
	vector<vector<char>> arr(r, vector<char>(c));
	FOR(i, 0, r) FOR(j, 0, c) cin >> arr[i][j];

	for (int i = 0; i < r - 1; i++)
	{
		for(int j = 0; j < c - 1; j++)
		{
			int cnt = 0;
			bool flag = 0;
			for (int x = i; x < i + 2; x++)
			{
				for (int y = j; y < j + 2; y++)
				{
					if (arr[x][y] == '#')
					{
						flag = 1;
						break;
					}
					if (arr[x][y] == 'X') cnt++;
				}
				if (flag) break;
			}
			if (!flag) ans[cnt]++;
		}
	}
	for (auto x : ans) cout << x << "\n";
}