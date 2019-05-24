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
	
	CASES(t)
	{
		int ans = 0;
		int a, b, c;
		cin >> a >> b >> c;
		while (1)
		{
			a += c * ans;
			if (a >= b)
			{
				cout << ans << "\n";
				break;
			}
			ans++;
		}
	}
}