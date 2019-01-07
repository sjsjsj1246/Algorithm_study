#include <stdio.h>

int main()
{
	int N, X, Mat[10001]={0,};
	scanf("%d %d",&N,&X);
	for(int i=0; i<N; i++)
	{
		scanf("%d",&Mat[i]);
		if(Mat[i]>0&&Mat[i]<X)printf("%d ",Mat[i]);
	}
}
