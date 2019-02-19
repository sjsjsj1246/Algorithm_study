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
	int a, b, c, d;
	int p, m, n;
	cin >> a >> b >> c >> d;
	cin >> p >> m >> n;
	cout << ((p % (a + b)) <= a && (p % (a + b)) > 0) + ((p % (c + d)) <= c && (p % (c + d)) > 0) << "\n";
	cout << ((m % (a + b)) <= a && (m % (a + b)) > 0) + ((m % (c + d)) <= c && (m % (c + d)) > 0) << "\n";
	cout << ((n % (a + b)) <= a && (n % (a + b)) > 0) + ((n % (c + d)) <= c && (n % (c + d)) > 0) << "\n";
}