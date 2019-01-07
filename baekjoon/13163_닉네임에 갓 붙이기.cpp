#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n; cin >> n; getchar();
	while (n--)
	{
		int flag = 0;
		string s, res;
		getline(cin, s);
		for (int i = 0; i < s.size(); i++)
		{
			if (flag && s[i] != ' ') res += s[i];
			else if (!flag && s[i] == ' ')
			{
				flag = 1;
				res += "god";
			}
		}
		cout << res + '\n';
	}
}