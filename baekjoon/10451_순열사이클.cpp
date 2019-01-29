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
int adj[1001];

int dfs(int here)
{
	int next = adj[here];
	visited[here] = true;
	if (visited[next] == true) return 1;
	return dfs(next);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		memset(visited, false, sizeof(visited));
		int n, sum = 0, temp;
		cin >> n;

		for (int i = 0; i < n; i++) cin >> temp, adj[i] = temp - 1;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				sum += dfs(i);
			}
		}
		cout << sum << "\n";
	}
}