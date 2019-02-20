#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int map[1000][1000];

int main()
{
	int n, m;
	int Max = 0;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
			map[i][j] = s[j] - '0';
	}
	for (int y = n - 2; y >= 0; y--)
	{
		for (int x = m - 2; x >= 0; x--)
		{
			if (map[y][x])
				map[y][x] = min({ map[y + 1][x], map[y][x + 1], map[y + 1][x + 1]}) + 1;
			//각 칸이 정사각형의 크기
			//1,2,3칸이 모두 1이면 2*2정사각형이 만들어진 것 
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (Max < map[i][j]) Max = map[i][j];
	}
	cout << Max * Max;
}