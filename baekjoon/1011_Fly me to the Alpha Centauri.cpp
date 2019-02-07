#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		LL a, b;
		cin >> a >> b;
		LL x = b - a;
		for (LL i = 0;; i++)
		{
			if (x - i*i < 0)
			{
				LL n = i - 1;
				LL temp = x - n*n;
				cout << 2 * n - 1 + temp / n + (temp % n != 0) << "\n";
				break;
			}
		}
	}
	return 0;
}