#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1999
#define INF 987654321
typedef long long ll;
using namespace std;

int arr[100001];

void dfs(int pre, int here, vector<vector<int>> &adj)
{
	arr[here] += arr[pre];
	for (auto next : adj[here])
	{
		dfs(here, next, adj);
	}
}

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1, vector<int>());
	FOR(i, 1, n+1)
	{
		int temp;
		cin >> temp;
		if (temp == -1) continue;
		adj[temp].push_back(i);
	}
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		arr[a] += b;
	}
	dfs(0, 1, adj);
	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
}