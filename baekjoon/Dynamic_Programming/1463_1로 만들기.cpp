//dottom-up
#include <stdio.h>

int main()
{
	int dp[1000001];
	int n;
	scanf("%d", &n);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i <= n; i++)
	{
		if (i % 3 == 0 && i % 2 == 0)
			dp[i] = 1 + min(dp[i / 3], dp[i / 2]);
		else if (i % 3 == 0)
			dp[i] = 1 + min(dp[i - 1], dp[i / 3]);
		else if (i % 2 == 0)
			dp[i] = 1 + min(dp[i - 1], dp[i / 2]);
		else
			dp[i] = 1 + dp[i - 1];
	}
	printf("%d", dp[n]);
}

//-------------------------------------------------------------------------
//non-dp(메모이제이션이 없음) 재귀로 품
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n)
{
	if (n <= 1)
		return 0;
	int x = solve(n / 3) + n % 3 + 1;
	int y = solve(n / 2) + n % 2 + 1;
	return min(x, y);
}
int main()
{
	int N;
	scanf("%d", &N);

	printf("%d", solve(N));
	return 0;
}