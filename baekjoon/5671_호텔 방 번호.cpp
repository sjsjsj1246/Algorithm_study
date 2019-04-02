#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int a; cin >> a; for(int t=1;t<=a;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int cnt = 0;

		for (int i = n; i <= m; i++)
		{
			string temp = to_string(i);
			map<char, int> m;
			bool flag = 1;

			for (auto c : temp)
			{
				if (m[c] != 0)
				{
					flag = 0;
					break;
				}
				else m[c]++;
			}

			if (flag) cnt++;
		}

		cout << cnt << "\n";
	}
}