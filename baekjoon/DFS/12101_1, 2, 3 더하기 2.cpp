#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int n, k;
string ans="00-1";

void dfs(int here, int temp, string s)
{
	s += to_string(temp);
	if (k == 0) return;
	if (here == n)
	{
		k--;
		if (k == 0)
		{
			ans = s;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		if (here + i > n) continue;
		dfs(here + i, i, s + "+");
	}
}

int main()
{
	FAST;
	cin >> n >> k;
	dfs(0, 0, "");
	cout << ans.substr(2);
}