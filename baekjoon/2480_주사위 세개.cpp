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
	vector<int> arr(3);
	map<int, int> m;
	FOR(i, 0, 3) cin >> arr[i], m[arr[i]]++;
	sort(ALL(arr));
	if (m.size() == 3) cout << arr[2] * 100;
	else if (m.size() == 2) cout << 1000 + arr[1] * 100;
	else cout << 10000 + arr[2] * 1000;
}