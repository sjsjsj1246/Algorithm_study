#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000000
#define INF 987654321
typedef long long ll;
using namespace std;

int pow(int n, int m)
{
	if (m == 0) return 1;
	int ret = 1;
	for (int i = 0; i < m; i++) ret *= n;
	return ret;
}

int f(int n, int p)
{
	int ret = 0;
	while (n > 0)
	{
		ret += pow(n % 10, p);
		n /= 10;
	}
	return ret;
}

int main() 
{
	FAST;
	int n, p;
	cin >> n >> p;
	bool arr[236197] = { 0, };
	vector<int> ans;

	int start = n;
	ans.push_back(n);
	arr[n] = 1;
	while (1)
	{
		n = f(n, p);
		if (!arr[n])
		{
			arr[n] = 1;
			ans.push_back(n);
		}
		else
		{
			start = n;
			break;
		}
	}

	int cnt = 0;
	for (auto x : ans)
	{
		if (x == start) break;
		cnt++;
	}
	cout << cnt;
}