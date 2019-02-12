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
//----------------------------------------------------------

int main()
{
	LL x[3] = { 0,1,1 };
	int n;
	cin >> n;

	for (int i = 3; i <= n; i++)
	{
		x[i % 3] = x[(i + 1) % 3] + x[(i + 2) % 3];
		x[i % 3] %= MOD;
	}

	cout << x[n % 3];
}