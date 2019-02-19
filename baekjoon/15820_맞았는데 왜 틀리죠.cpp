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
	string a, b;
	int n, m;
	cin >> n >> m;
	bool flag1 = 1, flag2 = 1;
	FOR(i, n)
	{
		cin >> a >> b;
		if (a != b) flag1 = 0;
	}
	if (flag1 == 0)
	{
		cout << "Wrong Answer";
		return 0;
	};
	FOR(i, m)
	{
		cin >> a >> b;
		if (a != b) flag2 = 0;
	}
	if (flag2) cout << "Accepted";
	else cout << "Why Wrong!!!";
} 