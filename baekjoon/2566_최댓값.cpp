#include <iostream>
using namespace std;

int main()
{
	int map[9][9], max = 0;;
	int posx, posy;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (max < map[i][j])
			{
				posx = i+1;
				posy = j+1;
				max = map[i][j];
			}
		}
	}
	printf("%d\n%d %d", max, posx, posy);
}