#include <iostream>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int a = 0, b = 0;
		int n; cin >> n;
		getchar();
		while (n--)
		{
			char x, y;
			x = getchar();
			getchar();
			y = getchar();
			getchar();
			if (x == 'R')
			{
				if (y == 'R');
				if (y == 'S') a++;
				if (y == 'P') b++;
			}
			if (x == 'S')
			{
				if (y == 'R') b++;
				if (y == 'S');
				if (y == 'P') a++;
			}
			if (x == 'P')
			{
				if (y == 'R') a++;
				if (y == 'S') b++;
				if (y == 'P');
			}
		}
		if (a < b) printf("Player 2\n");
		else if (a > b) printf("Player 1\n");
		else printf("TIE\n");
	}
}