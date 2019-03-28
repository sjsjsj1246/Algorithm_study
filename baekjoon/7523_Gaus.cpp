#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;
typedef long long ll;

int main()
{
	int n; cin >> n;
	ll a, b;

	for (int i = 1; i <= n; i++) {
		cin >> a >> b;

		ll ta = a + 1, tb = b - 1;
		ll left, right;

		if (a <= 0 && b >= 0) {
			if (a % 2 == 0) left = ((a - 1) * ((abs(a)) / 2));
			else left = ((ta - 1) * ((abs(ta)) / 2)) + a;

			if (b % 2 == 0) right = ((b + 1) * ((abs(b)) / 2));
			else right = ((tb + 1) * ((abs(tb)) / 2)) + b;

			printf("Scenario #%d:\n%lld\n\n", i, right + left);
		}
		else if (a <= 0 && b <= 0)
		{
			if ((abs(a) + abs(b) + 1) % 2 == 0) left = (a + b) * ((abs(a - b - 1) / 2));
			else left = ((ta + b) * ((abs(ta - b - 1) / 2))) + a;

			printf("Scenario #%d:\n%lld\n\n", i, left);
		}
		else if (0 <= a && 0 <= b)
		{
			if ((abs(a) + abs(b) + 1) % 2 == 0) left = (a + b) * ((abs(b - a + 1) / 2));
			else left = ((a + tb) * ((abs(tb - a + 1) / 2))) + b;

			printf("Scenario #%d:\n%lld\n\n", i, left);
		}
	}

	return 0;
}