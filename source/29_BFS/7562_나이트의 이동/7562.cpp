#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { 1,-1,2,-2,2,-2,1,-1 };
bool visited[301][301];
int n, ax, ay, bx, by, res;

void bfs(int x, int y, int cnt)
{
	queue<pair<int,int>> q;
	queue<int> q2;
	pair<int, int> temp = { x,y };
	q.push(temp);
	q2.push(0);
	while (!q.empty()) 
	{
		int hx = q.front().first;
		int hy = q.front().second;
		int cnt = q2.front();
		if ( hx == bx && hy == by)
		{
			res = cnt;
			break;
		}
		q.pop();
		q2.pop();
		for (int i = 0; i < 8; i++)
		{
			
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			pair<int, int> there = { nx,ny };
			if (!visited[nx][ny]) 
			{
				q.push(there);
				q2.push(cnt + 1);
				visited[nx][ny] = true;
			}
		}
	}
}

int main()
{
	int c; cin >> c;
	while (c--)
	{
		res = 0;
		memset(visited, 0, sizeof(visited));
		cin >> n;
		cin >> ax >> ay >> bx >> by;
		bfs(ax, ay, 0);
		cout << res << endl;
	}
}