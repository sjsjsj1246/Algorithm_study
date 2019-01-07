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
	LL n;
	cin >> n;
	int res = 1;
	int cnt = 11;
	while (n >= cnt)
	{
		res++;
		cnt = cnt * 10 + 1;
	}
	cout << res;
}