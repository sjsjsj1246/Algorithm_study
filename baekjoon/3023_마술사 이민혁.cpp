#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

char arr[101][101];

int main()
{
	FAST;
	int r, c, a, b;
	cin >> r >> c;
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
		}
	}
	cin >> a >> b;
	a--, b--;
	for (int i = 0; i < r; i++)
	{
		for (int j = c; j < 2 * c; j++)
		{
			arr[i][j] = arr[i][2 * c - j - 1];
		}
	}
	for (int i = r; i < 2 * r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = arr[2 * r - i - 1][j];
		}
	}
	for (int i = r; i < 2 * r; i++)
	{
		for (int j = c; j < 2 * c; j++)
		{
			arr[i][j] = arr[2 * r - i - 1][2 * c - j - 1];
		}
	}
	if (arr[a][b] == '#') arr[a][b] = '.';
	else arr[a][b] = '#';
	for (int i = 0; i < 2*r; i++)
	{
		for (int j = 0; j < 2*c; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
}