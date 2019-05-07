#include <iostream>
#include <algorithm>
using namespace std;

int d[10001], a[10001];

int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	d[0] = 0; d[1] = a[1];	d[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++)
	{
		d[i] = max({ d[i - 1], d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i] });
	}

	cout << d[n];
}