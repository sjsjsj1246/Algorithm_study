#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	int cnt = 1;
	int n, m, ans;
	cin >> n >> m;
	ans = m;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		m += a - b;
		if (m < 0)
		{
			cout << 0;
			return 0;
		}
		ans = max(ans, m);
	}
	cout << ans;
}