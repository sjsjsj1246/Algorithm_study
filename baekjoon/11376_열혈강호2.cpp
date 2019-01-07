#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define in cin
#define out cout

#define REP(i,n) for(int i=0; i<n; i++)
#define REP2(i,s,e) for(int i=s; i<e; i++)
#define REPE(i,s,e) for(int i=s; i<=e; i++)
#define REPR(i,s,e) for(int i=s; i>=e; i--)

#define all(v) v.begin(), v.end()
#define pb push_back

#define ll long long
#define pii pair<int, int>

#define X first
#define Y second
#define intINF 2147483647
#define llINF 9223372036854775807LL
#define MOD 1000000007

#define rd(n) scanf("%d", &n)
#define rdll(n) scanf("%lld", &n)

const int MAX_V = 2010;
const int INF = intINF;

class flowNetwork
{
private:
	int V;

	int cap[MAX_V][MAX_V];
	int flow[MAX_V][MAX_V];
	vector<int> adj[MAX_V];

public:
	void init(int n)
	{
		memset(cap, 0, sizeof(cap));
		V = n;
	}

	void addEdge(int x, int y, int c)
	{
		cap[x][y] += c;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int get(int src, int sink)
	{
		memset(flow, 0, sizeof(flow));
		int totalFlow = 0;


		while (true)
		{
			int parent[MAX_V];
			memset(parent, -1, sizeof(parent));

			queue<int> Q;

			parent[src] = src;
			Q.push(src);

			while (Q.size() && parent[sink] == -1)
			{
				int here = Q.front(); Q.pop();
				for (int i = 0; i < adj[here].size(); i++)
				{
					int there = adj[here][i];
					if (cap[here][there] - flow[here][there] > 0 &&
						parent[there] == -1)
					{
						Q.push(there);
						parent[there] = here;
					}
				}
			}

			if (parent[sink] == -1) break;

			int amount = INF;
			for (int p = sink; p != src; p = parent[p])
			{
				amount = min(amount,
					cap[parent[p]][p] - flow[parent[p]][p]);
			}

			for (int p = sink; p != src; p = parent[p])
			{
				flow[parent[p]][p] += amount;
				flow[p][parent[p]] -= amount;
			}

			totalFlow += amount;
		}

		return totalFlow;
	}
};

int main()
{
	int n, m; rd(n); rd(m);
	// 0 : src
	// 1~n 
	// n+1 ~ n+m 
	// n+m+1 sink

	flowNetwork G;
	G.init(n + m + 10);

	REPE(i, 1, n)
	{
		G.addEdge(0, i, 2);
	}
	REPE(i, 1, m)
	{
		G.addEdge(n + i, n + m + 1, 1);
	}

	REPE(i, 1, n)
	{
		int k; rd(k);
		REP(j, k)
		{
			int x; rd(x);
			G.addEdge(i, n + x, 1);
		}
	}

	printf("%d", G.get(0, n + m + 1));

	return 0;
}