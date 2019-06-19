#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 2000000000
#define INF 987654321
typedef long long ll;
using namespace std;


void getSum(vector<int> &res, vector<int> &arr, int here, int to, int sum)
{
	if (here == to)
	{
		res.push_back(sum);
		return;
	}
	getSum(res, arr, here + 1, to, sum + arr[here]);
	getSum(res, arr, here + 1, to, sum);
}

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	FOR(i, 0, n) cin >> arr[i];
	vector<int> a;
	getSum(a, arr, 0, n / 2 + 1, 0);
	vector<int> b;
	getSum(b, arr, n / 2 + 1, n, 0);
	sort(ALL(a));
	sort(ALL(b));

	ll ans = 0;

	int i = 0, j = b.size() - 1;
	for (int x : a)
	{
		int target = m - x;
		auto hi = upper_bound(ALL(b), target);
		auto lo = lower_bound(ALL(b), target);
		ans += hi - lo;
	}

	cout << ans - (m == 0 ? 1 : 0);
}
