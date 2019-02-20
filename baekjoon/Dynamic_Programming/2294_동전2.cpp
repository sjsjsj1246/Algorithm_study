#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int intMax = 987654321;
int n, k;
int dp[10001], money[101];

int memo(int sum)
{
	int &res = dp[sum];
	if (res != -1) return res;

	res = intMax;
	for (int i = 0; i < n; i++)
	{
		if (sum - money[i] >= 0)
			res = min(res, memo(sum - money[i]) + 1);
	}

	return res;
}

int main()
{
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; i++) cin >> money[i];
	int res = memo(k);
	if (res != intMax) cout << res;
	else cout << -1;
}