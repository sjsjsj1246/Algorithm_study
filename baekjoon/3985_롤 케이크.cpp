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
	int n, m;
	cin >> n >> m;
	vector<int> cake(n + 1);
	int ans1 = 0, max1 = 0;
	int ans2 = 0, max2 = 0;
	FOR(i, 1, m + 1)
	{
		int a, b, cnt = 0;
		cin >> a >> b;
		for (int j = a; j <= b; j++)
		{
			if (!cake[j]) cake[j] = i, cnt++;
		}
		if (b - a + 1 > max1)
		{
			max1 = b - a + 1;
			ans1 = i;
		}
		if (max2 < cnt)
		{
			max2 = cnt;
			ans2 = i;
		}
	}
	cout << ans1 << "\n" << ans2;
} 