#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int solve(string &s, int pos, char pre)
{
	if (pos == s.length()) return 1;
	int ret = 0;
	if (s[pos] == 'd')
	{
		for (char i = '0'; i <= '9'; i++)
		{
			if (pre != i)
			{
				ret += solve(s, pos + 1, i);
			}
		}
	}
	else
	{
		for (char i = 'a'; i <= 'z'; i++)
		{
			if (pre != i)
			{
				ret += solve(s, pos + 1, i);
			}
		}
	}
	return ret;
}

int main()
{
	FAST;
	string s;
	cin >> s;
	cout << solve(s, 0, '!');
}