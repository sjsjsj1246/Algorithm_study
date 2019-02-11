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
#define MOD 45678
//----------------------------------------------------------
#define f(x) (x-'0')

int main()
{
	LL sum = 0;
	string a, b;
	cin >> a >> b;
	for (auto c1 : a)
	{
		for (auto c2 : b)
		{
			sum += f(c1)*f(c2);
		}
	}
	cout << sum;
}