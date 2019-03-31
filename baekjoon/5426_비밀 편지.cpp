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
	CASES(t)
	{
		string s;
		cin >> s;

		int size = sqrt(s.length());
		for (int i = size-1; i >=0; i--)
		{
			for (int j = 0; j < size; j++)
			{
				cout << s[size*j+i];
			}
		}
		cout << "\n";
	}
}