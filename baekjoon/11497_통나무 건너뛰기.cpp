#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <functional>
using namespace std;

int solve(vector<int> &arr)
{
	sort(arr.begin(), arr.end());

	int r = 0, l = 0, cnt = 0;
	vector<int> temp(arr.size(), 0);
	int mid = arr.size() / 2;

	temp[mid] = arr.back();

	for (int i = arr.size() - 2; i >= 0; i--)
	{
		if (cnt % 2)
		{
			r++;
			temp[mid + r] = arr[i];
		}
		else
		{
			l++;
			temp[mid - l] = arr[i];
		}
		cnt++;
	}

	int Max = abs(temp.front() - temp.back());
	for (int i = 0; i < temp.size() - 1; i++)
	{
		Max = max(Max, abs(temp[i] - temp[i + 1]));
	}

	return Max;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << solve(arr) << "\n";
	}
}

//-----------------------------------------------
// 충격적인 코드;;

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int a[n];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		int ans = 0;
		for(int i=2; i<n; i++) {
			ans = max(ans, a[i] - a[i-2]);
		}
		cout << ans << '\n';
	}
}