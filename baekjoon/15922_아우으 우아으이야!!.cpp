#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<pair<int, int>> list(n);
	for (int i = 0; i < n; i++)
	{
		cin >> list[i].first >> list[i].second;
	}
	vector<pair<int, int>>::iterator it;
	int a = list[0].first, b = list[0].second;
	long long int lenSum = 0;
	for (it = list.begin() + 1; it != list.end(); it++)
	{
		if ((*it).first <= b && (*it).second >= b) b = (*it).second;
		else if ((*it).first > b)
		{
			lenSum += b - a;
			a = (*it).first, b = (*it).second;
		}
	}
	cout << lenSum + (b - a);
}