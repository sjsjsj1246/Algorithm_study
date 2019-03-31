#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int a;cin>>a;for(int t=1;t<=a;t++)
typedef long long ll;
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

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
		if (s.find("Simon says") != string::npos)
		{
			cout << s.substr(s.find("Simon says") + 10, s.length()) << "\n";
		}
	}
}