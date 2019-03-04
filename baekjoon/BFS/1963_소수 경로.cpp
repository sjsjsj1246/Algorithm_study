#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool prime[100000] = { 1,1 }; //0일때 소수
bool visit[100000];

int bfs(int start, int des)
{
	queue<int> q;
	queue<int> cnt;
	q.push(start);
	cnt.push(0);
	visit[start] = 1;
	while (!q.empty())
	{
		int here = q.front();
		int h_cnt = cnt.front();
		int num[4];
		if (here == des) return h_cnt;
		q.pop();
		cnt.pop();

		int temp = here;
		for (int i = 0; temp != 0; i++)
		{
			num[i] = temp % 10;
			temp /= 10;
		}

		for (int i = 0; i < 4; i++) 
		{
			for (int j = 0; j < 10; j++) 
			{
				int x = num[i];
				if (i != 3 | j != 0) num[i] = j;
				int next = num[0] + num[1] * 10 + num[2] * 100 + num[3] * 1000;
				if (!visit[next] && !prime[next]) 
				{
					q.push(next);
					cnt.push(h_cnt + 1);
					visit[next] = 1;
				}
				num[i] = x;
			}
		}
	}
	return -1;
}

int main()
{
	for (int i = 2; i < 100000; i++)
	{
		if (prime[i]) continue;
		for (int j = 2; i*j < 100000; j++)
		{
			prime[i*j] = 1;
		}
	}

	int t;
	cin >> t;
	while(t--)
	{
		memset(visit, 0, sizeof(visit));
		int start, des;
		cin >> start >> des;
		int ans = bfs(start, des);
		if (ans == -1) cout << "Impossible\n";
		else cout << ans << "\n";
	}
	return 0;
}