#include <stdio.h>

char armor[4][3][4] =
{
	{
		"111",
		"101",
		"000"
	},
	{
		"101",
		"111",
		"111"
	},
	{
		"111",
		"101",
		"101"
	},
	{
		"000",
		"101",
		"101"
	}
};

int main()
{
	int a, n;
	scanf("%d%d", &a, &n);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < n; l++)
				{
					printf("%c", armor[a][i][k]);
				}
			}
			printf("\n");
		}
	}
}