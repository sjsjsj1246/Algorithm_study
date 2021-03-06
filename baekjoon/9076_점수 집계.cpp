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
	cin >> n;
	vector<int> arr(5);
	FOR(i, n)
	{
		FOR(j, 5) cin >> arr[j];
		sort(ALL(arr));
		if (arr[3]-arr[1] > 3) cout << "KIN\n";
		else cout << arr[1] + arr[2] + arr[3] << "\n";
	}
}