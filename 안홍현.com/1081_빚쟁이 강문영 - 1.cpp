#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	scanf("%d", &n);
	int ans = 0;
	int a[7] = { 0, }, b[7] = { 0, };
	int cnt = 0;
	while (n > 0)
	{
		if (n % 10 == 4)
		{
			a[cnt] = 3;
			b[cnt] = 1;
		}
		else
		{
			a[cnt] = n % 10;
			b[cnt] = 0;
		}
		cnt++;
		n /= 10;
	}
	for (int i = cnt-1; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
	printf(" ");

	int flag = 0;
	for (int i = cnt - 1; i >= 0; i--)
	{
		if (b[i]) flag = 1;
		if (flag) printf("%d", b[i]);
	}

	if (!flag) printf("0");
}