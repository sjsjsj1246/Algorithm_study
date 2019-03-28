#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	int t;
	cin >> t;
	while(t--)
	{
		map<char, int> m;
		string s;
		char next = 'a';
		bool flag = 0;
		cin >> s;
		for (auto c : s)
		{
			if (next != 'a')
			{
				if (next != c)
				{
					flag = 1;
					break;
				}
				else
				{
					flag = 0;
					next = 'a';
				}
			}
			else
			{
				m[c]++;
				if (m[c] % 3 == 0) next = c, flag = 1;
			}
		}
		if (flag) cout << "FAKE\n";
		else cout << "OK\n";
	}
}