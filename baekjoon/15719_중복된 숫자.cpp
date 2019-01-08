#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;



int main()
{
	fast;
	LL n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
	}
	cout << sum - n*(n-1)/2LL;
}