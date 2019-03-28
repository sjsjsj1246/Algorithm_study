#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	FAST;
	int t;
	cin >> t;
	map<string, double> m;
	m["kg"] = 2.2046;
	m["lb"] = 0.4536;
	m["l"] = 0.2642;
	m["g"] = 3.7854;
	map<string, string> z;
	z["kg"] = "lb";
	z["lb"] = "kg";
	z["l"] = "g";
	z["g"] = "l";
	for (int cases = 1; cases <= t; cases++)
	{
		double n;
		string s;
		cin >> n >> s;
		cout << fixed, cout.precision(4);
		cout << n * m[s] << " "+z[s]+"\n";
	}
	return 0;
}