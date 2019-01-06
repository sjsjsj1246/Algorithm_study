#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int c; cin >> c;
	while (c--)
	{
		int L, v, l, r;
		cin >> L >> v >> l >> r;
		int res = L / v;
		if (l%v) l = (l / v + 1)*v;
		if (r%v) r = (r / v)*v;
		if (l == r) res--;
		else res -= (r - l) / v + 1;
		cout << res << "\n";
	}
	return 0;
}