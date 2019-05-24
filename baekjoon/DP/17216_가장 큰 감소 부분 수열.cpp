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
	int n;
	cin >> n;
	vector<int> arr(n), dp(n);
	FOR(i, 0, n) cin >> arr[i], dp[i] = arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[j] = max(dp[j], dp[i] + arr[j]);
			}
		}
	}
	
	cout << *max_element(ALL(dp));
}