#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

int main()
{ 
	char S[201];
	scanf("%[^\n]", S);
	while (S[0] != '*')
	{
		vector<bool> check(26, 0);
		bool flag = 1;
		int len = strlen(S);
		for (int i = 0; i < len; i++)
			if (S[i] != ' ')
				check[S[i] - 'a'] = 1;
		for (int i = 0; i < 26; i++)
			if (check[i] == 0) flag = 0;
		if (flag) puts("Y");
		else puts("N");
		scanf(" %[^\n]", S);
	}
}