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
	int x, y;
	cin >> x >> y;
	if (x > 0 && y > 0) cout << 1;
	else if (x > 0 && y < 0) cout << 4;
	else if (x < 0 && y < 0) cout << 3;
	else if (x < 0 && y > 0) cout << 2;
}