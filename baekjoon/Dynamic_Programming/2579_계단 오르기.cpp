//bottom-up 탐색에 제약이 있을 때

#include <stdio.h>
int dp[301][2], step[301];

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &step[i]);
	}
	dp[1][1] = dp[1][2] = step[1];
	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][2] + step[i];
        //1칸 올라갈때, 세칸연속으로 못올라가기 때문에 이전에 두칸 올라온 경우만 더해줌
		dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + step[i];
        //2칸 올라갈 때, 이전에 한칸 올라온 경우와 두칸 올라온 경우중 큰것 선택
	}
	printf("%d", max(dp[n][1],dp[n][2]));
}

//---------------------------------------------------
//top-down
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
int step[301], dp[301][2];

int upStair(int pos, int cnt)
{
	if (pos <= 0) return 0;
	int& ret = dp[pos][cnt];
	if (ret != -1) return ret;

	ret = step[pos];
	if (cnt == 0) return ret += max(upStair(pos - 2, 1), upStair(pos - 2, 0));
	else return ret += upStair(pos - 1, 0);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> step[i];
	cout << max(upStair(N, 1), upStair(N, 0));
}

