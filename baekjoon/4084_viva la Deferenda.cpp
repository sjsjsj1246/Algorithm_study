#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int a;cin>>a;for(int t=1;t<=a;t++)
typedef long long ll;
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	FAST;
	while(1)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0) return 0;

		int cnt = 0;
		while (!(a == b && b == c && c == d && d == a))
		{
			int ta=a, tb=b, tc=c, td=d;
			cnt++;
			a = abs(ta - tb);
			b = abs(tb - tc);
			c = abs(tc - td);
			d = abs(td - ta);
		}
		cout << cnt << "\n";
	}
}