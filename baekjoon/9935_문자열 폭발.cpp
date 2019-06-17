#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	string s, bomb, ans;
	bool check;
	cin >> s >> bomb;

	for (int i = 0; i < s.length(); i++)
	{
		ans += s[i];
		if (s[i] == bomb[bomb.length() - 1] && i >= bomb.length() - 1)
		{
			check = true;
			for (int j = 1; j < bomb.length(); j++)
			{
				if (ans[ans.size() - 1 - j] != bomb[bomb.length() - 1 - j])
				{
					check = false;
					break;
				}
			}
			if (check)
			{
				for (int k = 0; k < bomb.length(); k++)
				{
					ans.pop_back();
				}
			}
		}
	}
	cout << (ans.empty() ? "FRULA" : ans);
}