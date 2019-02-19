#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <random>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;
typedef long long int LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << a << "\n";
//----------------------------------------------------------

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

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	uf.init(n + 1);
	FOR(i, m)
	{
		int c, a, b;
		cin >> c >> a >> b;
		if (c == 0) uf.merge(a, b);
		if (c == 1)
		{
			if (uf.same_set(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}