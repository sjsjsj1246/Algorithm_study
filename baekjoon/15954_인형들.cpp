#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int n, k;
	long long arr[501], ps[501], sum = 0;
	long double minA = 2147483647; long long tempPrefix = 0;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) ps[i] = sum += arr[i];
	
	for (int x = 1; x <= n - k + 1; x++)
	{
		for (int i = k + x - 1; i <= n; i++)
		{
			long double count = i - x + 1;
			long double m{ (ps[i] - ps[x - 1]) / count }, A{};
			for (int j = x; j <= i; j++) A += (arr[j] - m) * (arr[j] - m);
			minA = min(minA, sqrt(A / count));
		}
	}

	cout << fixed; cout.precision(11);
	cout << minA;
}