#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m,l;
	cin >> n >> m >> l;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end(),greater<int>());

	int sum = 0;
	int i;
	for (i = 0; sum < m*l; i++)
	{
		if (i == n)
		{
			cout << "STRESS";
			return 0;
		}
		sum += arr[i];
	}
	cout << i;
}