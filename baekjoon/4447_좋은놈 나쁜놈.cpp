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
	string s, t;
	getline(cin, t);
	int cases = atoi(t.c_str());
	while (cases--)
	{
		int b = 0, g = 0;
		getline(cin, s);
		for (auto c : s)
		{
			if (c == 'b' || c == 'B') b++;
			if (c == 'g' || c == 'G') g++;
		}
		cout << s << " is ";
		if (b < g) cout << "GOOD\n";
		if (b > g) cout << "A BADDY\n";
		if (b == g) cout << "NEUTRAL\n";
	}
}