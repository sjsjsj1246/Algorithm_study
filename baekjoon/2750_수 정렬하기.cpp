#include<stdio.h>
int main()
{
	char A[100]={'*',};
	int i=0;
	scanf("%s",A);
	while(A[i]!='*')
	{
		printf("%c",(int)A[i]+1);
		i++;
	}
	return 0;
}
