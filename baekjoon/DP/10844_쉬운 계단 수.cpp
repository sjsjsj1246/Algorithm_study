#include <iostream>
#include <cstring>
#define mod 1000000000
using namespace std;
typedef long long int LL;
LL dp[101][10];

LL memo(int count, int num)
{
	if (num < 0 || num>9) return 0LL;
	if (count == 1 && num != 0) return 1LL;
	if (dp[count][num] != -1LL) return dp[count][num];
	return dp[count][num] = (memo(count - 1, num - 1) % mod + memo(count - 1, num + 1) % mod) % mod;
}

int main()
{
	int n; cin >> n;
	LL sum = 0;
	memset(dp, -1LL, sizeof(dp));
	for (int i = 0; i < 10; i++)
		sum += memo(n , i)%mod;
	cout << sum%mod;
}