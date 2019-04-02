#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int a; cin >> a; for(int t=1;t<=a;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	CASES(t)
	{
		int n, temp;
		cin >> n;
		map<int, int> m;

		while (n--) cin >> temp, m[temp]++;
		
		int Max = 0, num = 0;
		for (auto x : m)
		{
			if (Max < x.second)
			{
				num = x.first;
				Max = x.second;
			}
		}

		cout << num << "\n";
	}
}