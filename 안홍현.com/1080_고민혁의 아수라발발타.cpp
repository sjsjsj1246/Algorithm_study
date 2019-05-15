#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int a = 0, b = 0;
	for (int i = 1; i <= 20; i++)
	{
	}
	printf("경우의 수 = %d\n", b);

	printf("%d %d", a/gcd(a,b), b/gcd(a,b));
}