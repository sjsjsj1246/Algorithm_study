#include <stdio.h>

int main()
{
	int n, arr[1000000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int p;
	scanf("%d", &p);
	
	int ans = 0;
	for (int i = 0; i < n; i++) if (arr[i] > p) ans++;
	printf("%d", ans);
}