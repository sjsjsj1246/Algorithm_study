#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
 
#define MAX_N 501
using namespace std;
 
int n, k;
int aMatch[MAX_N];
int bMatch[MAX_N];
vector<int> adj[MAX_N];
 
int visit[MAX_N];
int cnt;
 
bool dfs(int a)
{
    if (visit[a] == cnt)
        return false;
 
    visit[a] = cnt;
 
    for (int i = 0; i < adj[a].size(); i++)
    {
        int b = adj[a][i];
 
        if (bMatch[b] == -1 || dfs(bMatch[b]))
        {
            bMatch[b] = a;
            aMatch[a] = b;
 
            return true;
        }
 
    }
    return false;
}
 
int bipartiteMatch()
{
    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
 
    int ans = 0;
 
    for (int start = 1; start <= n; start++)
    {
        cnt++;
        ans += dfs(start);
    }
 
    return ans;
}
int main()
{
    scanf("%d %d", &n, &k);
 
    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
 
        adj[x].push_back(y);
    }
 
    printf("%d", bipartiteMatch());
}