#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map<string, int> maap;
	vector<string> res;
	for (int i = 0; i < n; i++)
	{
		string temp; cin >> temp;
		maap[temp] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		string temp; cin >> temp;
		if (maap[temp] == 1)
		{
			res.push_back(temp);
		}
	}
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	vector<string>::iterator it;
	for (it = res.begin(); it != res.end(); it++)
		cout << *it << '\n';
}