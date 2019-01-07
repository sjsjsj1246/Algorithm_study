#include <stdio.h>
#include <math.h>

int main()
{
	int n, digit;
	long long int res = 0;
	scanf("%d", &n);
	digit = (int)log10(n);
	while (n)
	{
		res += (n - (int)pow(10, digit) + 1) * (digit+1);
		n = (int)pow(10, digit) - 1;
		digit--;
	}
	printf("%lld", res);
}