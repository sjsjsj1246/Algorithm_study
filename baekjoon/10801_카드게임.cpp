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

int main()
{
	FAST;
	int a[10], b[10];
	int aa = 0, bb = 0;
	FOR(i, 10) cin >> a[i];
	FOR(i, 10) cin >> b[i];
	FOR(i, 10)
	{
		if (a[i] < b[i]) bb++;
		if (a[i] > b[i]) aa++;
	}
	if (aa == bb) cout << "D";
	if (aa < bb) cout << "B";
	if (aa > bb) cout << "A";
}