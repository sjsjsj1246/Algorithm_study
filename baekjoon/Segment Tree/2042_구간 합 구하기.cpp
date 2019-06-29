#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 펜윅 트리의 구현.가상의 배열 A[] 의 부분 합을
// 빠르게 구현할 수 있도록 한다. 초기화시에는 A[] 의
// 원소가 전부 0 이라고 생각한다.
struct FenwickTree {
	vector<long long > tree;
	FenwickTree(long long  n) : tree(n + 1) {}

	// A[0..pos] 의 부분 합을 구한다
	long long  sum(long long  pos) {
		// 인덱스를 1 부터 시작하는 것이라고 생각하자
		++pos;
		long long  ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			// 다음 구간을 찾기 위해 최종 비트를 지운다
			pos &= (pos - 1);
		}
		return ret;
	}

	// 갱신, A[pos] 에 val 을 더한다
	void add(long long  pos, long long  val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	long long  n, m, k;
	cin >> n >> m >> k;
	vector<long long > arr(n+1);
	FenwickTree f(n+1);
	for (long long  i = 1; i <= n; i++) cin >> arr[i], f.add(i,arr[i]);
	for (long long  i = 0; i < m + k; i++)
	{
		long long  a, b, c;
		cin >> a >> b >> c;
		if (a == 1) f.add(b, -arr[b] + c), arr[b] = c;
		else cout << f.sum(c) - f.sum(b - 1) << "\n";
	}
}