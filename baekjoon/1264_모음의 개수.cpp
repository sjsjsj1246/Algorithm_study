#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

char aeiou[] = "aeiouAEIOU";

int main()
{
	char S[256];
	scanf(" %[^\n]", S);

	while (S[0] != '#')
	{
		int len = strlen(S);
		int cnt = 0;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (S[i] == aeiou[j]) cnt++;
			}
		}
		printf("%d\n", cnt);
		scanf(" %[^\n]", S);
	}
}