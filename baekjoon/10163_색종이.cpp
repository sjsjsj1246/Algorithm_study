#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int map[102][102];

int main()
{
	ios::sync_with_stdio(false);
	memset(map, -1, sizeof(map));
	int n; cin >> n;
	vector<int> res(n);
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int x = a; x < a + c; x++)
		{
			for (int y = b; y < b + d; y++)
			{
				map[x][y] = i;
			}
		}
	}
	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++)
		{
			if (map[i][j] != -1)
				res[map[i][j]]++;
		}
	}
	for(auto i :res) cout << i << "\n";
}