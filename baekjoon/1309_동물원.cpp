#include <iostream>
using namespace std;

int main()
{
	int n; 
	cin >> n;
	int dp[100001] = { 0,3,7, };
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1] * 2) % 9901;
	}
	cout << dp[n];
}

/*
dp[n-2] ��ŭ ��� ������� ����� �״��� ���� 3���� ���� -> dp[n-2]*3
dp[n-1]-dp[n-2] ��ŭ ��� �ϳ��� ���ִ� ��찡 ���� �״��� ���� 2���� ���� -> (dp[n-1]-dp[n-2])*2
���� dp[n] = dp[n-2]*3 + (dp[n-1]-dp[n-2])*2
dp[n] = dp[n-2] + dp[n-1]*2
*/