#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;

int main() 
{
	FAST;
	map<char, bool> m;
	m['a'] = 1;
	m['e'] = 1;
	m['i'] = 1;
	m['o'] = 1;
	m['u'] = 1;
	while (1)
	{
		int cnt = 0;
		string s;
		cin >> s;
		if (s == "#") return 0;
		while (!m[s[0]])
		{
			rotate(s.begin(), s.begin() + 1, s.end());
			cnt++;
			if (cnt == s.length()) break;
		}
		cout << s + "ay\n";
	}
}