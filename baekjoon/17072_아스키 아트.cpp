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

char I(int a, int b, int c)
{
	int ans = 2126 * a + 7152 * b + 722 * c;
	if (ans < 510000) return '#';
	else if (ans < 1020000) return 'o';
	else if (ans < 1530000) return '+';
	else if (ans < 2040000) return '-';
	else return '.';
}

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			cout << I(a, b, c);
		}
		cout << "\n";
	}
}