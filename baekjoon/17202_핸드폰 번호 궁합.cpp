#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	string a, b;
	string c, temp;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
	{
		c += a[i];
		c += b[i];
	}
	while (c.length() != 2)
	{
		for (int i = 0; i < c.length() - 1; i++)
		{
			temp += (c[i] + c[i + 1] - '0' * 2) % 10 + '0';
		}
		c = temp;
		temp = "";
	}
	cout << c;
}