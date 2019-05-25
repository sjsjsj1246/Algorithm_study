#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;


int main()
{
	FAST;
	pair<int, int> arr[5][5];
	string name[5] = { "Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki" };
	FOR(i, 0, 5) FOR(j, 0, 5) cin >> arr[i][j].first;
	FOR(i, 0, 5) FOR(j, 0, 5) cin >> arr[i][j].second;
	vector<pair<int, string>> can(5);
	FOR(i, 0, 5) can[i].second = name[i];
	FOR(x, 0, 5)
	{
		FOR(y, 0, 5)
		{
			FOR(i, 0, 5)
			{
				can[x].first += arr[x][i].first * arr[i][y].second;
			}
		}
	}
	sort(ALL(can), [](pair<int,string>a, pair<int,string> b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
		});
	cout << can[0].second;
}