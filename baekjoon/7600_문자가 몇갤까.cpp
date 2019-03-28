#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	string s;
	while (1)
	{
		map<char, int> m;
		getline(cin, s);
		if (s == "#") return 0;
		for (auto c : s)
		{
			if (c >= 'a' && c <= 'z') m[c]++;
			if (c >= 'A'&&c <= 'Z') m[c - 'A' + 'a']++;
		}
		cout << m.size() << "\n";
	}
}