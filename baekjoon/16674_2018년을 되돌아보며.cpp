#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;

int main()
{
	fast;
	int a[4] = { 0 };
	int n;
	bool flag = 1;
	cin >> n;
	while (n != 0)
	{
		if (n % 10 == 2) a[0]++;
		else if (n % 10 == 0) a[1]++;
		else if (n % 10 == 1) a[2]++;
		else if (n % 10 == 8) a[3]++;
		else flag = 0;
		n /= 10;
	}
	if (flag == 0)
	{
		cout << 0;
		return 0;
	}
	if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3])
	{
		cout << 8;
		return 0;
	}
	else if (a[0] > 0 && a[1] > 0 && a[2] > 0 && a[3] > 0)
	{
		cout << 2;
		return 0;
	}
	else
	{
		cout << 1;
		return 0;
	}
}