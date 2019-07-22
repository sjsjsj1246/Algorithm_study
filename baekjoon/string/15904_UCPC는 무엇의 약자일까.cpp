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
	string s;
	getline(cin, s);
	if (s.find("U") != string::npos)
	{
		s = s.substr(s.find("U") + 1, s.length());
		if (s.find("C") != string::npos)
		{
			s = s.substr(s.find("C") + 1, s.length());
			if (s.find("P") != string::npos)
			{
				s = s.substr(s.find("P") + 1, s.length());
				if (s.find("C") != string::npos)
				{
					cout << "I love UCPC";
					return 0;
				}
			}
		}
	}
	cout << "I hate UCPC";
}