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
	int n;
	cin >> n;
	string s;
	map<string, int> m;
	FOR(i, 0, n) cin >> s, m[s]++;
	for (auto x : m)
	{
		if (x.second == 0) continue;
		string temp = x.first;
		reverse(ALL(temp));
		if (m[temp])
		{
			cout << temp.length() << " " << temp[temp.length() / 2];
			return 0;
		}
	}
}