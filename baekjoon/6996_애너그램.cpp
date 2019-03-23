#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;

		int ca[26] = {}, cb[26] = {};
		for (char c : a) ca[c - 'a']++;
		for (char c : b) cb[c - 'a']++;

		bool flag = 1;
		for (int i = 0; i < 26; i++)
		{
			if (ca[i] != cb[i])
			{
				cout << a << " & " << b << " are NOT anagrams.\n";
				flag = 0;
				break;
			}
		}
		if(flag) cout << a << " & " << b << " are anagrams.\n";
	}
}