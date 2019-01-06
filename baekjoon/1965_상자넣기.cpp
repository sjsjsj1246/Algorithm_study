#include<stdio.h>
int main(void)
{
	int n, i, j, max = 0;
	scanf("%d", &n);
	int a[1001], sum[1001];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = 1;
	}
	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
			if (a[i] > a[j])
				if (sum[i] < sum[j] + 1)
					sum[i] = sum[j] + 1;
	for (i = 0; i < n; i++)
		if (max < sum[i]) max = sum[i];
	printf("%d", max);
	return 0;
}
