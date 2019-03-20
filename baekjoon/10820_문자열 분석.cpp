#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int a, A, n, s;

int main()
{
	char c;
	while ((c = getchar()) != EOF) 
	{
		if (c >= 'a' && c <= 'z') a++;
		else if (c >= 'A' && c <= 'Z') A++;
		else if (c >= '0' && c <= '9') n++;
		else if (c == ' ') s++;
		else if (c == '\n')
		{
			printf("%d %d %d %d\n", a, A, n, s);
			a = A = n = s = 0;
		}
	}
}