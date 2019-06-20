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
	CASES(t)
	{
		string a, b;
		cin >> a >> b;

		bool flag = 1;
		int j = 0;
		for (int i = 0; i < b.length(); i++)
		{
			if (b[i] == a[j]) j++;
			else
			{
				if (i > 0 && b[i - 1] == b[i]) continue;
				else
				{
					flag = 0;
					break;
				}
			}
			if (j == a.length())
			{
				bool flag2 = 1;
				for (int k = i; k < b.length(); k++)
				{
					if (b[k] != a[j - 1])
					{
						flag2 = 0;
						break;
					}
				}
				if (flag2) break;
				else
				{
					flag = 0;
					break;
				}
			}
 		}
		if (j != a.length()) flag = 0;
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}