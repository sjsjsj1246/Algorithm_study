#include <stdio.h>

int main()
{
	int n;
	int arr[10001] = { 0, };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]), arr[i] += arr[i - 1];
	
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", arr[b] - arr[a - 1]);
	}
}