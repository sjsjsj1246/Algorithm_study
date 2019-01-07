#include <iostream>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		int res = 2 * b - a;
		printf("%d %d\n", res, b - res);
	}
}