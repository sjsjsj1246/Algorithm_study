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

int arr[101][101], res[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main()
{
	FAST;
	string s;
	int n, m;
	cin >> m >> n;
	
	FOR(i, n)
	{
		cin >> s;
		FOR(j, m)
		{
			arr[i][j] = s[j] - '0';
		}
	}
	MINUS(res);

	queue<pair<int, int>> q;
	queue<pair<int, int>> nq;
	q.push({ 0,0 });
	res[0][0] = 0;
	while (!q.empty())
	{
		int hx = q.front().first;
		int hy = q.front().second;
		q.pop();
		FOR(i, 4)
		{
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if (res[nx][ny] == -1)
			{
				if (arr[nx][ny] == 0) 
				{
					res[nx][ny] = res[hx][hy];
					q.push(make_pair(nx, ny));
				}
				else {
					res[nx][ny] = res[hx][hy] + 1;
					nq.push(make_pair(nx, ny));
				}
			}
		}
		if (q.empty())
		{
			q = nq;
			nq = queue<pair<int, int>>();
		}
	}
	cout << res[n - 1][m - 1];
}