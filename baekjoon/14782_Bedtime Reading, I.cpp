#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0) ans += i;
	}
	cout << ans;
}