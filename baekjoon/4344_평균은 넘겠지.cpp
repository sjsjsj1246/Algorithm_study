#include <stdio.h>

int H[9], x, y, sum = 0;
int check()
{
	for (int i = 0; i<8; i++)
	{
		int tmp = sum;
		tmp -= H[i];
		for (int j = i + 1; j<9; j++)
		{
			tmp -= H[j];
			if (tmp == 100)
			{
				x = i; y = j;
				return 0;
			}
			tmp += H[j];
		}
		tmp += H[i];
	}
}
int main()
{
	for (int i = 0; i<9; i++)
	{
		scanf("%d", &H[i]);
	}
	for (int i = 0; i<9; i++)
	{
		sum += H[i];
	}
	check();
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<6 - i; j++)
		{
			if (i != x&&i != y)
			{
				if (H[i]>H[i + 1])
				{
					int temp = H[i];
					H[i] = H[i + 1];
					H[i + 1] = temp;
				}
			}
		}
	}
	for(int i=0;i<9;i++)
	{
		if(i!=x&&i!=y)
		{
			printf("%d\n",H[i]);
		}
	}
}
