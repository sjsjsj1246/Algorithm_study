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
	double a, b, c, d;
	cin >> a >> b >> c >> d;

	double Max = 0;
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		double sum = a / c + b / d;
		if (Max < sum)
		{
			Max = sum;
			cnt = i;
		}
		double ta = a, tb = b, tc = c, td = d;
		a = tc;
		b = ta;
		c = td;
		d = tb;
	}
	cout << cnt;
}