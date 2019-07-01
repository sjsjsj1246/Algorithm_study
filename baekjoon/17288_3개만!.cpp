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
	string s;
	cin >> s;
	s += ' ';
	int cnt = 1, ans = 0;
	for (int i = 0; i < s.length()-1; i++)
	{
		if (s[i] + 1 == s[i + 1])
		{
			cnt++;
		}
		else
		{
			if (cnt == 3) ans++;
			cnt = 1;
		}
	}
	cout << ans;
}