#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s, k;
		cin >> s >> k;

		int cnt = 0;
		while (s.find(k) != string::npos)
		{
			cnt += s.find(k) + 1;
			s = s.substr(s.find(k) + k.length(), s.length());
		}
		cout << cnt + s.length() << "\n";
	}
}