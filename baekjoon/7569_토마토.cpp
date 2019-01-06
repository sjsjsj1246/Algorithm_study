#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <bitset>
#include <set>
#include <map>
using namespace std;
#define inf 2000000000
#define mod 1000000007
int arr[102][102][102];
int m, n, h;
int bfs() {
	int maxl = 0;
	queue<int> x, y, l, z;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (arr[i][j][k] == 1) {
					y.push(j);
					x.push(k);
					z.push(i);
					l.push(0);
				}
			}
		}
	}
	if (x.empty()) {
		return -1;
	}
	if (n*m*h == x.size()) {
		return 0;
	}
	int pz[6] = { 0,0,0,0,1,-1 }, py[6] = { -1,0,1,0,0,0 }, px[6] = { 0,1,0,-1,0,0 };
	while (!x.empty()) {
		int fx = x.front(), fy = y.front(), fz = z.front(), fl = l.front();
		//    cout << fz << " " << fy << " " << fx << '\n';
		x.pop(), y.pop(), z.pop(), l.pop();
		for (int i = 0; i<6; i++) {
			if (arr[fz + pz[i]][fy + py[i]][fx + px[i]] == 0) {
				y.push(fy + py[i]);
				x.push(fx + px[i]);
				z.push(fz + pz[i]);
				l.push(fl + 1);
				arr[fz + pz[i]][fy + py[i]][fx + px[i]] = 1;
			}
		}
		maxl = fl;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (arr[i][j][k] == 0) {
					maxl = -1;
					break;
				}
			}

		}
	}
	return maxl;
}
int main() {
	cin >> m >> n >> h;
	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			for (int k = 0; k <= m + 1; k++) {
				arr[i][j][k] = -1;
			}
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				scanf("%d", &arr[i][j][k]);
			}
		}
	}
	cout << bfs();
}