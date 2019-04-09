#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

bool la, ta, n, t;

int main()
{
	int ans = 0;
	int temp;
	string s;
	cin >> temp >> s;

	for (char c : s)
	{
		if (c >= 'a'&& c <= 'z') la = 1;
		else if (c >= 'A'&& c <= 'Z') ta = 1;
		else if (c >= '0'&& c <= '9') n = 1;
		else t = 1;
	}

	ans = !la + !ta + !n + !t;
	if (s.length() + ans < 6) ans += 6 - (ans + s.length());
	cout << ans;
}