#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define INF 2147000000

using namespace std;

int v;

vector<int> dijkstra(int src, vector<vector<pair<int, int>>> adj)
{
	vector<int> dist(v+1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main()
{
	int c; cin >> c;
	while (c--)
	{
		int e, n, m;
		cin >> v >> e >> n >> m;
		vector<vector<pair<int, int>>> adj(v + 1);
		vector<int> fire(n);
		for (int i = 0; i < e; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		for (int i = 0; i < n; i++) cin >> fire[i];
		for (int i = 0; i < m; i++)
		{
			int fs; cin >> fs;
			adj[0].push_back(make_pair(fs,0));
		}
		vector<int> res = dijkstra(0, adj);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += res[fire[i]];
		}
		cout << sum << "\n";
	}
}   