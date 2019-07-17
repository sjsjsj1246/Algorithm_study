#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

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
	while (1)
	{
		e.clear();
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			e.push_back(Edge(a, b, c));
			e.push_back(Edge(b, a, c));
			sum += c;
		}

		cout << sum - kruskal() << "\n";
	}
}