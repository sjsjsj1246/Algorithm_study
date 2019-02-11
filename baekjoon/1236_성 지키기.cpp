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
//----------------------------------------------------------

int n, m;
bool ver[51], hor[51];

int main()
{
	FAST;
	cin >> n >> m;
	int Max = max(n, m);
	int ans = Max;
	string s;
	FOR(i, n)
	{
		cin >> s;
		FOR(j, m)
		{
			if (s[j] == 'X')
			{
				ver[j] = 1;
				hor[i] = 1;
			}
		}
	}

	int x = 0, y = 0;
	FOR(i, n) y += hor[i];
	FOR(j, m) x += ver[j];
	cout << max(n - y, m - x);
}