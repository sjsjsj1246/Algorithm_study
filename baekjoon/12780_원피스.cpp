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
	FAST;
	string s, k;
	cin >> s >> k;

	int cnt = 0;
	while (s.find(k) != string::npos)
	{
		cnt++;
		s = s.substr(s.find(k) + k.length(), s.length());
	}
	cout << cnt;

}