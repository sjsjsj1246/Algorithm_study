#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;


int main()
{
	FAST;
	int n, k;
	cin >> n >> k;
	int m = pow(10, k);
	if (n % m >= 5 * m / 10) cout << (int)(n / m + 1) * m;
	else cout << (int)(n / m) * m;
}