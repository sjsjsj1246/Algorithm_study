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
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
//----------------------------------------------------------

int main()
{
	FAST;
	int n, x, y;
	int q[4] = {};
	int axis = 0;
	cin >> n;
	FOR(i, n)
	{
		cin >> x >> y;
		if (x < 0 && y < 0) q[2]++;
		else if (x < 0 && y>0) q[1]++;
		else if (x > 0 && y < 0) q[3]++;
		else if (x > 0 && y > 0) q[0]++;
		else axis++;
	}
	FOR(i, 4) cout << "Q" << i + 1 << ": " << q[i] << "\n";
	cout << "AXIS: " << axis;
}