#include <iostream>
#include <vector>
using namespace std;

int n;

bool findYPath(int pos, vector<vector<int>> &map, int h)
{
	int cnt = 0, dx = 0;
	while (dx<n-1)
	{
		if (map[pos][dx] > map[pos][dx+1]||
			map[pos][dx+1]- map[pos][dx]>1)

			dx++;
		cnt++;
	}
}

bool findXPath(int pos, vector<vector<int>> &map, int h)
{
}

int main()
{
	int h;
	cin >> n >> h;
	vector<vector<int>> map;
	for (int i = 0; i < n; i++)
	{
		vector<int> element(n, 0);
		map.push_back(element);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (findXPath)
			res++;
		if (findYPath)
			res++;
	}
	cout << res;
}