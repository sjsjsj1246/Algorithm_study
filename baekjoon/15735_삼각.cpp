#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//----------------------------------------------------------
#define f(x) (x*(x+1))/2

int main()
{
	int n;
	LL ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) ans += f(i);

	for (int i = 1; i <= n; i++)
	{
		if (n % 2 == 0)
		{
			if (i % 2 == 0) continue;
			ans += f(i);
		}
		else
		{
			if (i % 2 == 1) continue;
			ans += f(i);
		}
	}
	cout << ans;
}