#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	FAST;
	while (1)
	{
		string s;
		getline(cin, s);
		if (s == "#") return 0;
		
		int sum = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ') continue;
			sum += (s[i] - 'A' + 1)*(i + 1);
		}
		cout << sum << "\n";
	}
	return 0;
}