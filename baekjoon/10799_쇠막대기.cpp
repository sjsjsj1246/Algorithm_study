#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef signed long long ll;

#define FOR(x,to) for(x=0;x<(to);x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

int main()
{
	stack<char> Stack;
	string s;
	int cnt = 0, sum = 0;
	cin >> s;
	char temp;
	for (char c : s)
	{
		if (c == ')')
		{
			if (temp == '(')
			{
				Stack.pop();
				sum += cnt - 1;
				cnt--;
			}
			else
			{
				Stack.pop();
				sum += 1;
				cnt--;
			}
		}
		else
		{
			cnt++;
			Stack.push(c);
		}
		temp = c;
	}
	cout << sum;
}