#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	int cnt = 1;
	int temp;
	cin >> temp;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'L') i++;
		cnt++;
	}
	cout << min(temp,cnt);
}