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
vector<vector<int>> adj;
vector<int> visit;
vector<int> ans;

int dfs(int start, int here, vector<int> & arr)
{
	if (visit[here])
	{
		if (here == start)
		{
			for (auto x : arr) ans.push_back(x);
			return 1;
		}
		else return 0;
	}

	visit[here] = 1;
	for (int there : adj[here])
	{
		arr.push_back(there);
		if (dfs(start, there, arr)) return 1;
		arr.pop_back();
		visit[here] = 0;
	}
	return 0;
}

int main()
{
	FAST;
	cin >> n;
	adj = vector<vector<int>>(n + 1, vector<int>());
	visit = vector<int>(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		adj[i + 1].push_back(temp);
	}

	for (int i = 1; i <= n; i++)
	{
		vector<int> arr;
		if (!visit[i])
		{
			dfs(i, i, arr);
		}
	}

	sort(ALL(ans));
	cout << ans.size() << "\n";
	for (auto x : ans) cout << x << "\n";
}