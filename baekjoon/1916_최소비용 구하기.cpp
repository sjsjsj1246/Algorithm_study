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

int v;

vector<int> dijkstra(int src, vector<vector<pair<int, int>>> adj)
{
	vector<int> dist(v + 1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, src });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push({ -nextDist, there });
			}
		}
	}
	return dist;
}

int main()
{
	FAST;
	int e;
	cin >> v >> e;
	vector<vector<pair<int, int>>> adj(v + 1);
	
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}

	int src, sink; 
	cin >> src >> sink;
	vector<int> res = dijkstra(src, adj);
	cout << res[sink];
	
}