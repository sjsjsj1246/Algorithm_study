#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	vector<int> arr(3);
	FOR(i, 0, 3) cin >> arr[i];
	sort(ALL(arr));
	int d;
	cin >> d;
	
	int ans = 0;
	while (arr[1] - arr[0] < d) arr[0]--, ans++;
	while (arr[2] - arr[1] < d) arr[2]++, ans++;
	cout << ans;
}