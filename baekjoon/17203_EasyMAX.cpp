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
	int n, q;
	cin >> n >> q;
	vector<int> arr(n + 1);
	FOR(i, 1, n + 1) cin >> arr[i];
	FOR(t, 0, q)
	{
		int i, j, sum = 0;
		cin >> i >> j;
		if (j - 1 < i) cout << 0 << "\n";
		else
		{
			for (int k = i; k < j; k++)
			{
				sum += abs(arr[k + 1] - arr[k]);
			}
			cout << sum << "\n";
		}
	}
}