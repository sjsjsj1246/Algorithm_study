#include <cstdio>
#include <cstring>
int a[22];
int b[22];
int n;
int d[22][111];
int go(int x, int y) {
	if (d[x][y]) return d[x][y];
	int &ans = d[x][y];
	if (x == n) {
		return 0;
	}
	if (y - a[x]>0) {
		ans = go(x + 1, y - a[x]) + b[x];
	}
	int temp = go(x + 1, y);
	if (ans < temp) ans = temp;
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", &a[i]);
	for (int i = 0; i<n; i++) scanf("%d", &b[i]);
	printf("%d\n", go(0, 100));
	return 0;
}
