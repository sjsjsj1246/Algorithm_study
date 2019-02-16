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
int n, m, a, b, x, y, cnt, sum, res, ans;

bool Map[102][102];

int main()
{
	FAST;
	int x1, y1, x2, y2;
	FOR(i, 4)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				Map[j][k] = 1;
			}
		}
	}
	FOR(i, 102) FOR(j, 102) sum += Map[i][j];
	cout << sum;
}