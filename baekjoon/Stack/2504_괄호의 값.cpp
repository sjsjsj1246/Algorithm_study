#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	stack<pair<char,int>> stk;
	string s;
	cin >> s;

	int ans = 0;
	bool flag = 0;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (c == '(' || c == '[')
		{
			stk.push({ c, 0 });
		}
		else if (c == ')')
		{
			if (stk.empty() || stk.top().first != '(')
			{
				flag = 1;
				break;
			}
			int temp = stk.top().second * 2;
			if (temp == 0) temp = 2;
			stk.pop();
			if (stk.empty()) ans += temp;
			else stk.top().second += temp;
		}
		else if (c == ']')
		{
			if (stk.empty() || stk.top().first != '[')
			{
				flag = 1;
				break;
			}
			int temp = stk.top().second * 3;
			if (temp == 0) temp = 3;
			stk.pop();
			if (stk.empty()) ans += temp;
			else stk.top().second += temp;
		}
	}
	if (flag) cout << 0;
	else cout << ans;
}