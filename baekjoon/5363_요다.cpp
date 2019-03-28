#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	FAST;
	string temp;
	getline(cin, temp);
	int t = stoi(temp);
	for (int cases = 1; cases <= t; cases++)
	{
		string s;
		getline(cin, s);
		s = s.substr(s.find(" ") + 1, s.length()) + " " + s.substr(0, s.find(" "));
		s = s.substr(s.find(" ") + 1, s.length()) + " " + s.substr(0, s.find(" "));
		cout << s << "\n";
	}
	return 0;
}