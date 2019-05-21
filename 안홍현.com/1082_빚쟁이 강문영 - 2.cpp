#include <stdio.h>
#include <string.h>

int main()
{
	char s[100001], ans[100001] = "";
	scanf("%s", s);

	int len = strlen(s);
	int ans_len = 0;
	int flag = 1;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '4')
		{
			s[i] = '3';
			ans[ans_len] = '1';
			ans_len++;
			flag = 0;
		}
		else if (ans_len != 0)
		{
			ans[ans_len] = '0';
			ans_len++;
		}
	}
	if (flag) printf("%s 0", s);
	else 
	{
		ans[ans_len] = '\0';
		printf("%s %s", s, ans);
	}
}