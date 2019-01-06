#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<stack>
#include<string>
#include<map>
#include<cstring>
#include<cmath>
#include<cstdio>

#define INF 0x6FFFFFFF
#define JUDGE 987654321

using namespace std;
bool visited[101];

bool bfs(int start, int des, vector<vector<pair<int, int>>> adj) {
    vector<bool> discovered(adj.size(), false);
    queue<int> q;
    discovered[start] = true;
    q.push(start);
    while (!q.empty()) {
        int here = q.front();
        if (here == des)
            return true;
        q.pop();
        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            if (!discovered[there]) {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
    return false;
}


vector<int> bellmanFord(int src, vector<vector<pair<int, int>>> adj, int V) {
    vector<int> upper(V, INF);
    int flag;
    upper[src] = 0;
    bool updated;
    bool reach;
    for (int iter = 0; iter < V; ++iter) {
        updated = false;
        for (int here = 0; here < V; ++here) {
            for (int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if (upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                    if (iter == V - 1)
                        flag = here;
                }
            }
        }
        if (!updated) break;
    }
    if (updated)
    {
        reach = bfs(flag, 1, adj);
        if (reach)
            upper.clear();
    }
    return upper;
}
int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        int V, W;
        cin >> V >> W;
        vector<vector<pair<int, int>>> adj1(V);
        vector<vector<pair<int, int>>> adj2(V);
        for (int i = 0; i < W; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            pair<int, int> temp1 = { b, d };
            pair<int, int> temp2 = { b, -d };
            adj1[a].push_back(temp1);
            adj2[a].push_back(temp2);
        }
        vector<int> past(V);
        past = bellmanFord(0, adj1, V);
        memset(visited, 0, sizeof(visited));
        vector<int> future(V);
        future = bellmanFord(0, adj2, V);
        if (!past.empty() && past[1] > INF - JUDGE)
            cout << "UNREACHABLE";
        else if (!future.empty() && future[1] > INF - JUDGE)
            cout << "UNREACHABLE";
        else
        {
            if (past.empty())
                cout << "INFINITY" << ' ';
            else
                cout << past[1] << ' ';
            if (future.empty())
                cout << "INFINITY";
            else
                cout << -future[1];
        }
        cout << endl;
    }
}