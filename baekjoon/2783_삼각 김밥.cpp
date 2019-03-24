#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int a;
	double b;
	cin >> a >> b;
	double Min = a / b * 1000;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		Min = min(Min, a / b * 1000);
	}
	cout << Min;
}