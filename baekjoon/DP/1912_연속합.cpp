#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int LL;
using namespace std;

LL dp[100000];

int main()
{
	int n; cin >> n;
	vector<LL> list(n);
	for (int i = 0; i < n; i++)
		cin >> list[i];
	LL result = dp[0] = list[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i - 1] + list[i], list[i]);
		if (result < dp[i]) result = dp[i];
	}
	cout << result;
}