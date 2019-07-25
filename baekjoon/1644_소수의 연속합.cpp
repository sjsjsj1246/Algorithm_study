#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;
//투포인터, 에라토스테네스의 체
bool np[4000001] = {1, 1};

int main()
{
	FAST;
	int n;
	cin >> n;
	vector<int> prime;
	for (int i = 0; i * i <= n; i++)
	{
		if (np[i]) continue;
		for (int j = 2; j * i <= n; j++)
			np[j * i] = 1;
	}
	for (int i = 0; i <= n; i++) if (!np[i]) prime.push_back(i);
	int ans = 0, sum = 0, lo = 0, hi = 0;
	while (1) 
	{
		if (sum >= n) sum -= prime[lo++];
		else if (hi == prime.size()) break;
		else sum += prime[hi++];
		if (sum == n) ans++;
	}
	cout << ans;
}