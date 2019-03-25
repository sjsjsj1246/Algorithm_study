#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool visit[1000001];

int bfs(int start)
{
	queue<int> q, cnt;
	q.push(start);
	cnt.push(0);
	visit[start] = 1;
	while(!q.empty())
	{
		int here = q.front();
		int h_cnt = cnt.front();
		if (here == G) return h_cnt;
		q.pop();
		cnt.pop();
		int next1 = here + U;
		int next2 = here - D;
		if (next1 <= F && !visit[next1])
			q.push(next1), cnt.push(h_cnt + 1), visit[next1] = 1;
		if (next2 > 0 && !visit[next2])
			q.push(next2), cnt.push(h_cnt + 1), visit[next2] = 1;
	}
	return -1;
}

int main()
{
	cin >> F >> S >> G >> U >> D;
	int res = bfs(S);
	if (res == -1) cout << "use the stairs";
	else cout << res;
}