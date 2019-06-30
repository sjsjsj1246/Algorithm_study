#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

double adj[4][4];
bool visit[4];
double ans = INF;
void dfs(int here, int cnt, double sum)
{
	if (cnt == 4)
	{
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (i == here) continue;
		if (!visit[i])
		{
			visit[i] = 1;
			dfs(i, cnt + 1, sum + adj[here][i]);
			visit[i] = 0;
		}
	}
}

int main()
{
	FAST;
	pair<double,double> pos[4];
	FOR(i, 0, 4) cin >> pos[i].first >> pos[i].second;
	FOR(i, 0, 4)
	{
		FOR(j, i + 1, 4)
		{
			pair<double, double> a = pos[i];
			pair<double, double> b = pos[j];
			adj[i][j] = adj[j][i] = sqrt((a.first - b.first) * (a.first - b.first) 
				+ (a.second - b.second) * (a.second - b.second));
		}
	}
	visit[0] = 1;
	dfs(0, 1, 0);
	cout << (int)ans;
}