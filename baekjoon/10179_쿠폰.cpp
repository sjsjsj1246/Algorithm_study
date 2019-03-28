#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		double price;
		cin >> price;
		price *= 0.8;

		cout << fixed, cout.precision(2);
		cout << "$" << price << "\n";
	}
	return 0;
}