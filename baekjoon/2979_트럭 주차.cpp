#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int cost[4] = { 0, };
	for (int i = 1; i < 4; i++) cin >> cost[i];
	int count[100] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		int n, m;
		cin >> n >> m;
		for (int j = n - 1; j < m-1; j++)
		{
			count[j]++;
		}
	}
	int sum = 0;
	for (int i = 0; i < 100; i++) sum += cost[count[i]]*count[i];
	cout << sum;
}