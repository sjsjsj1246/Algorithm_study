#include <stdio.h>
#include <stdlib.h>
int main()
{
	// �Է� ����
	int n;
	scanf("%d", &n);
	int *Mat1;
	int *Mat2;
    //���� �Ҵ�
	Mat1 = (int*)malloc(sizeof(int)*n);
	Mat2 = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&Mat1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &Mat2[i]);
	}
	// �Է� ����
    
	int count = 0;
	for (int i = 0; i < n-1; i++)
	{
		int temp = Mat2[i] - Mat2[i + 1];
		if ((temp ==1 || temp==-1) != 1)
		{
			count++;
		}
		if (count > 1)
		{
			printf("bad puzzle");
			return 0;
		}
	}
	printf("good puzzle");
	return 0;
}
