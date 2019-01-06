#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	long long int dp[68] = { 1,1,2,4 };
	for (int i = 4; i < 68; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		cout << dp[temp] << '\n';
	}
}