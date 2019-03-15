#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b, n, w;
	cin >> a >> b >> n >> w;
	vector<pair<int, int>> answer;
	for (int i = 1; i < n; i++)
	{
		if (a*(i)+b * (n - i) == w) answer.push_back({ i,n - i });
	}
	if (answer.size() > 1 || answer.empty()) cout << -1;
	else cout << answer[0].first << " " << answer[0].second;
}