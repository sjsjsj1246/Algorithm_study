#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001], dp[1001];
//LIS와 비슷
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + arr[j]);	
			//i를 만들기 위한 최대비용 = (i-j)를 만드는 최대비용 + j의 비용
		}
	}
	cout << dp[n];
}