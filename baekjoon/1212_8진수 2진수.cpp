#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;

int main() 
{
	FAST;
	string s;
	cin >> s;
	if (s == "0")
	{
		cout << 0;
		return 0;
	}
	map<char, string> m;
	m['1'] = "001";
	m['2'] = "010";
	m['3'] = "011";
	m['4'] = "100";
	m['5'] = "101";
	m['6'] = "110";
	m['7'] = "111";
	m['0'] = "000";
	string res = "";
	for (auto c : s) res += m[c];
	cout << res.substr(res.find("1"), res.length());
}