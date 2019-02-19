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

int main()
{
	FAST;
	CASES(t)
	{
		int a[8];
		FOR(i, 8) cin >> a[i];
		a[0] = max(1, (a[0] + a[4]));
		a[1] = max(1, (a[1] + a[5]));
		a[2] = max(0, (a[2] + a[6]));
		a[3] += a[7];
		int sum = 0;
		sum = a[0] + 5 * a[1] + 2 * a[2] + 2 * a[3];
		SUB(sum);
	}
}