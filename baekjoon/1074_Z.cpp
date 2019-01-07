#include <iostream>
using namespace std;

int POW(int x, int y)
{
	int temp = x;
	if (y == 0) return 1;
	while (--y)
		x *= temp;
	return x;
}

int Z(int n, int r, int c)
{
	if (n == 1)
	{
		if (r == 0 && c == 0) return 0;
		if (r == 0 && c == 1) return 1;
		if (r == 1 && c == 0) return 2;
		if (r == 1 && c == 1) return 3;
	}
	int size = POW(2, n);
	if (r < size / 2 && c < size / 2)
		return Z(n - 1, r, c);
	if (r < size / 2 && c >= size / 2)
		return POW(4, n - 1) + Z(n - 1, r, c - size / 2);
	if (r >= size / 2 && c < size / 2)
		return 2*POW(4, n - 1) + Z(n - 1, r - size / 2, c);
	if (r >= size / 2 && c >= size / 2)
		return 3*POW(4, n - 1) + Z(n - 1, r - size / 2, c - size / 2);
}

int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	cout << Z(n, r, c);
}