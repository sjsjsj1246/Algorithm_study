#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

string d = "*+-/";

ll cal(ll n, int sw)
{
	switch (sw)
	{
	case 0:
		return n * n;
		break;
	case 1:
		return 2 * n;
		break;
	case 2:
		return 0;
		break;
	case 3:
		return 1;
		break;
	}
}

string bfs(ll start, ll des)
{
	queue<pair<ll, string>> q;
	set<ll> s;
	s.insert(start);
	q.push({ start, "" });
	while (!q.empty())
	{
		pair<ll, string> here = q.front();
		q.pop();
		if (here.first == des) return here.second;
		for (int i = 0; i < 4; i++)
		{
			ll next = cal(here.first, i);
			if (next < 1) continue;
			if (s.find(next) != s.end()) continue;
			s.insert(next);
			q.push({ next, here.second + d[i] });
		}
	}
	return "-1";
}

int main()
{
	FAST;
	ll a, b;
	cin >> a >> b;
	if (a == b) cout << 0;
	else cout << bfs(a, b);
}