#include <iostream>
#include <algorithm>
using namespace std;

long long int dp[91] = { 0,1,1 }; 
//한자리 전의 수에 1을 떼고 10 붙이기 + 두자리 전의 수에 10 붙이기

int main()
{
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[n];
}