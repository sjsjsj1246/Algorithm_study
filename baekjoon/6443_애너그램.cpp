#include <iostream>
#include <algorithm>
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
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		do
		{
			cout << s << "\n";
		} while (next_permutation(s.begin(), s.end()));
	}
}