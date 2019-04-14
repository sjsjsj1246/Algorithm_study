#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n, k, temp;
	ll ans = 0;
	cin >> n >> k;
	vector<pair<int, int>> arr(n);
	multiset<int> bag;
	FOR(i, 0, n) cin >> arr[i].second >> arr[i].first;
	FOR(i, 0, k) cin >> temp, bag.insert(temp);
	sort(ALL(arr), greater<pair<int,int>>());
	for (auto x : arr)
	{
		auto it = bag.lower_bound(x.second);
		if (it != bag.end())
		{
			ans += x.first;
			bag.erase(it);
		}
	}
	cout << ans;
}