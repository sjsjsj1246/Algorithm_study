#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 187654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n, m, temp;
	cin >> n >> m;
	set<int> arr1, arr2;
	FOR(i, 0, n) cin >> temp, arr1.insert(temp);
	FOR(i, 0, m) cin >> temp, arr2.insert(temp);

	vector<int> ans;
	set_difference(ALL(arr1), ALL(arr2), std::inserter(ans, ans.begin()));
	cout << ans.size() << "\n";
	for (auto x : ans) cout << x << " ";
}