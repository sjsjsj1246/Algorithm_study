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
	int t, cnt = 0;
	cin >> t;
	while (t--)
	{
		cnt++;
		int sum = 0, temp;
		for (int i = 0; i < 10; i++) cin >> temp, sum += temp % 2 ? temp : 0;
		cout << "#" << cnt << " " << sum << "\n";
	}

}