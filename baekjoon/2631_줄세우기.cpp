#include<iostream>
using namespace std;

int main(void)
{
	int n, i, j, max = 0;
	cin >> n;
	int list[1001], dp[1001];
	for (i = 0; i < n; i++)
	{
		cin >> list[i];
		dp[i] = 1;
	}
	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
			if (list[i] > list[j])
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
	for (i = 0; i < n; i++)
		if (max < dp[i]) max = dp[i];
	cout << n - max;
	return 0;
}
