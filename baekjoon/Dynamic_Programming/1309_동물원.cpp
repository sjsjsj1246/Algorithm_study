#include <iostream>
using namespace std;

int main()
{
	int n; 
	cin >> n;
	int dp[100001] = { 0,3,7, };
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1] * 2) % 9901;
	}
	cout << dp[n];
}

/*
dp[n-2] 만큼 모두 빈공간이 생기고 그다음 경우는 3가지 가능 -> dp[n-2]*3
dp[n-1]-dp[n-2] 만큼 적어도 하나가 차있는 경우가 생김 그다음 경우는 2가지 가능 -> (dp[n-1]-dp[n-2])*2
따라서 dp[n] = dp[n-2]*3 + (dp[n-1]-dp[n-2])*2
dp[n] = dp[n-2] + dp[n-1]*2
*/