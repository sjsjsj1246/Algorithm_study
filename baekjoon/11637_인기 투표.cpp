#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	FAST;
	int t;
	cin >> t;
	for (int cases = 1; cases <= t; cases++)
	{
		int n, sum = 0;
		cin >> n;
		vector<pair<int,int>> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i].first, arr[i].second = i + 1, sum += arr[i].first;
		sort(arr.begin(), arr.end());
		if (arr[n-1].first == arr[n-2].first) cout << "no winner\n";
		else if (arr.back().first > sum / 2) cout << "majority winner " << arr.back().second << "\n";
		else cout << "minority winner " << arr.back().second << "\n";
	}
	return 0;
}