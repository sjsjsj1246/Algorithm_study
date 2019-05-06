#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int n;
bool check[2000001];

void dfs(int pos, int sum, vector<int>& arr)
{
	if (sum > 2000001) return;
	check[sum] = 1;
	if (pos >= n) return;
	dfs(pos + 1, sum + arr[pos], arr);
	dfs(pos + 1, sum, arr);
}

int main()
{
	FAST;
	cin >> n;
	vector<int> arr(n);
	FOR(i, 0, n) cin >> arr[i];
	dfs(0, 0, arr);
	for (int i = 1; i <= 2000001; i++)
	{
		if (!check[i])
		{
			cout << i;
			break;
		}
	}
}