#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[26][26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


int BFS(pair<int, int> start)
{
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty())
	{
		int hx = q.front().first;
		int hy = q.front().second;
		cnt++;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			pair<int, int> there = { nx,ny };
			if (map[nx][ny])
			{
				q.push(there);
				map[nx][ny] = false;
			}
		}
	}
	
	return cnt;
}

int main()
{
	int cnt = 0;
	cin >> n;
	vector<int> res;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j])
			{
				map[i][j] = false;
				pair<int, int> start = { i,j };
				res.push_back(BFS(start));
				cnt++;
			}
		}
	}
	sort(res.begin(), res.end());
	cout << cnt << "\n";
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
		cout << *it << "\n";
}