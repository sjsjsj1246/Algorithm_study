#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<vector<int>> adj;

int bfs(int start)
{
    int cost = 0;
    vector<int> visit(n, 0);
    queue<int> q;
    queue<int> cnt;
    visit[start] = 1;
    q.push(start);
    cnt.push(0);
    while (!q.empty())
    {
        int here = q.front();
        int h_cnt = cnt.front();
        cost += h_cnt;
        cnt.pop();
        q.pop();
        for (int i = 0; i < adj[here].size(); i++)
        {
            int next = adj[here][i];
            if (!visit[next])
            {
                q.push(next);
                cnt.push(h_cnt + 1);
                visit[next] = 1;
            }
        }
    }
    return cost;
}

int main()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    vector<int> cabin(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        cabin[i] = bfs(i);
    }

    int Min = 987654321, pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (Min > cabin[i])
            Min = cabin[i], pos = i;
    }
    cout << pos + 1;
}