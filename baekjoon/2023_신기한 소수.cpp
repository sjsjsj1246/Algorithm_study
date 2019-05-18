#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

#include <stdio.h>

void dfs(int start, int to)
{
	int len = log10(start) + 1;
	if (len == to)
	{
		cout << start << "\n";
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		if (i % 2 == 0) continue;
		int n = start * 10 + i;
		bool flag = 1;
		int sq = sqrt(n);
		for (int j = 2; j <= sq; j++)
		{
			if (n % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag) dfs(n, to);
	}
}

int main()
{
	FAST;
	int n;
	cin >> n;
	dfs(2, n);
	dfs(3, n);
	dfs(5, n);
	dfs(7, n);
}