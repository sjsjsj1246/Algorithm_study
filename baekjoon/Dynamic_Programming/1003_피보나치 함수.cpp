#include<stdio.h>

int main()
{
	int N;
	int Zero[41];
	int One[41];
	int Rst[41];
	Zero[0]=1;
	Zero[1]=0;
	One[0]=0;
	One[1]=1;
	for (int i=0; i<41; i++)
	{
		Zero[i+2]=Zero[i+1] + Zero[i];
		One[i+2]=One[i+1] + One[i];
	}
	scanf("%d",&N);
	for (int i=0; i<N; i++)
	{
		scanf("%d",&Rst[i]);
	}
	for (int i=0; i<N; i++)
	{
		printf("%d %d\n",Zero[Rst[i]],One[Rst[i]]);
	}
}
