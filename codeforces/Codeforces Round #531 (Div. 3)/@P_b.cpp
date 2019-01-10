#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <tuple>
#include <numeric>
#include <functional>
#include <algorithm>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 5;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };


int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int arr[5001]{}, dat[5000];
	for (int v, i = 0; i < n; ++i) {
		scanf("%d", &v);
		dat[i] = v;
		if (++arr[v] > k) return !printf("NO");
	}

	set<int> tmp[5001];

	puts("YES");
	for (int i = 0; i < n; ++i) {
		int cur;
		if (i < k) tmp[dat[i]].insert(cur = i + 1);
		else {
			cur = 1;
			while (tmp[dat[i]].find(cur) != tmp[dat[i]].end()) ++cur;
			tmp[dat[i]].insert(cur);
		}

		printf("%d ", cur);
	}

	return 0;
}