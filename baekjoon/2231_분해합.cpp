#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define INF 987654321
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;

int getSum(int n)
{
	int sum = n;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	fast;
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (getSum(i) == n)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
}