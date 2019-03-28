#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	FAST;
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (arr[1] - arr[0] == arr[2] - arr[1]) cout << arr.back() + arr[1] - arr[0];
	else cout << arr.back() / arr[0] * arr[1];
}