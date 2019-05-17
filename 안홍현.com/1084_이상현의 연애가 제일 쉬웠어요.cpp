#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char s[1001];
	scanf("%d%s", &n, s);

	int len = strlen(s);
	for (int i = 0; i < len; i++) s[i] = (s[i] == 'R' ? 'D' : 'R');
	printf("%s", s);
}