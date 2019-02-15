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

int arr[100001];

int main()
{
	FAST;
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
	cin >> m;
	FOR(i, m)
	{
		int a, b;
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << "\n";
	}
}