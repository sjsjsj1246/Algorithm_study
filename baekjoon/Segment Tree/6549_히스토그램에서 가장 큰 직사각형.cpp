#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 187654321
typedef long long ll;
using namespace std;

void init(vector<int>& a, vector<int>& tree, int node, int start, int end) 
{
	if (start == end) tree[node] = start;
	else 
	{
		init(a, tree, node * 2, start, (start + end) / 2);
		init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		if (a[tree[node * 2]] <= a[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
		else tree[node] = tree[node * 2 + 1];
	}
}
int query(vector<int>& a, vector<int>& tree, int node, int start, int end, int i, int j) 
{
	if (i > end || j < start)  return -1;
	if (i <= start && end <= j) return tree[node];
	int m1 = query(a, tree, 2 * node, start, (start + end) / 2, i, j);
	int m2 = query(a, tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else 
	{
		if (a[m1] <= a[m2]) return m1;
		else return m2;
	}
}
long long largest(vector<int>& a, vector<int>& tree, int start, int end) 
{
	int n = a.size();
	int m = query(a, tree, 1, 0, n - 1, start, end);
	long long area = (long long)(end - start + 1) * (long long)a[m];
	if (start <= m - 1) 
	{
		long long temp = largest(a, tree, start, m - 1);
		if (area < temp) area = temp;
	}
	if (m + 1 <= end) 
	{
		long long temp = largest(a, tree, m + 1, end);
		if (area < temp) area = temp;
	}
	return area;
}

int main()
{
	FAST;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) return 0;
		vector<int> arr(n);
		FOR(i, 0, n) cin >> arr[i];
		int h = (int)(ceil(log2(n)) + 1e-9);
		int tree_size = (1 << (h + 1));
		vector<int> tree(tree_size);
		init(arr, tree, 1, 0, n - 1);
		cout << largest(arr, tree, 0, n - 1) << '\n';
	}
}