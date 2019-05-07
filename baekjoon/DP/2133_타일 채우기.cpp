#include<iostream>
using namespace std;

long long int dp[31];

int main()
{
	dp[0] = 1; dp[2] = 3;
	int n; cin >> n;
	if (n % 2) cout << 0;
	else
	{
		for (int i = 4; i <= n; i += 2) 
		{
			dp[i] = 3 * dp[i - 2];
			for (int j = 4; j <= i; j += 2) 
			{
				dp[i] += 2 * dp[i - j];
			}
		}
		cout << dp[n];
	}
}