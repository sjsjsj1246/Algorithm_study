#include<stdio.h>
int main()
{
	int n, A[1000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-1;j++)
        {
            int temp;
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
	for (int i=0;i<n;i++)
	{
		printf("%d\n",A[i]);
	}
}
