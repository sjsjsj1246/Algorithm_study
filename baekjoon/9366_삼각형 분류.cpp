#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	int t;
	cin >> t;
	for (int cases = 1; cases <= t; cases++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vector<int> arr;
		arr.push_back(a);
		arr.push_back(b);
		arr.push_back(c);
		sort(arr.begin(), arr.end());
		if (arr[2] >= arr[0] + arr[1])
		{
			cout << "Case #" << cases << ": invalid!\n";
			continue;
		}
		map<int, int> m;
		m[a]++;
		m[b]++;
		m[c]++;
		if (m.size() == 1) cout << "Case #" << cases << ": equilateral\n";
		if (m.size() == 2) cout << "Case #" << cases << ": isosceles\n";
		if (m.size() == 3) cout << "Case #" << cases << ": scalene\n";
	}

}