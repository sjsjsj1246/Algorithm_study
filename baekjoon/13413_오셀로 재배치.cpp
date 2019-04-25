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
	CASES(t)
	{
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;

		int a_cnt = 0, b_cnt = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			a_cnt += a[i] == 'W' ? 0 : 1;
			b_cnt += b[i] == 'W' ? 0 : 1;
			if (a[i] != b[i]) cnt++;
		}

		int d = abs(a_cnt - b_cnt);
		cnt -= d;
		cout << d + cnt / 2 + cnt % 2 << "\n";
	}
}