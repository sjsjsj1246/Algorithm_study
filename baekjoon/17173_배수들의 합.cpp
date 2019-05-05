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
	int n, m;
	cin >> n >> m;

	vector<bool> check(n + 1, 0);
	FOR(i, 0, m)
	{
		int temp;
		cin >> temp;
		for (int i = 1; i * temp <= n; i++) check[i * temp] = 1;
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) if (check[i]) sum += i;
	cout << sum;
}