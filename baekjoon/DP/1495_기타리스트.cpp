#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <random>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;
typedef long long int LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (arr.begin()),(arr.end())
#define ZERO(a) memset(arr,0,sizeof(arr))
#define MINUS(a) memset(arr,-1,sizeof(arr))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << arr << "\n";
//----------------------------------------------------------
/*
dp, bottom-up
dp[i][j] = i번째 곡일 때, 볼륨 j 가능 여부
*/

int arr[101];
bool dp[101][1001];

int main()
{
	FAST;
	int n, s, m, ans = -1;
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[0][s] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j])
			{
				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] = 1;
				if (j + arr[i] <= m)
					dp[i][j + arr[i]] = 1;
			}
		}
	}
	for (int i = 0; i <= m; i++)
		if (dp[n][i])
			ans = i;

	cout << ans;
}