#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	FAST;
	string s;
	cin >> s;
	int t, cnt = 0;
	cin >> t;
	for (int cases = 1; cases <= t; cases++)
	{
		string temp;
		cin >> temp;
		for (int i = 0; i < temp.length(); i++)
		{
			rotate(temp.begin(), temp.begin() + 1, temp.end());
			if (temp.find(s) != string::npos)
			{
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}