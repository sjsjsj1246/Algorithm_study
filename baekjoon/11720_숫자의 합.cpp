#include<stdio.h>
int main()
{
	int n, r=0;
	char a[100];
	scanf("%d",&n);
	scanf("%s",a);
	for (int i=0;i<n;i++)
	{
		r+=(int)a[i]-48;
	}
	printf("%d",r);
}
