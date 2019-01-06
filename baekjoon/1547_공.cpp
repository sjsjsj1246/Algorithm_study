#include <iostream>
using namespace std;

int main()
{
	int m; cin >> m;
	int pos = 1;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		if (a == pos) pos = b;
		else if (b == pos) pos = a;
	}
	cout << pos;
}