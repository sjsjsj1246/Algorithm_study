#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	bool Set[21] = { 0 };
	int m;
	cin >> m;
	FOR(i, 0, m)
	{
		string s;
		int n;
		cin >> s;
		if (s == "add")
		{
			cin >> n;
			Set[n] = 1;
		}
		if (s == "remove")
		{
			cin >> n;
			Set[n] = 0;
		}
		if (s == "check") 
		{
			cin >> n;
			cout << Set[n] << "\n";
		}
		if (s == "toggle") 
		{
			cin >> n;
			Set[n] ^= 1;
		}
		if (s == "all")
		{
			for (int i = 1; i <= 20; i++) Set[i] = 1;
		}
		if (s == "empty")
		{
			for (int i = 1; i <= 20; i++) Set[i] = 0;
		}
		
	}
}