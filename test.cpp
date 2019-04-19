#include <stdio.h>
#include <string.h>
int main()
{
	char str[101];
	int len;
	scanf("%s", str);

	len = strlen(str);
	for (int i = 0; i <= len; i += 10)
	{
		for (int j = i; j < i + 10; j++)
		{
			if (str[j] == '\0')
				return 0;
			printf("%c", str[j]);
		}
		printf("\n");
	}
}a


