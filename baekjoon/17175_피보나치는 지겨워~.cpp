#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int cache[51] = { 1,1 };

int main()
{
	FAST;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		cache[i] = cache[i - 1] + cache[i - 2] + 1;
		cache[i] %= MOD;
	}
	cout << cache[n];
}