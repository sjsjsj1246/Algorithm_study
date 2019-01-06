#include <stdio.h>

int main()
{
	int count=0, n;
	scanf("%d",&n);
	int temp=n;
	while(1)
	{
		count++;
		if(n<10)n=n*10+n;
		else n=(n%10)*10+(n/10+n%10)%10;
		if(n==temp)break;
	}
	printf("%d",count);
}
