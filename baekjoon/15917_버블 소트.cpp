#include <stdio.h>

int main()
{
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		long long int a; scanf("%lld", &a);
		if ((a&(-a)) == a) printf("%d\n", 1);
		else printf("%d\n", 0);
	}
}