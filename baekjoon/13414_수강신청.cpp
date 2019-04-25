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
	int n, m;
	cin >> n >> m;
	vector<string> arr(m);
	map<string, int> Map;
	FOR(i, 0, m) cin >> arr[i], Map[arr[i]]++;
	
	int cnt = 0;
	FOR(i, 0, arr.size())
	{
		if (Map[arr[i]] == 1)
			cout << arr[i] << "\n", cnt++;
		else
			Map[arr[i]]--;
		if (cnt == n) break;
	}
}