#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (arr).begin(),(arr).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

 struct info
{
	int y, x, count;
};

info sang;
info king;

// 세 칸 이동(도착 지점)
int dy[8] = { -3, -2, 2, 3, 3, 2, -2, -3 };
int dx[8] = { -2, -3, -3, -2, 2, 3, 3, 2 };

// 한 칸 이동(가는 경로)
int vy[8] = { -1, 0, 0, 1, 1, 0, 0, -1 };
int vx[8] = { 0, -1, -1, 0, 0, 1, 0 };

// 두 칸 이동(가는 경로)
int ty[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int tx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

int bfs()
{
	bool visit[10][9] = { 0, };
	queue<info> q;
	q.push(sang);
	visit[sang.y][sang.x] = true;
	while (!q.empty())
	{
		int qSize = q.size();
		while (qSize--)
		{
			info goHo = q.front();
			q.pop();
			if (goHo.y == king.y && goHo.x == king.x) return goHo.count;

			for (int i = 0; i < 8; i++)
			{
				// 한 칸 검사
				int y = goHo.y + vy[i];
				int x = goHo.x + vx[i];
				if (y < 0 || y >= 10 || x < 0 || x >= 9 || (y == king.y && x == king.x)) continue;

				// 두 칸 검사
				y = goHo.y + ty[i];
				x = goHo.x + tx[i];
				if (y < 0 || y >= 10 || x < 0 || x >= 9 || (y == king.y && x == king.x)) continue;

				// 세 칸 (도착 지점) 검사
				y = goHo.y + dy[i];
				x = goHo.x + dx[i];
				if (y < 0 || y >= 10 || x < 0 || x >= 9 || visit[y][x]) continue;

				q.push({ y, x, goHo.count + 1 });
				visit[y][x] = true;
			}
		}
	}
	return -1;
}

int main(void)
{
	FAST;
	cin >> r1 >> c1 >> r2 >> c2;
	sang = { r1, c1, 0 };
	king = { r2, c2, 0 };
	cout << bfs();
	return 0;
}