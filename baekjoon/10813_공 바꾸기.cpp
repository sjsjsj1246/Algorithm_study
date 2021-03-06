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
int n, m, a, b, x, y, cnt, sum, res, ans;

int main()
{
	FAST;
	cin >> n >> m;
	vector<int> arr(n);
	FOR(i, n) arr[i] = i + 1;
	FOR(i, m)
	{
		cin >> x >> y;
		swap(arr[x - 1], arr[y - 1]);
	}
	ITR(it, arr) cout << *it << " ";
}