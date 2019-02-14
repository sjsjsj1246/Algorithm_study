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
	double a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) return 0;
		if (c - b == b - a) cout << "AP " << c + (b - a) << "\n";
		else if (c / b == b / a) cout << "GP " << (b / a)*c << "\n";
	}
}