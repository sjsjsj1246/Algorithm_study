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
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
//----------------------------------------------------------
/*
dp, bottom-up
dp[n] n을 만드는 동전의 개수
*/
int dp[10001];

int main()
{
	FAST;
	int t, n, price;
	cin >> t;
	while (t--)
	{
		ZERO(dp);
		dp[0] = 1;
		cin >> n;
		vector<int> coin(n);
		FOR(i, n) cin >> coin[i];
		cin >> price;
		FOR(i, n) for (int j = coin[i]; j <= price; j++) dp[j] += dp[j - coin[i]];
		cout << dp[price] << "\n";
	}
}