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
		string s;
		getline(cin, s);
		if (s == "*") return 0;

		for_each(s.begin(), s.end(), [](char &c) {
			if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
		});

		char key = s[0];
		bool flag = 1;
		while (s.find(" ") != string::npos)
		{
			s = s.substr(s.find(" ") + 1, s.length());
			if (s[0] != key)
			{
				flag = 0;
				break;
			}
		}

		if (flag) cout << "Y\n";
		else cout << "N\n";
	}
}