#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

bool cmp(char &a, char &b)
{

}

int main()
{
	FAST;;
	for (int cases = 1; ; cases++)
	{
		int a, b;
		string s;
		cin >> a >> s >> b;
		if (s == "E") return 0;
		cout << boolalpha;
		if (s == "!=") cout << "Case " << cases << ": " << (a != b) << "\n";
		if (s == ">=") cout << "Case " << cases << ": " << (a >= b) << "\n";
		if (s == "<=") cout << "Case " << cases << ": " << (a <= b) << "\n";
		if (s == ">") cout << "Case " << cases << ": " << (a > b) << "\n";
		if (s == "<") cout << "Case " << cases << ": " << (a < b) << "\n";
		if (s == "==") cout << "Case " << cases << ": " << (a == b) << "\n";
	}
}