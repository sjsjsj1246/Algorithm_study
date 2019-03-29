#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int fac[10] = { 1, 1 };
	for (int i = 2; i < 10; i++) fac[i] = i * fac[i - 1];
	cout << "n e\n- -----------\n";
	
	double e = 0;
	for (int i = 0; i < 10; i++)
	{
		e += 1 / (double)fac[i];
		if (i >= 3) cout << fixed, cout.precision(9);
		cout << i << " " << e << "\n";
	}
}