#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll two = 0, five = 0;
		for (ll i = 2; i <= n; i *= 2) two += n / i;
		for (ll i = 5; i <= n; i *= 5) five += n / i;
		cout << min(two, five) << "\n";
	}
}