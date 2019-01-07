#include <iostream>
#include <string>
using namespace std;

char tree[65][65];

bool Check(int x, int y, int size)
{
	char temp = tree[y][x];
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			if (tree[j][i] != temp) return 0;
	return 1;
}

string quard(int x, int y, int size)
{
	if (Check(x, y, size))
	{
		if (tree[y][x] == '1') return "1";
		else return "0";
	}
	string one = quard(x, y, size / 2);
	string two = quard(x + size / 2, y, size / 2);
	string three = quard(x, y + size / 2, size / 2);
	string four = quard(x + size / 2, y + size / 2, size / 2);
	return "(" + one + two + three + four + ")";
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> tree[i];
	cout << quard(0, 0, n);
}