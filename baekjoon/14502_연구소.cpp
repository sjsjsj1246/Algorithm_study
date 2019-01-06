#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;

int n, m;
int map[8][8] = { 0 }, temp[8][8] = { 0 }, visited[8][8] = { 0 };
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> virous;

void resetMap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[i][j] = map[i][j];
		}
	}
}

int countSafezone()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] == 0) sum++;
		}
	}
	return sum;
}

void radiate(pair<int,int> start)
{
	queue<pair<int,int>> q;
	q.push(start);
	while (!q.empty())
	{
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			pair<int, int> there = { nx,ny };
			if (!visited[nx][ny]&&temp[nx][ny]==0)
			{
				temp[nx][ny] = 2;
				q.push(there);
				visited[nx][ny] = true;
			}
		}
	}
}

int main()
{
	
	fast;
	int max = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
			if (input == 2) virous.push_back({ i,j });
			map[i][j] = input;
		}
	}
	for (int i = 0; i < n*m; i++)
	{
		for (int j = i+1; j < n*m; j++)
		{
			for (int k = j+1; k < n*m; k++)
			{
				if (map[i / m][i%m] || map[j / m][j%m] || map[k / m][k%m]) continue;
				resetMap();
				memset(visited, 0, sizeof(visited));
				temp[i / m][i%m] = 1;
				temp[j / m][j%m] = 1;
				temp[k / m][k%m] = 1;
				for (auto it = virous.begin(); it != virous.end(); it++)
				{
					radiate(*it);
				}
				int res = countSafezone();
				if (max < res) max = res;
			}
		}
	}
	cout << max;
}