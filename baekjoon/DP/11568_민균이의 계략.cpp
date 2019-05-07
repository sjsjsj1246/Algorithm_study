#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int dp[1001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j] && dp[i] >= dp[j])
			{
				dp[j]++;
			}
		}
	}

	cout << *max_element(dp, dp + 1001) + 1;
}