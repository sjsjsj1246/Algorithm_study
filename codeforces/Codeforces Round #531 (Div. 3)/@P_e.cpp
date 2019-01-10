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

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 5;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main() {
	int n;
	scanf("%d", &n);

	int arr[200000];
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);

	map<int, int> dic;
	for (int i = 0; i < n; ++i) dic[arr[i]] = i;

	ll ans = 1;
	int pos = dic[arr[0]];
	for (int i = 0; i < n; ++i) {
		if (i <= pos) {
			pos = max(pos, dic[arr[i]]);
			continue;
		}

		pos = dic[arr[i]];
		ans = ans * 2 % MOD;
	}

	printf("%lld", ans);

	return 0;
}