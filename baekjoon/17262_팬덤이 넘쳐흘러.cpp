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
	int n;
	cin >> n;
	int min_end = 100000, max_begin = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		min_end = min(min_end, b);
		max_begin = max(max_begin, a);
	}
	int ans = max_begin - min_end;
	cout << (ans < 0 ? 0 : ans);
}