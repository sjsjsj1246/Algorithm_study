#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
#include <algorithm>
#define MOD 1000000000
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int greedy(int n, int m) { return min(n / 2, m); }

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int ans = 0;
	if (k == 0) ans = greedy(n, m);
	for (int i = 0; i < k; i++)
	{
		ans = max(ans, max(greedy(n - i, m - (k - i)), greedy(n - (k - i), m - i)));
	}
	cout << ans;
}