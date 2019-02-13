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
	pq.push(make_pair(0, src));
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
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main()
{
	FAST;
	int e, src, max = 0;
	cin >> v >> e >> src;
	vector<vector<pair<int, int>>> adj1(v + 1);
	vector<vector<pair<int, int>>> adj2(v + 1);
	
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj1[a].push_back(make_pair(b, c));
		adj2[b].push_back(make_pair(a, c));
	}

	vector<int> res1 = dijkstra(src, adj1);
	vector<int> res2 = dijkstra(src, adj2);

	for (int i = 1; i < v + 1; i++) if (max < res1[i] + res2[i]) max = res1[i] + res2[i];
	cout << max;
}