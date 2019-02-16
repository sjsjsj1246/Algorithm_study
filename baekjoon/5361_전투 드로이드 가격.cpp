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
	double price[5] = { 350.34,230.9,190.55,125.3,180.9 };
	double arr[5];
	int t;
	scanf("%d", &t);
	while (t--)
	{
		FOR(i, 5) scanf("%lf", &arr[i]);
		double sum = 0;
		FOR(i, 5) sum += price[i] * arr[i];
		printf("$%.2f\n", sum);
	}
}