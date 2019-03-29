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
	if (s.length() % 3 == 1) s = "00" + s;
	if (s.length() % 3 == 2) s = "0" + s;

	map<string, string> m;
	m["001"] = "1";
	m["010"] = "2";
	m["011"] = "3";
	m["100"] = "4";
	m["101"] = "5";
	m["110"] = "6";
	m["111"] = "7";
	m["000"] = "0";
	string res = "";

	for (int i = 0; i < s.length() / 3; i++)
	{
		res += m[s.substr(3 * i, 3)];
	}
	
	cout << res;
}