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
		string s;
		getline(cin, s);
		if (s == "EOI") return 0;
		for_each(s.begin(), s.end(), [](char &c) {
			if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
		});
		if (s.find("nemo") != string::npos) cout << "Found\n";
		else cout << "Missing\n";
	}
}