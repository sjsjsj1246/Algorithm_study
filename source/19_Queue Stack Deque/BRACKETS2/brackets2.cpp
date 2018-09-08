#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		bool flag = 1;
		string ins; cin >> ins;
		stack<char> Stack;
		int len = ins.length();
		for (int i = 0; i < len; i++)
		{
			if (ins[i] == '(' || ins[i] == '{' || ins[i] == '[')
			{
				Stack.push(ins[i]);
			}
			else
			{
				if (Stack.empty())
				{
						flag = 0;
					break;
				}
				if (ins[i] == ')')
				{
					if (Stack.top() != '(')
					{
						flag = 0;
						break;
					}
					else
						Stack.pop();
				}
				else if (ins[i] == '}')
				{
					if (Stack.top() != '{')
					{
						flag = 0;
						break;
					}
					else
						Stack.pop();
				}
				else if (ins[i] == ']')
				{
					if (Stack.top() != '[')
					{
						flag = 0;
						break;
					}
					else
						Stack.pop();
				}
			}
		}
		if (flag&&Stack.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}