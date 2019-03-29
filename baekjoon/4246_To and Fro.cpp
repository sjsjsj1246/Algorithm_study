#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	FAST;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) return 0;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < s.length()/n; j++)
			{
				if(j%2) cout << s[n - i + n * j - 1];
				else cout << s[i + n * j];
			}
		}
		cout << "\n";
	}
}