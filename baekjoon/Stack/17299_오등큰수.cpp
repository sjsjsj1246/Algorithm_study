#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int cnt[1000001];

int main()
{
	FAST;
	int n; cin >> n;
	vector<int> arr(n), ans(n);
	for (int i = 0; i < n; i++) cin >> arr[i], cnt[arr[i]]++;

	cnt[0] = INF;
	stack<int> stk; 
	stk.push(0);
	for (int i = n - 1; i >= 0; i--) 
	{
		while (cnt[stk.top()] <= cnt[arr[i]]) stk.pop();
		if (cnt[stk.top()] >= INF) ans[i] = -1;
		else ans[i] = stk.top();
		stk.push(arr[i]);
	}
	for (auto i : ans) cout << i << " ";
}
