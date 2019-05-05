#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int pow(int n) { return n * n; }

int main()
{
	FAST;
	int a, b, c;
	cin >> a >> b >> c;

	int ans = -1;
	for (int i = 1; i <= 100; i++)
	{
		if (pow(a) * i * i + 2 * a * b * c * i + pow(a) * pow(b) + pow(a) * pow(c) - pow(a) * pow(a) == 0)
		{
			ans = i;
			break;
		}
	}

	cout << ans;
}