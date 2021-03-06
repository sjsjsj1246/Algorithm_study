#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
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

int n, m; //n : 정점의 수, m : 간선의 수

struct union_find_tree
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
	int v1, v2;
	int cost;
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
	FAST;
	cin >> n;
	vector<pair<int,int>> x;
	vector<pair<int, int>> y;
	vector<pair<int, int>> z;
	FOR(i, n)
	{
		int a, b, c;
		cin >> a >> b >> c;
		x.push_back({ a,i });
		y.push_back({ b,i });
		z.push_back({ c,i });
	}
	sort(ALL(x));
	sort(ALL(y));
	sort(ALL(z));
	FOR(i, n - 1)
	{
		e.push_back(Edge(x[i].second, x[i + 1].second, x[i].first > x[i + 1].first ? x[i].first - x[i + 1].first : x[i + 1].first - x[i].first));
		e.push_back(Edge(y[i].second, y[i + 1].second, y[i].first > y[i + 1].first ? y[i].first - y[i + 1].first : y[i + 1].first - y[i].first));
		e.push_back(Edge(z[i].second, z[i + 1].second, z[i].first > z[i + 1].first ? z[i].first - z[i + 1].first : z[i + 1].first - z[i].first));
	}
	cout << kruskal();
}