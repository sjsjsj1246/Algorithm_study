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

int T[305] = { 0, 1 };

int main()
{
	FAST;
	for (int i = 2; i < 305; i++)
	{
		T[i] = T[i - 1] + i;
	}

	int t;
	cin >> t;
	while (t--)
	{
		int n, ans = 0;;
		cin >> n;
		for (int k = 1; k <= n; k++)
		{
			ans += k * T[k + 1];
		}
		cout << ans << "\n";
	}
}