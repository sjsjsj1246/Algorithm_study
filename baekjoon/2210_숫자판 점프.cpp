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
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << a << "\n";
//----------------------------------------------------------

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int Map[5][5];
set<string> ans;

void dfs(int x, int y, string s)
{
	s += Map[x][y] + '0';
	if (s.length() == 6)
	{
		ans.insert(s);
		return;
	}
	FOR(i, 4)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		dfs(nx, ny, s);
	}

}

int main()
{
	FAST;
	FOR(i, 5) FOR(j, 5) cin >> Map[i][j];
	FOR(i, 5) FOR(j, 5) dfs(i, j, "");
	cout << ans.size();
}