#include <stdio.h>

int prime[1001] = { 1,1 };

int main()
{
	for (int i = 2; i < 1001; i++)
	{
		if (prime[i]) continue;
		for (int j = 2; i*j < 1001; j++)
		{
			prime[i*j] = 1;
		}
	}

	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		
		int flag = 0;
		for (int i = 2; i <= n / 2; i++)
		{
			if (prime[i] == 0 && prime[n - i] == 0)
			{
				printf("%d %d\n", i, n - i);
				flag = 1;
				break;
			}
			if (flag) break;
		}
		if (flag == 0) printf("-1\n");
	}
}