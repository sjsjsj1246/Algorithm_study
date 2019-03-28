#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	int t;
	cin >> t;
	for (int cases = 1; cases <= t; cases++)
	{
		int a, b, c;
		string d, e;
		cin >> a >> d >> b >> e >> c;
		if (d == "+")
		{
			if (a + b == c)
				cout << "Case " << cases << ": YES\n";
			else
				cout << "Case " << cases << ": NO\n";
		}
		else
		{
			if (a - b == c)
				cout << "Case " << cases << ": YES\n";
			else
				cout << "Case " << cases << ": NO\n";
		}
	}
}