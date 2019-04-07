#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int abcd; cin >> abcd; for(int t=1;t<=abcd;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	CASES(t)
	{
		int n;
		string s;
		cin >> n >> s;
		for_each(ALL(s), [](char& c) {
			c = (c == 'E' ? 'S' : 'E');
			});
		cout << "Case #" << t << ": " << s << "\n";
	}
}