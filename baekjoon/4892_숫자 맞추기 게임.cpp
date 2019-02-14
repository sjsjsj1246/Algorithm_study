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
	int n, cnt = 0;
	while (1)
	{
		cnt++;
		cin >> n;
		if (n == 0) return 0;
		int n1 = 3 * n;
		int n2;
		if (n1 % 2 == 0) n2 = n1 / 2;
		else n2 = (n1 + 1) / 2;
		int n3 = 3 * n2;
		int n4 = n3 / 9;
		cout << cnt << ". " << (n1 % 2 ? "odd " : "even " )<< n4 << "\n";
	}
}