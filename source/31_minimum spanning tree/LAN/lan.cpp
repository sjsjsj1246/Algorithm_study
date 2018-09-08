#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

const int MAX_V = 100;
const int INF = 987654321;

int n;

double getDistance(pair<int,int> a, pair<int, int> b)
{
	return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

double prim(vector<vector<double>> adj)
{
	vector<bool> added(n, false);
	vector<double> minWeight(n, INF), parent(n, -1);
	double ret = 0;
	minWeight[0] = parent[0] = 0;
	for (int iter = 0; iter < n; ++iter)
	{
		int u = -1;
		for (int v = 0; v < n; ++v)
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;

		ret += minWeight[u];
		added[u] = true;
		for (int i = 0; i < n; ++i)
		{
			int v = i;
			double weight = adj[u][i];
			if (!added[v] && minWeight[v] > weight)
			{
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int c; cin >> c;
	while (c--)
	{
		int m;
		cin >> n >> m;
		vector<vector<double>> adj(n);
		vector<pair<int, int>> map(n);
		for (int i = 0; i < n; i++) cin >> map[i].first;
		for (int i = 0; i < n; i++) cin >> map[i].second;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				adj[i].push_back(getDistance(map[i],map[j]));
			}
		}
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a][b] = 0;
			adj[b][a] = 0;
		}
		printf("%.7lf\n", prim(adj));
	}
}