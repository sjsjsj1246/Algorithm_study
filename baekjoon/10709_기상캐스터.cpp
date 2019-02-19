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
typedef long long int LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << a << "\n";
//----------------------------------------------------------

int Map[101][101];

int main()
{
	FAST;
	char c;
	int n, m;
	cin >> n >> m;
	MINUS(Map);
	FOR(i, n) FOR(j, m) { cin >> c; if (c == 'c') Map[i][j] = 0; }
	FOR(i, n)
	{
		FOR(j, m)
		{
			if (Map[i][j] != -1)continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (!Map[i][k])
				{
					Map[i][j] = j - k;
					break;
				}
			}
		}
	}
	FOR(i, n)
	{
		FOR(j, m)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	} 
}