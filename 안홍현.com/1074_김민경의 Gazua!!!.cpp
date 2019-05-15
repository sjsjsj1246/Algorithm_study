#include <stdio.h>

int main()
{
	int arr[1000];
	int n, money;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	scanf("%d", &money);

	long long int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int money2 = money / arr[i] * arr[j];
			if (ans < money2) ans = money2;
		}
	}

	printf("%d", ans);
}