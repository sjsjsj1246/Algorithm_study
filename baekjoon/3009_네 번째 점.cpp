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
//한번만 나온 숫자만 출력, 같은 수를 두번 ^해주면 0이됨

int main()
{
	FAST;
	int x[3], y[3];
	FOR(i, 3) cin >> x[i] >> y[i];
	cout << (x[0] ^ x[1] ^ x[2]) << " " << (y[0] ^ y[1] ^ y[2]); //하나만 있는 수만 살아남음
}