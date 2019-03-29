#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	map<char, int> m;
	m['a'] = 1;
	m['e'] = 1;
	m['i'] = 1;
	m['o'] = 1;
	m['u'] = 1;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i];
		if (m[s[i]]) i += 2;
	}
}