#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <queue>
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int LL;
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r1, r2, l1, l2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (l1 <= r2)
		{
			if (l1 != r2)
				cout << l1 << " " << r2 << "\n";
			else
				cout << l1 << " " << l2 << "\n";
		}
		else if (l1 > r2)
		{
			cout << r1 << " " << l2 << "\n";
		}
	}
}