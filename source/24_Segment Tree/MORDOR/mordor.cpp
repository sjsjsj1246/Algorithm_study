#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int IntMax = 2147483647;

struct RMQ {

	int n;

	vector<int> rangeMin;
	RMQ(const vector<int>& array)
	{
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	int init(const vector<int>& array, int left, int right, int node)
	{
		if (left == right) return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return IntMax;
		if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	int c; cin >> c;
	while (c--)
	{
		int n, q;
		cin >> n >> q;
		vector<int> list(n);
		for (int i = 0; i < n; i++) cin >> list[i];
		RMQ rmq1(list);
		for (int i = 0; i < n; i++) list[i] *= -1;
		RMQ rmq2(list);
		for (int i = 0; i < q; i++)
		{
			int a, b;
			cin >> a >> b;
			cout << -rmq2.query(a, b) - rmq1.query(a, b) << "\n";
		}
	}
}