#include <stdio.h>

int main()
{
    int dp[12];
    int T, n;

    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            //1, 2, 3 을 빼줌으로써 1,2,3을 사용한 셈이 되고
            //i-1, i-2, i-3을 만드는 경우는 dp로
        }
        printf("%d\n", dp[n]);
    }
}

//------------------------------------------------------------
//top-down
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[12];

int memo(int n)
{
	if (n < 0) return 0;
	int &ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= 3; i++)
	{
		ret += memo(n - i);
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << memo(n) << "\n";
	}
}