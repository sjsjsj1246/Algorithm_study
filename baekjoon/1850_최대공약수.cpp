#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int gcd(ll a, ll b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	ll a, b;
	cin >> a >> b;
	int ans = gcd(a, b);
	for (int i = 0; i < ans; i++) cout << "1";
}