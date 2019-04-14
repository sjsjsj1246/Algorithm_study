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
	int n;
	cin >> n;
	map<string, int> m;
	string s;
	FOR(i, 0, n) cin >> s, m[s]++;

	int Max = 0;
	string ans = s;
	for (auto x : m) 
	{
		if (Max < x.second)
		{
			Max = x.second;
			ans = x.first;
	 	}
	}
	cout << ans;
}