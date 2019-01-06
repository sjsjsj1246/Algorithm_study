#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long int LL;

void go(int x, int y, vector<LL> arr, vector<LL>& res, LL& sum)
{
	if (y - x == 1)
	{
		sum += arr[x] * arr[y];
		res.push_back(arr[x] + arr[y]);
	}
	else if (x == y) res.push_back(arr[x]);
	else
	{
		int b = (y - x + 1) / 2;
		go(x, x + b - 1, arr, res, sum);
		go(x + b, y, arr, res, sum);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	LL sum = 0;
	vector<LL> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<LL> res;
	while (arr.size() != 1)
	{
		go(0, arr.size() - 1, arr, res, sum);
		arr = res;
		res.clear();
	}
	cout << sum;
}