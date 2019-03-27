#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;


int main()
{
	FAST;
	while (1)
	{
		string s;
		getline(cin, s);
		if (s == ".") return 0;
		stack<char> stk;

		bool flag = 1;
		for (auto c : s)
		{
			if (c == '(') stk.push(c);
			if (c == ')')
			{
				if (stk.empty())
				{
					cout << "no\n";
					flag = 0;
					break;
				}
				if (stk.top() != '(')
				{
					cout << "no\n";
					flag = 0;
					break;
				}
				else stk.pop();
			}
			if (c == '[') stk.push(c);
			if (c == ']')
			{
				if (stk.empty())
				{
					cout << "no\n";
					flag = 0;
					break;
				}
				if (stk.top() != '[')
				{
					cout << "no\n";
					flag = 0;
					break;
				}
				else stk.pop();
			}
		}
		if (flag)
		{
			if(!stk.empty()) cout << "no\n";
			else cout << "yes\n";
		}
	}
}