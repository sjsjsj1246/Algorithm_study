#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (arr).begin(),(arr).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

bool prime[1000000] = { 1,1, };

int main()
{
	for (int i = 2; i < 1000; i++)
	{
		if (prime[i]) continue;
		for (int j = 2; i * j < 1000000; j++)
		{
			prime[i * j] = 1;
		}
	}
	vector<int> p;
	for (int i = 0; i < 1000000; i++) if (!prime[i] && i%2) p.push_back(i);

	FAST;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (prime[n - p[i]] == 0)
			{
				cout << n << " = " << p[i] << " + " << n - p[i] << "\n";
				break;
			}
		}
	}
}