#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	map<int, int> check;
	for (int i = 0; i < adj[1].size(); i++)
	{
		check[adj[1][i]]++;
		for (int j = 0; j < adj[adj[1][i]].size(); j++)
		{
			check[adj[adj[1][i]][j]]++;
		}
	}
	cout << check.size() - 1;
}