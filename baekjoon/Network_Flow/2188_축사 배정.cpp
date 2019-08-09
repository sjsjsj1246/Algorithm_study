#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1999
#define INF 987654321
typedef long long ll;
using namespace std;

const int MAX_V = 500;
int V;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int networkFlow(int source, int sink) 
{
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;

	while (1) {
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


int main() 
{
	FAST;
	int n, m;
	cin >> n >> m;
	V = n + m + 1;
	// s : 0, k : 1, 2 ~ n+1, n+2 ~ n+m+1

	for (int i = 0; i < n; i++) 
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int temp;
			cin >> temp;
			adj[2 + i].push_back(n + 1 + temp);
			adj[n + 1 + temp].push_back(2 + i);
			capacity[2 + i][n + 1 + temp] = 1;
		}
		capacity[0][i + 2] = 1;
		adj[0].push_back(2 + i);
		adj[2 + i].push_back(0);
	}

	for (int i = 0; i < m; i++)
	{
		adj[n + 2 + i].push_back(1);
		adj[1].push_back(n + 2 + i);
		capacity[n + 2 + i][1] = 1;
	}

	cout << networkFlow(0, 1);
}