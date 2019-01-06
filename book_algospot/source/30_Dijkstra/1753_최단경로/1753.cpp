#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#define INF 987654321
using namespace std;

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
	ios::sync_with_stdio(false);
	int e;
	cin >> v >> e;
	vector<vector<pair<int, int>>> adj(v+1);
	int src; cin >> src;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	vector<int> res = dijkstra(src, adj);
	vector<int>::iterator it;
	for (it = res.begin() + 1; it != res.end(); it++)
	{
		if (*it != INF) cout << *it << '\n';
		else cout << "INF\n";
	}
}