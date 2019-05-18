#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (arr).begin(),(arr).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
int arr[32][32];
ll dp[32][32][3];
int dx[] = { 0, 1, 1 }, dy[] = { 1, 0, 1 };

ll solve(int x, int y, int z)
{
	if (x == n - 1 && y == n - 1) return 1;
	ll& ret = dp[x][y][z];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 3; i++) 
	{
		if (i + z == 1) continue;
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || ny >= n || arr[nx][ny]) continue;
		if (i == 2 && (arr[x][y + 1] || arr[x + 1][y])) continue;
		ret += solve(nx, ny, i);
	}
	return ret;
}

int main() 
{
	FAST;
	cin >> n;
	FOR(i, 0, n) FOR(j, 0, n) cin >> arr[i][j];

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1, 0);
}