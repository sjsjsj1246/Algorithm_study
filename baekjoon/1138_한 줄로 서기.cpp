#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> ans(n, 0);
	FOR(i, 0, n) cin >> arr[i];
	FOR(i, 0, n)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i] == cnt && ans[j] == 0)
			{
				ans[j] = i + 1;
				break;
			}
			if (ans[j] == 0) cnt++;
		}
	}
	for (auto x : ans) cout << x << " ";
}