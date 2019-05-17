#include <stdio.h>

int day[13] = { 0,31,28,31,31,31,31,31,31,31,31,31,31 };

int main()
{
	int y, m, d, t;
	scanf("%d%d%d%d", &y, &m, &d, &t);
	
	d += t;
	while (d > day[m])
	{
		d -= day[m], m++;
		if (m > 12) y++, m -= 12;
	}
	
	printf("%d %02d %02d", y, m, d);
}