#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
#include <algorithm>
#define MOD 1000000000
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool check[1001] = { 1,1, };

int main(void)
{
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 2; i < n + 1; i++)
	{
		if (check[i] == 0)
		{
			for (int j = 1; i*j <n + 1; j++)
			{
				if (check[i*j] == 0) cnt++;
				check[i*j] = 1;
				if (cnt == k)
				{
					cout << i * j;
					return 0;
				}
			}
		}
	}
}