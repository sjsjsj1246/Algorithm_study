#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	cout << arr.front()*arr.back();
	return 0;
}