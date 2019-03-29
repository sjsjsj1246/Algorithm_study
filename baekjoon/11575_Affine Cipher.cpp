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
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		for_each(s.begin(), s.end(), [&](char &c) {
			c = (a*(c-'A') + b) % 26 + 'A';
		});
		cout << s << "\n";
	}
}