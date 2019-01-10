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
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);

	if (x > y) return !printf("%d", n);

	int a[100], cnt = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		cnt += a[i] <= x;
	}
	
	printf("%d", cnt + 1 >> 1);

	return 0;
}