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
	string s, Min;
	cin >> s;
	FOR(i, 1, s.length())
	{
		FOR(j, i + 1, s.length())
		{
			string a, b, c;
			a = s.substr(0, i);
			reverse(ALL(a));
			b = s.substr(i, j-i);
			reverse(ALL(b));
			c = s.substr(j, s.length());
			reverse(ALL(c));
			if (i == 1 && j == 2) Min = a + b + c;
			if (Min > a + b + c) Min = a + b + c;

		}
	}
	cout << Min;
}