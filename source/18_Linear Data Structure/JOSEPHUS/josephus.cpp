#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> list(n);
		for (int i = 0; i < n; i++)
			list[i] = i + 1;
		for (int pos = 0; list.size() > 2;pos = (pos+k-1)%list.size())
		{
			list.erase(list.begin() + pos);
		}
		for (vector<int>::iterator it = list.begin(); it != list.end(); it++)
		{
			cout << *it << " ";
		}
		puts("");
	}
}