#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> scores;
	vector<int> share(n), team(n);
	FOR(i, 0, n) cin >> share[i];
	FOR(i, 0, n) cin >> team[i];
	FOR(i, 0, n) FOR(j, 0, n) scores.push_back({ share[i] * team[j], team[j] });
	sort(ALL(scores));
	int cnt = 0;
	map<int, bool> m;
	for (auto it = scores.rbegin(); it != scores.rend(); it++)
	{
		if (m[(*it).second]) continue;
		if (cnt == k)
		{
			cout << (*it).first;
			return 0;
		}

		m[(*it).second] = 1;
		cnt++;
	}
}