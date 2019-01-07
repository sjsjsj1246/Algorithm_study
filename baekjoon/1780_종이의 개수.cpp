#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;

int map[2187][2187];
int n, a = 0, b = 0, c = 0;

bool check(pair<int,int> start, pair<int,int> end)
{ 
	for (int i = start.first; i < end.first; i++)
	{
		for (int j = start.second; j < end.second; j++)
		{
			if (map[start.first][start.second] != map[i][j]) return 0;
		}
	}
	return 1;
}

void DQ(pair<int, int> start, pair<int, int> end)
{
	if (check(start, end))
	{
		switch (map[start.first][start.second])
		{
		case -1: a++;
			break;
		case 0: b++;
			break;
		case 1: c++;
			break;
		default:
			break;
		}
	}
	else
	{
		for (int i = start.first; i < end.first; i += (end.first - start.first) / 3) 
		{
			for (int j = start.second; j < end.second; j += (end.second - start.second) / 3)
			{
				DQ({ i, j }, { i + (end.first - start.first) / 3,j + (end.second - start.second) / 3 });
			}
		}
	}
}

int main()
{
	fast;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	DQ({ 0,0 }, { n,n });
	cout << a << "\n" << b << "\n" << c;
}