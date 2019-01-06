#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[2][100];

int main()
{
	int c; cin >> c;
	while (c--)
	{
		memset(dp, 0, sizeof(dp));
		int n; cin >> n;
		cin >> dp[0][0];
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				cin >> dp[i % 2][j];
				int one = 0, two = 0;
				one = dp[(i + 1) % 2][j];
				if (j - 1 >= 0) two = dp[(i + 1) % 2][j - 1];
				dp[i % 2][j] += max(one, two);
			}
		}
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (max < dp[(i + 1) % 2][i])
			{
				max = dp[(i + 1) % 2][i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (max < dp[i % 2][i])
			{
				max = dp[i % 2][i];
			}
		}
		printf("%d\n", max);
	}
}