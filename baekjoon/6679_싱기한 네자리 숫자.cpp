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
	int t = 1000;
	while (t < 10000)
	{
		int sum10 = 0, sum12 = 0, sum16 = 0;
		int temp = t;
		while (temp > 0)
		{
			sum10 += temp % 10;
			temp /= 10;
		}
		temp = t;
		while (temp > 0)
		{
			sum12 += temp % 12;
			temp /= 12;
		}
		temp = t;
		while (temp > 0)
		{
			sum16 += temp % 16;
			temp /= 16;
		}
		if (sum10 == sum12 && sum12 == sum16) cout << t << "\n";
		t++;
	}
}