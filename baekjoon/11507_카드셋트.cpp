#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int cnt[4];
bool chk[4][14];
int main() {
	char c;
	int x, y;
	while (scanf("%c%1d%1d", &c, &x, &y) != EOF)
	{
		x = x * 10 + y;
		if (c == 'P')c = 0;
		else if (c == 'K')c = 1;
		else if (c == 'H')c = 2;
		else if (c == 'T')c = 3;
		if (chk[c][x])
		{
			puts("GRESKA");
			return 0;
		}
		chk[c][x] = 1, cnt[c]++;
	}
	for (int i = 0; i < 4; i++)
		printf("%d ", 13 - cnt[i]);
}