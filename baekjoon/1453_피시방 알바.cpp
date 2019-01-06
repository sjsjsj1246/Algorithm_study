#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	int res = 0;
	vector<bool> arr(n,0);
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp; temp--;
		if (arr[temp]) res++;
		else arr[temp] = 1;
	}
	cout << res;
}