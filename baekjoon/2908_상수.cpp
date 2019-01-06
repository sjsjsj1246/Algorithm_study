#include <stdio.h>
int main()
{
	int n1,n2,A[1001];
	scanf("%d",&n1);
	for(int i=0;i<n1;i++)
	{
		scanf("%d",&n2);
		int sum=0,count=0;
		for(int j=0;j<n2;j++)
		{
			scanf("%d",&A[j]);
			sum+=A[j];
		}
		double avg=sum/n2;
		for(int j=0;j<n2;j++)
		{
			count+=(double)A[j]>avg?1:0;
		}
		printf("%.3lf%%\n",(double)count/n2*100);
	}
}
