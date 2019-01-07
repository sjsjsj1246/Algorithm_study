#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	long long int sum = 0;
	int cnt = 0;
	cin >> n >> k;
	vector<pair<int,bool>> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i].first;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < k; i++) arr[i].second = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < cnt; j++) sum += arr[i].first;
		if (arr[i].second) cnt++;
	}
	cout << sum;
	return 0;
}