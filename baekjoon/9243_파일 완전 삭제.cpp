#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	if (n % 2)
	{
		for_each(a.begin(), a.end(), [](char &c) {
			c = (c == '0' ? '1' : '0');
		});
		if (a == b) cout << "Deletion succeeded";
		else cout << "Deletion failed";
	}
	else
	{
		if (a == b) cout << "Deletion succeeded";
		else cout << "Deletion failed";
	}
}