#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

bool visited[1001];


//int dfs(int here, vector<int> adj) 이렇게 했을 때 시간초과, 재귀호출을 할 때 adj가 계속 복사되기 때문
int dfs(int here, vector<int>& adj)
{
	int next = adj[here];
	visited[here] = 1;
	if (visited[next] == 1) return 1;
	return dfs(next, adj);
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		ZERO(visited);
		int n, sum = 0, temp;
		cin >> n;

		vector<int> adj;
		FOR(i, n) cin >> temp, adj.push_back(temp - 1);
		FOR(i, n)
		{
			if (!visited[i])
			{
				sum += dfs(i, adj);
			}
		}
		cout << sum << "\n";
	}
}