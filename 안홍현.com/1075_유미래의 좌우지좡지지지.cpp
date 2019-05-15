#include <stdio.h>

int arr[1000001];

int main()
{
	int n, m, temp;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		arr[temp] = 1;
	}

	int c;
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		int t;
		scanf("%d", &t);
		for (int j = 0; j < t; j++)
		{
			int temp;
			scanf("%d", &temp);
			if (arr[temp])
			{
				printf("Past");
				return 0;
			}
		}
	}
	printf("Furture");
}