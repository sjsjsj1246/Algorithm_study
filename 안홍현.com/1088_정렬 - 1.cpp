#include <stdio.h>

int main()
{
	int arr[3000001] = { 0, };
	int n, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &temp), arr[temp]++;
	for (int i = 0; i < 3000001; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			printf("%d\n", i);
		}
	}
}