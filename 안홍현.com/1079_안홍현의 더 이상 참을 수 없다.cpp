#include <stdio.h>

int arr[101][101];

int main()
{
	int n;
	scanf("%d%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int p;
	scanf("%d", &p);
	p = p * 2 - 1;

	int ans = 0;
	for (int i = 0; i < n - p + 1; i++)
	{
		for (int j = 0; j < n - p + 1; j++)
		{
			int cnt = 0;
			for (int x = i; x < i + p; x++)
			{
				for (int y = j; y < j + p; y++)
				{
					if (arr[x][y]) cnt++;
				}
			}
			if (ans < cnt) ans = cnt;
		}
	}
	printf("%d", ans);
}