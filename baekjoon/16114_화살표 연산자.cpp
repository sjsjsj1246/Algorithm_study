#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
-5 0 0
10 4 4
3 0 i
-5 1 i
10 1 0
10 3 e

*/
int main()
{
	int x, n, cnt = 0;
	cin >> x >> n;
	if (n == 1)
	{
		if (x < 0)
		{
			cout << "INFINITE";
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	if (n%2)
	{
		cout << "ERROR";
		return 0;
	}
	if (n == 0 && x > 0)
	{
		cout << "INFINITE";
		return 0;
	}
	n /= 2; x -= n;
	while (x>0)
	{
		x -= n;
		cnt++;
	}
	cout << cnt;
	return 0;
}