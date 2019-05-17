#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (gcd(n, m) == 1) printf("0");
	else printf("1");
}