#include <stdio.h>
typedef long long ll;

typedef struct point
{
	int x, y;
}point;

int main()
{
	point arr[6];
	for (int i = 0; i < 6; i++) scanf("%d%d", &arr[i].x, &arr[i].y);

	ll ans = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			for (int k = j + 1; k < 6; k++)
			{
				point a = arr[i];
				point b = arr[j];
				point c = arr[k];
				ll area = (a.y - b.y)*(c.x - b.x) - (a.x - b.x)*(c.y - b.y);
				area /= 2;
				if (ans < area) ans = area;
			}
		}
	}

	printf("%lld", ans);
}