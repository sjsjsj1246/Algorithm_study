#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	CASES(t)
	{
		int n, m;
		cin >> n >> m;
		int x = 0, y = 0, temp;
		FOR(i, 0, m) cin >> temp, x *= 10, x += temp;
		FOR(i, 0, m) cin >> temp, y *= 10, y += temp;
		vector<int> arr(n);
		FOR(i, 0, n) cin >> arr[i];

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int num = 0;
			for (int j = 0, p = i; j < m; j++)
			{
				num *= 10;
				num += arr[p];
				p++;
				if (p == arr.size()) p = 0;
			}
			if (x <= num && y >= num)ans++;
		}
		cout << ans << "\n";
	}
}