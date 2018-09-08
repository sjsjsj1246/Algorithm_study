#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define INF 987654321

using namespace std;

int n;

vector<double> dijkstra(int src, vector<vector<pair<int, double>>> adj)
{
	vector<double> dist(n, INF);
	dist[src] = 0;
	priority_queue<pair<double, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			double nextDist = cost + adj[here][i].second;
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
		int m;
		cin >> n >> m;
		vector<vector<pair<int, double>>> adj(n);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			double c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, log10(c)));
			adj[b].push_back(make_pair(a, log10(c)));
		}
		vector<double> res = dijkstra(0, adj);
		double ret = pow(10, res[n - 1]);
		printf("%.10f\n", ret);
	}
}