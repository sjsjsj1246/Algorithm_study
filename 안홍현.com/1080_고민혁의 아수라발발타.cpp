#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int score(int a, int b)
{
	if (a == b) return a * 10 + 1;
	return (a + b) % 10 == 0 ? 10 : (a + b) % 10;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int cnt[10] = { 0, };
	cnt[n]++, cnt[m]++;
	int a = 0, b = 18*17;
	for (int i = 0; i < 20; i++)
	{
		for (int j = i + 1; j < 20; j++)
		{
			int x = i / 2 + 1;
			int y = j / 2 + 1;
			if (x == y && cnt[x] > 0) continue;
			else if (x != y && cnt[x] > 1) continue;

			if (score(n, x) < score(m, y)) a++;
		}
	}

	if (a == 0) printf("-1");
	else printf("%d %d", a / gcd(a, b), b / gcd(a, b));
}