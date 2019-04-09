#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int a; cin >> a; for(int t=1;t<=a;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int Map[101][101];

int main()
{
	int n, x_ans = 0, y_ans = 0;
	cin >> n;
	char c;
	FOR(i, 0, n) FOR(j, 0, n) cin >> c, Map[i][j] = (c == '.' ? 0 : 1);

	for (int i = 0; i < n; i++)
	{
		bool flag = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (Map[i][j] == 0 && Map[i][j + 1] == 0) if (flag) x_ans++, j++, flag = 0;
			if (Map[i][j] == 1) flag = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		bool flag = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (Map[j][i] == 0 && Map[j + 1][i] == 0) if (flag) y_ans++, j++, flag = 0;
			if (Map[j][i] == 1) flag = 1;
		}
	}

	cout << x_ans << " " << y_ans;
	return 0;
}