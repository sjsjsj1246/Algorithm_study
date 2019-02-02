#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

deque <int> dq;

void left() {
	int tmp = dq.front();
	dq.pop_front();
	dq.push_back(tmp);
}

void right() {
	int tmp = dq.back();
	dq.pop_back();
	dq.push_front(tmp);
}

int main() {
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	int m;
	cin >> m;
	while (m--) {
		int num;
		cin >> num;
		int cnt = 0;
		if (dq.front() == num) {
			dq.pop_front();
			n--;
			continue;
		}
		while (1) {
			left();
			cnt++;
			if (dq.front() == num) {
				dq.pop_front();
				n--;
				break;
			}
			if (cnt >= n / 2) {
				while (cnt--) {
					right();
				}
				cnt = 0;
				while (1) {
					right();
					cnt++;
					if (dq.front() == num) {
						dq.pop_front();
						n--;
						break;
					}
				}
				break;
			}
		}
		ans += cnt;
	}
	cout << ans << '\n';
	return 0;
}