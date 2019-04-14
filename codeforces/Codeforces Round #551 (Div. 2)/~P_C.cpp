#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	stack<char> stk;
	string s;
	int n;
	cin >> n >> s;
	if (n % 2 || s.front() == ')' || s.back() == '(')
	{
		cout << ":(";
		return 0;
	}

	bool flag = 0;
	string res = "(";
	for (int i = 1; i < s.length() - 1; i++)
	{
		char c = s[i];
		if (c == '(')
		{
			stk.push(c);
			res += '(';
		}
		else if (c == ')')
		{
			if (stk.empty())
			{
				flag = 1;
				break;
			}
			else
			{
				stk.pop();
				res += ')';
			}
		}
		else
		{
			if (stk.empty()) stk.push('('), res += '(';
			else stk.pop(), res+=')';
		}
	}
	if (!stk.empty() || flag) cout << ":(";
	else cout << res + ')';
}