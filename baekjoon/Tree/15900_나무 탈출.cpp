#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

vector<vector<int>> tree;
bool visit[500001] = { 1 ,1 };
ll res;

void dfs(int here, int cnt)
{
	if (tree[here].size() == 1 && here != 1)
	{
		res += cnt;
		return;
	}
	for (auto next : tree[here])
	{
		if (!visit[next])
		{
			visit[next] = 1;
			dfs(next, cnt + 1);
		}
	}
}

int main()
{
	FAST;
	int n;
	cin >> n;
	tree = vector<vector<int>>(n + 1, vector<int>());
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[b].push_back(a);
		tree[a].push_back(b);
	}

	dfs(1, 0);
	if (res % 2) cout << "Yes";
	else cout << "No";
}