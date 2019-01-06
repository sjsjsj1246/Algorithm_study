#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int MAX_V = 100;
int wins[20], match[200][2];
int n, m;
int V;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

int networkFlow(int source, int sink)
{
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;

	while (true) {
		vector<int> parent(MAX_V, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while (!q.empty())
		{
			int here = q.front(); q.pop();
			for (int there = 0; there < V; ++there)
				if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
				{
					q.push(there);
					parent[there] = here;
				}
		}
		if (parent[sink] == -1) break;
		int amount = 987654321;
		for (int p = sink; p != source; p = parent[p])
			amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
		for (int p = sink; p != source; p = parent[p])
		{
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}

	return totalFlow;
}

bool canWinWith(int totalWins)
{
	if (*max_element(wins + 1, wins + n) >= totalWins)
		return false;

	V = 2 + m + n;
	memset(capacity, 0, sizeof(capacity));
	for (int i = 0; i < m; i++)
	{
		capacity[0][2 + i] = 1;

		for (int j = 0; j < 2; j++)
			capacity[2 + i][2 + m + match[i][j]] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		int maxWin = (i == 0 ? totalWins : totalWins - 1);
		capacity[2 + m + i][1] = maxWin - wins[i];
	}

	return networkFlow(0, 1) == m;
}

int main()
{
	int cases;
	cin >> cases;
	for (int cc = 0; cc < cases; ++cc) 
	{
		int cnt = 0;
		int E;
		cin >> V >> E;
		n = V; m = E;
		memset(capacity, 0, sizeof(capacity));
		for (int i = 0; i < V; ++i)
			cin >> wins[i];
		for (int i = 0; i < E; ++i) 
		{
			int a, b;
			cin >> a >> b;
			match[i][0] = a;
			match[i][1] = b;
			if (a == 0 || b == 0) cnt++;
		}
		int flag = 0;
		for (int i = wins[0]; i <= wins[0] + cnt; i++)
		{
			if (canWinWith(i))
			{
				cout << i << "\n";
				flag = 1;
				break;
			} 
		}
		if (!flag) cout << "-1\n";
	}
}