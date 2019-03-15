#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end(), greater<int>());
	int Max = 0;
	Max = max({ arr[0] * arr[1] * arr[2],
		arr[0] * arr[1],
		arr[0] * arr[n - 1] * arr[n - 2],
		arr[n - 1] * arr[n - 2]
		});
	cout << Max;
}