#include <stdio.h>

int main()
{
	long long int n;
	scanf("%lld", &n);
	printf("%s", n % 7 & 5 ? "SK" : "CY");
}