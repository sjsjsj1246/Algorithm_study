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
	FAST;
	int n, m, h;
	cin >> n >> m >> h;
	vector<vector<int>> arr(n, vector<int>(m));
	vector<int> col(m);
	vector<int> row(n);
	FOR(i, 0, m) cin >> col[i];
	FOR(i, 0, n) cin >> row[i];
	FOR(i, 0, n) FOR(j, 0, m) cin >> arr[i][j];
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (arr[i][j])
			{
				arr[i][j] = min(row[i], col[j]);
			}
		}
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}