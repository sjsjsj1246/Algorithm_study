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
#define SUB(a) cout << a << "\n";
//----------------------------------------------------------

int main()
{
	FAST;
	int n;
	cin >> n;
	vector<int> arr(n);
	FOR(i, n) cin >> arr[i];
	sort(ALL(arr), greater<int>());

	int passDay = 1, remainDay;
	remainDay = arr[0];
	for (int i = 1; i < n; i++)
	{
		remainDay--, passDay++;
		remainDay = max(arr[i], remainDay);
	}
	cout << remainDay + passDay + 1;
}