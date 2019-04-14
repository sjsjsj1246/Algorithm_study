#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	int n, m, ans = 0;
	cin >> n >> m;
	vector<vector<int>> arr1(n, vector<int>(m));
	vector<vector<int>> arr2(n, vector<int>(m));
	FOR(i, 0, n) FOR(j, 0, m) scanf("%1d", &arr1[i][j]);
	FOR(i, 0, n) FOR(j, 0, m) scanf("%1d", &arr2[i][j]);
	FOR(i, 0, n-2)
	{
		FOR(j, 0, m-2)
		{
			if (arr1[i][j] != arr2[i][j])
			{
				FOR(x, i, i + 3)
				{
					FOR(y, j, j + 3)
					{
						arr1[x][y] = arr1[x][y] ? 0 : 1;
					}
				}
				ans++;
			}
		}
	}

	bool flag = 0;
	FOR(i, 0, n) FOR(j, 0, m) if (arr1[i][j] != arr2[i][j]) { flag = 1; break; }
	if (flag) cout << -1;
	else cout << ans;
}