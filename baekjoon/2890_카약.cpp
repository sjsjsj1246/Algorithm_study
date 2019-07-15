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
	int r, c;
	cin >> r >> c;
	vector<int> ans(10);
	char Map[51][51];
	FOR(i, 0, r) FOR(j, 0, c) cin >> Map[i][j];

	int rank = 1;
	for (int i = c - 2; i > 0; i--)
	{
		bool flag = 0;
		for (int j = 0; j < r; j++)
		{
			char n = Map[j][i];
			if (n >= '1' && n <= '9')
			{
				if (!ans[n - '0'])
				{
					flag = 1;
					ans[n - '0'] = rank;
				}
			}
		}
		if (flag) rank++;
	}
	for (int i = 1; i < ans.size(); i++) cout << ans[i] << "\n";
}