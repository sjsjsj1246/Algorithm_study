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
	int n;
	scanf("%d", &n);

	char str[300001];
	scanf("%s", str);

	int cnt[3]{};
	for (int i = 0; str[i]; ++i) cnt[str[i] - 48]++;

	int dif[3];
	for (int i = 0; i < 3; ++i) dif[i] = cnt[i] - n / 3;

	int i;
	int tmp[3]{};
	for (i = 0; str[i]; ++i) {
		if (dif[0] < 0) {
			if ('0' == str[i] || dif[str[i] - 48] <= 0) continue;
			dif[str[i] - 48]--;
			dif[0]++;
			str[i] = '0';
		}
		else if (dif[1] < 0) {
			if ('2' != str[i] || dif[str[i] - 48] <= 0) continue;
			dif[2]--;
			dif[1]++;
			str[i] = '1';
		}


	}

	for (--i; ~i; --i) {
		if (dif[2] < 0) {
			if ('2' == str[i] || dif[str[i] - 48] <= 0) continue;
			dif[str[i] - 48]--;
			dif[2]++;
			str[i] = '2';
		}
		else if (dif[1] < 0) {
			if ('0' != str[i] || dif[str[i] - 48] <= 0) continue;
			dif[0]--;
			dif[1]++;
			str[i] = '1';
		}
	}

	puts(str);

	return 0;
}