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
	LL c, k, p;
	LL sum = 0;
	cin >> c >> k >> p;
	for (int i = 0; i <= c; i++)
	{
		sum += k * i + p * i*i;
	}
	cout << sum;
}