#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

bool cmp(const string& a, const string& b)
{
	if (a.length() < b.length()) return 1;
	if (a.length() == b.length() && a < b) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<string> arr(n);
	string temp;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end(),cmp);
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && arr[i] == arr[i - 1]) continue;
		cout << arr[i] << "\n";
	}
}