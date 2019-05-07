#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (1)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) return 0;
		cout << min({ 30 * a + 40 * b,35 * a + 30 * b, 40 * a + 20 * b }) << "\n";
	}

}