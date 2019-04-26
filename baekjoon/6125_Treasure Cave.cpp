#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

vector<pair<int, int>> adj;
vector<int> res;
int t;

int dfs(int here, vector<int> &arr)
{
	arr.push_back(here);
	if (here == t)
	{
		res = arr;
		return 1;
	}

	if (adj[here].first != 0)
	{
		if (dfs(adj[here].first, arr)) return 1;
		if (dfs(adj[here].second, arr)) return 1;
	}
	arr.pop_back();
	return 0;
}

int main()
{
	FAST;

	int p, ns;
	cin >> p >> ns >> t;
	adj.resize(p + 1);
	FOR(i, 0, ns)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].first = b;
		adj[a].second = c;
	}
	
	vector<int> temp;
	dfs(1, temp);
	cout << res.size() << "\n";
	for (auto x : res) cout << x << "\n";
}