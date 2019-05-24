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
	string s;
	cin >> s;
	string l = s.substr(0, s.find("("));
	string r = s.substr(s.find(")"), s.length());

	int l_cnt = 0;
	while (l.find("@") != string::npos)
	{
		l_cnt++;
		l = l.substr(l.find("@") + 1, l.length());
	}

	int r_cnt = 0;
	while (r.find("@") != string::npos)
	{
		r_cnt++;
		r = r.substr(r.find("@") + 1, r.length());
	}

	cout << l_cnt << " " << r_cnt;
}