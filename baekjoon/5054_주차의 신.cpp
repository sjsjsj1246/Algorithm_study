#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

int dis(int x, int y) { return x > y ? x - y : y - x; }
	

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int c; cin >> c;
	while (c--)
	{
		int n; cin >> n;
		int sum = 0;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr.begin(), arr.end());
		for (int i = 0; i < n - 1; i++) sum += dis(arr[i], arr[i + 1]);
		sum += dis(arr[0], arr[n - 1]);
		cout << sum << "\n";
	}
}