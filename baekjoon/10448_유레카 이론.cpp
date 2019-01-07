#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;

int tri[46] = { 0 };

bool go(int n)
{
	for (int i = 1; i <= 45; i++)
	{
		for (int j = i; j <= 45; j++)
		{
			for (int k = j; k <= 45; k++)
			{
				if (n == tri[i] + tri[j] + tri[k]) return 1;
			}
		}
	}
	return 0;
}

int main()
{
	for (int i = 1; i <= 45; i++)
	{
		tri[i] = i * (i + 1) / 2;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		cout << go(temp) << "\n";
	}
}