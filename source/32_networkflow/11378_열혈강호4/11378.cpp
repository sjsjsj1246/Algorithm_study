#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;


const int MAX_V = 2018;
int V;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int networkFlow(int source, int sink) {
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;
	while (true) {
		vector<int> parent(MAX_V, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while (!q.empty()) {
			int here = q.front(); q.pop();
			for (int i = 0; i < adj[here].size(); ++i)
			{
				int there = adj[here][i];
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if (parent[sink] == -1) break;
		int amount = 987654321;
		for (int p = sink; p != source; p = parent[p])
			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}

	return totalFlow;
}


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	V = n + m + 2;
	// s : 0, k : 1, 2 ~ n+1, n+2, n+3 ~ n+m+2

	for (int i = 0; i < m; i++) 
	{
		adj[n + 3 + i].push_back(1);
		adj[1].push_back(n + 3 + i);
		capacity[n + 3 + i][1] = 1;
	}
	adj[0].push_back(n + 2);
	adj[n+2].push_back(0);
	capacity[0][n + 2] = k;
	for (int i = 0; i < n; i++)
	{
		adj[n + 2].push_back(2 + i);
		adj[2 + i].push_back(n + 2);
		capacity[n + 2][2 + i] = k;
	}
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		capacity[0][2 + i] = 1;
		adj[0].push_back(2 + i);
		adj[2 + i].push_back(0);
		for (int j = 0; j < num; j++)
		{
			int temp;
			scanf("%d", &temp);
			temp--;
			capacity[2 + i][3 + n + temp] = 1;
			adj[2 + i].push_back(3 + n + temp);
			adj[3 + n + temp].push_back(2 + i);
		}
	}
	cout << networkFlow(0, 1) << endl;
}