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
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << a << "\n";
//----------------------------------------------------------
int ans, n;

void play(int num, int cnt)
{
	if (cnt == n -1)
	{
		if (num % 3 == 0)
		{
			ans++;
		}
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (num == 0) continue;
		play(num * 10 + i, cnt + 1);
	}
}

int main()
{
	FAST;
	cin >> n;
	play(1, 0);
	play(2, 0);
	cout << ans;
} 