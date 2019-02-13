#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <random>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
//----------------------------------------------------------

int arr[126][126], dist[126][126];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main()
{
	FAST;
	int n, cnt = 0;
	while (1)
	{
		cnt++;
		cin >> n;
		if (n == 0) return 0;
		FOR(i, n)FOR(j, n) cin >> arr[i][j], dist[i][j] = INF;

		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -arr[0][0], { 0,0 }});
		dist[0][0] = arr[0][0];
		while (!pq.empty())
		{
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			int cost = -pq.top().first;
			pq.pop();
			if (dist[x][y] < cost) continue;
 			FOR(i, 4)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || nx >= n || ny<0 || ny >= n) continue;
				int nestDist = cost + arr[nx][ny];
				if (dist[nx][ny] > nestDist)
				{
					dist[nx][ny] = nestDist;
					pq.push({ -nestDist, {nx,ny} });
				}
			}
		}

		cout << "Problem " << cnt << ": " << dist[n - 1][n - 1] << "\n";
	}
}