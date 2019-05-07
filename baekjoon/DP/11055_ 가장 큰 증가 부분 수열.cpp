#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001], num[1001];

int n;

int Lis(int start) {
	if (start >= n)
		return 0;
	int& res = dp[start];
	if (res != -1)
		return res;
	else {
		res = num[start];
		for (int i = start + 1; i < n; ++i) {
			if (num[start] < num[i])
				res = max(res, num[start] + Lis(i));
		}
		return res;
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, Lis(i));
	}
	cout << res;
}