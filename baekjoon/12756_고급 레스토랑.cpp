#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	int c, d;
	cin >> a >> b >> c >> d;
	while (1)
	{
		b -= c;
		d -= a;
		if (b <= 0 && d <= 0) { cout << "DRAW"; break; }
		else if (b <= 0) { cout << "PLAYER B"; break; }
		else if (d <= 0) { cout << "PLAYER A"; break; }
	}
}