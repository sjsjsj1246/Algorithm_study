#include<stdio.h>

int main(void)
{
	char day[7][4] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	int month[12]={ 31,28,31,30,31,30,31,31,30,31,30,31 };
	int x, y;

	scanf_s("%d %d", &x, &y);

	for (int i = 0; i < x - 1; i++)
	{
		y += month[i];
	}
	printf("%s", day[y % 7]);
	return 0;
}