#include <stdio.h>
#include <math.h>

int prime(int n)
{
	int len = sqrt(n);
	int ret = 1;
	for (int i = 2; i <= len; i++)
	{
		if (n % i == 0)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (prime(n))
		{
			printf("2\n");
			continue;
		}

		int len = sqrt(n);
		int flag = 1;
		for (int i = 2; i <= len; i++)
		{
			if (n % i == 0)
			{
				if (!prime(i) || !prime(n / i))
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag) printf("1\n");
		else printf("0\n");
	}
}