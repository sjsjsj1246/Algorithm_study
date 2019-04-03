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
	int n;
	cin >> n;

	for (int i = n; i >= 4; i--)
	{
		string s = to_string(i);
		bool flag = 1;
		for (auto c : s)
		{
			if (c != '4' && c != '7')
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			cout << i;
			break;
		}
	}
}