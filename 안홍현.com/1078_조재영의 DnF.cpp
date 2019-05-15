#include <stdio.h>

int main()
{
	int h, n, c, k, q;
	scanf("%d%d%d%d%d", &h, &n, &c, &k, &q);
	int t = n / h;

	int ans = 0;
	while (t > 0 && c >= k)
	{
		t--;
		ans++;
		c -= k;
		c += q;
	}
	printf("%d", ans);
}