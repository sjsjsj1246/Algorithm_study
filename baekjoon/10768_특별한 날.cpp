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
	int m, d;
	cin >> m >> d;
	if (m < 2)
		cout << "Before" << '\n';
	else if (m == 2)
	{
		if (d == 18)
			cout << "Special" << '\n';
		else if (d < 18)
			cout << "Before" << '\n';
		else
			cout << "After" << '\n';
	}
	else
		cout << "After" << '\n';
}