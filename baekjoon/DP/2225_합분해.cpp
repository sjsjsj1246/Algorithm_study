#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
#define MOD 1000000000
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;

/*
2225 합분해
dp, top-down
dp[n][k] = k개의 합으로 n을 만드는 경우의수 저장
memo(int n, int k) return dp[n][k]
for i:n > n-i, k-1 
*/

int dp[201][201];

int memo(int n, int k)
{
	int &ret = dp[n][k];
	if (k == 1) return ret = 1;
	if (n == 0) return ret = 1;
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= n; i++)
	{
		ret += memo(n - i, k - 1);
		ret %= MOD;
	}
	return ret % MOD;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	int n, k;
	cin >> n >> k;
	cout << memo(n, k);
}