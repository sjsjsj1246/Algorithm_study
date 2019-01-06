#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int ret = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + arr[i] > t) break;
		sum += arr[i];
		ret++;
	}
	cout << ret;
}