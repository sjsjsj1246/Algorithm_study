#include <stdio.h>
#include <string.h>

int main()
{
	char s[100001], ans[100001] = "";
	scanf("%s", s);

	int len = strlen(s);
	int ans_len = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '4')
		{
			s[i] = '3';
			ans[ans_len] = '1';
			ans_len++;
		}
		else if (ans_len != 0)
		{
			ans[ans_len] = '0';
			ans_len++;
		}
	}
	ans[ans_len] = '\0';
	printf("%s %s", s, ans);
}