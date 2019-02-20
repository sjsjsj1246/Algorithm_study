#include<stdio.h>
int dp[1001] = {0,1,2};

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
	{
        //이 문제의 경우 처음 경우의 수를 적어가면서 패턴을 찾아냈음
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	printf("%d", dp[n]);
}