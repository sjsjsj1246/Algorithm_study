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
	int n, l;
	cin >> n >> l;
	vector<int> arr(n);
	FOR(i, 0, n) cin >> arr[i];
	sort(ALL(arr));

	int ans = 0;
	double pos = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (pos > arr[i]) continue;
		pos = arr[i];
		pos += l - 0.5;
		ans++;
	}
	cout << ans;
}