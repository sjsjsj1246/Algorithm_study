#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int fi[1000001] = { 0,1 };

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	if (n > 0) cout << "1\n";
	else if (n == 0) cout << "0\n";
	else if (n < 0)
	{
		if (n % 2) cout << "1\n";
		else cout << "-1\n";
	}

	n = abs(n);
	for (int i = 2; i <= n; i++) fi[i] = (fi[i - 1] % MOD + fi[i - 2] % MOD) % MOD;

	cout << fi[n];
}