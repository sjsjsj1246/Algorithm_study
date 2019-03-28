#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	string temp;
	getline(cin, temp);
	int t = stoi(temp);
	for (int i = 1; i <= t; i++)
	{
		string s;
		getline(cin, s);
		map<char, int> m;
		int Min = 987654321;
		for (auto c : s)
		{
			if (c >= 'a'&&c <= 'z') m[c]++;
			if (c >= 'A'&&c <= 'Z') m[c - 'A' + 'a']++;
		}
		for (char j = 'a'; j <= 'z'; j++)
			Min = min(Min, m[j]);
		if (Min == 0) printf("Case %d: Not a pangram\n", i);
		else if (Min == 1) printf("Case %d: Pangram!\n", i);
		else if (Min == 2) printf("Case %d: Double pangram!!\n", i);
		else if (Min == 3) printf("Case %d: Triple pangram!!!\n", i);
	}
	return 0;
}