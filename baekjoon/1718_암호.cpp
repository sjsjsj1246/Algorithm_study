#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;

int main()
{
	string s, key;
	getline(cin, s);
	getline(cin, key);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') cout << s[i];
		else if (s[i] - key[i%key.length()] <= 0)
			cout << (char)(s[i] - key[i%key.length()] - 1 + 26 + 'a');
		else
			cout << (char)(s[i] - key[i%key.length()] - 1 + 'a');
	}
}