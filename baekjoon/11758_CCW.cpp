#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
	int temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0) {
		return 1;
	}
	else if (temp < 0) {
		return -1;
	}
	else {
		return 0;
	}
}
 
 
int main()
{
	vector<pair<int, int>> arr;
	for (int i = 0; i < 3; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	cout << ccw(arr[0].first, arr[1].first, arr[2].first, arr[0].second, arr[1].second, arr[2].second);
}