#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int visit[10001], cost[10001];

pair<int,int> bfs(int start, vector<vector<pair<int, int>>>& arr) 
{
	//init
	int max_pos = 1, max_cost = 0;
	memset(cost, 0, sizeof(cost)); 
	memset(visit, 0, sizeof(visit));
	
	queue<int> q;
	visit[start] = 1;
	q.push(start);

	while (!q.empty()) 
	{
		int here = q.front();
		q.pop();
		for (auto it = arr[here].begin(); it != arr[here].end(); it++) 
		{
			int next = it->first;
			if (!visit[next]) 
			{
				visit[next] = 1;
				q.push(next);
				cost[next] = cost[here] + it->second;
				max_pos = max_cost > cost[next] ? max_pos : next;
				max_cost = max(max_cost, cost[next]);
			}
		}
	}
	return { max_pos, max_cost };
}

int main() 
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int n, parent, child, cost;

	cin >> n;
	//인접리스트로 트리 표현
	//약간 그래프스럽게 풂
	vector<vector<pair<int, int>>> arr(n + 1);
	for (int i = 0; i < n - 1; i++) 
	{
		cin >> parent >> child >> cost;
		arr[parent].push_back({ child, cost });
		arr[child].push_back({ parent, cost });
	}

	pair<int, int> temp;
	temp = bfs(1, arr);
	temp = bfs(temp.first, arr);

	cout << temp.second;
}