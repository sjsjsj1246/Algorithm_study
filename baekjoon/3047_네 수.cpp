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


int main()
{
	FAST;
	set<int> x;
	map<char, int> y;
	int temp, cnt = 0;
	FOR(i, 3) cin >> temp, x.insert(temp);
	ITR(it, x) y['A' + cnt] = *it, cnt++;

	char c;
	FOR(i, 3) cin >> c, cout << y[c] << " ";
}