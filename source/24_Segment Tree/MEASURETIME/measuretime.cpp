#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {}
	int sum(int pos) {
		++pos;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}
	void add(int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};



int main()
{
	std::ios::sync_with_stdio(false);
	int c; cin >> c;
	while (c--)
	{
		int n; cin >> n;
		FenwickTree ft(1000000);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int temp; cin >> temp;
			res += ft.sum(999999) - ft.sum(temp);
			ft.add(temp, 1);
		}
		cout << res << "\n";
	}
}
