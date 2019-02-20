#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> dp(16, -1);

int memo(vector<pair<int,int>> arr, int cnt)
{
	if (cnt >= n) return 0;
	int &ret = dp[cnt];
	if (ret != -1) return ret;
	ret = arr[cnt].second;
	if (cnt + arr[cnt].first > n) ret = 0;
	return ret = max(memo(arr, cnt + arr[cnt].first) + ret , memo(arr, cnt + 1));
}

int main()
{
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	cout << memo(arr, 0);
}