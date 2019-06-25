#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 187654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int cnt = 1;
	while (1)
	{
		string temp;
		int n;
		cin >> n;
		getline(cin, temp);
		if (n == 0) return 0;
		vector<string> s(n);
		vector<bool> check(n);
		FOR(i, 0, n) getline(cin, s[i]);
		FOR(i, 0, 2 * n - 1)
		{
			int a;
			cin >> a >> temp;
			check[a - 1] = check[a - 1] ^ 1;
		}
		FOR(i, 0, n) if (check[i]) cout << cnt << " " << s[i] << "\n";
		cnt++;
	}
}