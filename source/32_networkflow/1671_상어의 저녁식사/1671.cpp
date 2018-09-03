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
int ability[MAX_V][3];
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
	int n;
	cin >> n;
	V = n + n + 1;
	// s : 0, k : 1, 2 ~ n+1, n+2 ~ n+m+1

	for (int i = 0; i < n; i++)
	{
		adj[n + 2 + i].push_back(1);
		adj[1].push_back(n + 2 + i);
		capacity[n + 2 + i][1] = 1;
	}

	for (int i = 0; i < n; ++i) {
		int a;
		capacity[0][i + 2] = 2;
		adj[0].push_back(2 + i);
		adj[2 + i].push_back(0);
		for (int j = 0; j<3; j++)
		{
			cin >> a;
			ability[i + 1][j] = a;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				bool flag1 = true, flag2 = true;
				for (int k = 0; k < 3; k++)
				{
					if (ability[i + 1][k] < ability[j + 1][k])
						flag1 = false;
				}
				if (flag1)
				{
					adj[2 + i].push_back(2 + n + j);
					adj[2 + n + j].push_back(2 + i);
					capacity[2 + i][2 + j + n] = 1;
					for (int k = 0; k < 3; k++)
					{
						if (ability[i + 1][k] != ability[j + 1][k])
							flag2 = false;
					}
					if (flag2 && i > j)
					{
						capacity[2 + i][2 + j + n] = 0;
					}
				}
			}
		}
	}

	cout << n - networkFlow(0, 1);
}