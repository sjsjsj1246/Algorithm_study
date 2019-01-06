#include <iostream>
using namespace std;

int n, m, cnt;
int visited[1001];
int adj[1001][1001];

void dfs(int here)
{
	visited[here] = 1;
	for (int i = 1; i < n + 1; i++)
		if (adj[here][i] && !visited[i])
			dfs(i);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (!visited[i])
		{
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}