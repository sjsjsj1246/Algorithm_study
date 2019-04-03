#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int a; cin >> a; for(int t=1;t<=a;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	string temp;
	getline(cin, temp);
	int t = stoi(temp);
	while(t--)
	{
		string s;
		getline(cin, s);
		while (s.find(" ") != string::npos)
		{
			string out = s.substr(0, s.find(" "));
			reverse(ALL(out));
			cout << out << " ";
			s = s.substr(s.find(" ") + 1, s.length());
		}
		reverse(ALL(s));
		cout << s << " ";
		cout << "\n";
	}
}