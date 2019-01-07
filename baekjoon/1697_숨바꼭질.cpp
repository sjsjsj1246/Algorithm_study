#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int res[100001];

int BFS(int n, int k)
{
	queue<int> q;
	q.push(n);
	res[n] = 1;

	while (!q.empty())
	{
		int here = q.front();
		if (here == k) return res[k];
		q.pop();
		int next[3] = { here - 1,here + 1,here * 2 };
		for (int i = 0; i < 3; i++)
		{
			if (next[i] < 0 || next[i] > 100000 || res[next[i]]) continue;
			res[next[i]] = res[here] + 1;
			q.push(next[i]);
		}
	}
}


int main()
{
	int n, k;
	cin >> n >> k;
	if (n > k) cout << n - k;
	else cout << BFS(n, k) - 1;
}