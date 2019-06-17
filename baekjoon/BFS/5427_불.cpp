#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int testcase;
int n, m;

pair<int, int> start_point;            // 상근이의 시작 위치
vector<pair<int, int>> fire_point;     // 불의 초기 위치

char Map[1001][1001];
int fire[1001][1001];
int moving[1001][1001];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

// 불이 옮겨붙는 시간을 먼저 탐색하는 BFS
void bfs_fire() 
{
	// 불의 위치를 큐에 넣음
	queue<pair<int, int>> q;
	for (int i = 0; i < fire_point.size(); i++) 
	{
		q.push(fire_point[i]);
		fire[fire_point[i].first][fire_point[i].second] = 0;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// 벽이 아니고, 아직 불이 붙지 않은 곳이라면 이동 가능
			if (Map[nx][ny] != '#' && fire[nx][ny] == -1) {
				q.push(pair<int, int>(nx, ny));
				fire[nx][ny] = fire[x][y] + 1;
			}
		}
	}
}

// 불의 시간을 기준으로 상근이가 탈출할 수 있는지 탐색하는 BFS
void bfs_moving() 
{
	queue<pair<int, int>> q;
	q.push(start_point);
	moving[start_point.first][start_point.second] = 0;

	while (!q.empty()) 
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) 
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
			{
				// 탈출 성공
				cout << moving[x][y] + 1 << "\n";
				return;
			}

			// 빈 공간이고 아직 이동하지 않은 정점이고
			if (Map[nx][ny] == '.' && moving[nx][ny] == -1) 
			{
				// 불의 예상 시간보다 작거나 불의 범위가 아닌 곳이면 이동가능
				if (fire[nx][ny] > moving[x][y] + 1 || fire[nx][ny] == -1) 
				{
					q.push(pair<int, int>(nx, ny));
					moving[nx][ny] = moving[x][y] + 1;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << "\n";
}

int main(int argc, const char* argv[]) 
{
	FAST;
	CASES(t)
	{
		memset(fire, -1, sizeof(fire));
		memset(moving, -1, sizeof(moving));
		memset(Map, 0, sizeof(Map));
		fire_point.clear();

		cin >> m >> n;
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < m; j++) 
			{
				cin >> Map[i][j];
				if (Map[i][j] == '@')
					start_point = {i, j};
				else if (Map[i][j] == '*')
					fire_point.push_back({i, j});
			}
		}
		
		bfs_fire();
		bfs_moving();
	}
	return 0;
}