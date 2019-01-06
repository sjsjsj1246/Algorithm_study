#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#define LL long long int
#define INF 987654321
using namespace std;

int v;

vector<LL> dijkstra(int src, vector<vector<pair<int, int>>> adj)
{
	vector<LL> dist(v + 1, INF);
	dist[src] = 0;
	priority_queue<pair<LL, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty())
	{
		LL cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) 
		{
			int there = adj[here][i].first;
			LL nextDist = cost + adj[here][i].second;
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
	ios::sync_with_stdio(false);
	int e;
	cin >> v >> e;
	vector<vector<pair<int, int>>> adj(v+1);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	int via1, via2;
	cin >> via1 >> via2;
	vector<LL> res = dijkstra(1, adj);
	vector<LL> res1 = dijkstra(via1, adj);
	vector<LL> res2 = dijkstra(via2, adj);

	LL resres1 = res[via1] + res1[via2] + res2[v];
	LL resres2 = res[via2] + res2[via1] + res1[v];
	if (resres1 > INF && resres2 > INF)
		cout << -1;
	else 
		cout << min(resres1, resres2);
}