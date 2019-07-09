#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int n;

int main()
{
	FAST;
	int year;
	cin >> year;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		cout << 1;
	}
	else
		cout << 0;
}