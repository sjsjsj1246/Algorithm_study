#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int a;cin>>a;for(int t=1;t<=a;t++)
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	CASES(t)
	{
		string in;
		cin >> in;
		string b = in.substr(in.find("-") + 1, in.length());
		string a = in.substr(0, in.find("-"));

		int cost = 0;
		for (int i = 0, p = pow(26,a.length()-1); i < a.length(); i++, p /= 26) cost += (a[i]-'A') * p;

		if (abs(cost - stoi(b)) <= 100) cout << "nice\n";
		else cout << "not nice\n";
	}
}