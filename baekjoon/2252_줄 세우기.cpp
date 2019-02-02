#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------
/*
대표적인 위상정렬 문제

1. 진입 차수가 0인 정점(즉, 들어오는 간선의 수가 0)을 선택
	- 진입 차수가 0인 정점이 여러 개 존재할 경우 어느 정점을 선택해도 무방하다.
	- 초기에 간선의 수가 0인 모든 정점을 큐에 삽입
2. 선택된 정점과 여기에 부속된 모든 간선을 삭제
	- 선택된 정점을 큐에서 삭제
	- 선택된 정점에 부속된 모든 간선에 대해 간선의 수를 감소
3. 위의 과정을 반복해서 모든 정점이 선택, 삭제되면 알고리즘 종료

큐 또는 우선순위 큐 사용
*/

int main() 
{
	int n, m, a, b;
	cin >> n >> m;
	vector<int> cntOfLink(n+1);
	vector<vector<int>> adj;
	vector<int> temp;
	queue<int> q;

	FOR(i, n+1) adj.push_back(temp);
	FOR(i, m)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		cntOfLink[b]++;
	}

	for (int i = 1; i < n+1; i++)
	{
		if (cntOfLink[i] == 0)
		{
			q.push(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int v = q.front();
		q.pop();
		cout << v << " ";

		for (int nv : adj[v])
		{
			cntOfLink[nv]--;

			if (cntOfLink[nv] == 0)
				q.push(nv);
		}
	}
}