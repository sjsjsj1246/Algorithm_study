#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	int t;
	cin >> t;
	for (int cases = 1; cases <= t; cases++)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;

		for (auto c : s)
		{
			if (c == 'c') n++;
			else n--;
		}
		cout << "Data Set " << cases << ":\n" << n << "\n\n";
	}
}