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
//1197문제와 동일
/*최소 스패닝 트리 : 그래프에서 모든 노드를 잇는 트리중 간선의 가중치의 합이 가장 적은 것

#Kruskal 알고리즘, 탐욕법을 이용
	1. 그래프의 간선들을 가중치를 기준으로 오름차순 정렬한다.
	2. 정렬된 간선 리스트에서 순서대로 사이클을 형성하지 않는 간선을 선택한다.
	3. 해당 간선을 현재의 MST의 집합에 추가한다.

//사이클 생성 여부를 확힌하는 법
	추가하고자 하는 간선의 양 끝 정점이 같은 집합에 속해 있는지 검사한다
	union-find 알고리즘 이용 이게더복잡

#Prim 알고리즘, 시작 정점으로부터 확장해감
	1. 시작 단계에서는 시작 정점만이 MST 집합에 포함된다.
	2. 앞 단계에서 만들어진 MST 집합에 인접한 정점들 중에서 최소 
	  간선으로 연결된 정점을 선택하여 트리를 확장한다
	3. 위 과정을 트리가 N-1개의 간선을 가질 때까지 반복한다.

#시간 복잡도 비교
Kruskal : O(elog_2 e)
prim : O(v^2)
	그래프 내에 적은 숫자의 간선만을 가지는 희소그래프의 경우는 prim 알고리즘이 적합하다.
	그래프에 간선이 많이 존재하는 밀집 그래프의 경우는 prim 알고리즘이 적합하다.
*/

int n, m; //n : 정점의 수, m : 간선의 수

struct union_find_tree //구조체를 안만들고도 할 수 있지만 만드는게 나중에는 편하다.
{
	vector<int> parent;
	vector<int> height;
	vector<int> group_size;

	void init(int uf_n)
	{
		parent.clear();
		height.clear();
		group_size.clear();
		for (int i = 0; i < uf_n; i++)
		{
			parent.push_back(i);
			height.push_back(0);
			group_size.push_back(1);
		}
	}

	int get_root(int now)
	{
		if (parent[now] == now) return now;
		return parent[now] = get_root(parent[now]);
	}

	bool same_set(int v1, int v2)
	{
		return get_root(v1) == get_root(v2);
	}

	void merge(int v1, int v2)
	{
		v1 = get_root(v1); 
		v2 = get_root(v2);
		if (v1 == v2) return;
		if (height[v1] < height[v2]) swap(v1, v2);
		parent[v2] = v1;
		group_size[v1] += group_size[v2];
		if (height[v1] == height[v2])
			height[v1]++;
	}
}uf;

struct Edge
{
	int v1, v2, cost;
	Edge(int a, int b, int c) : v1(a), v2(b), cost(c) {}
	bool operator < (const Edge& e1) const { return cost < e1.cost; } 
	// sort 함수 활용을 위한 연산자 오버로딩
};
vector<Edge> e;

int kruskal()
{
	uf.init(n + 1);
	sort(e.begin(), e.end());
	int ret = 0;
	for (auto now : e)
	{
		if (!uf.same_set(now.v1, now.v2))
		{
			ret += now.cost;
			uf.merge(now.v1, now.v2);
		}
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back(Edge(a, b, c));
	}

	cout << kruskal();
}