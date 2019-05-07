#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000
#define INF 987654321
typedef long long ll;
using namespace std;

int dp[5001] = { 1, 0, };

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	if (s[0] > '0') dp[1] = 1;
	for (int i = 2; i <= len; i++)
	{
		if (s[i - 1] > '0')
			dp[i] = dp[i - 1];
		int temp = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
		if (temp >= 10 && temp <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
	}
	cout << dp[len];
}