#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> arr = { a,b,c };
		sort(arr.begin(), arr.end());
		if (arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0])
			printf("Scenario #%d:\nyes\n\n", i);
		else
			printf("Scenario #%d:\nno\n\n", i);
	}
	return 0;
}