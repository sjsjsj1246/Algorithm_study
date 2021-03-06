#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 187654321
typedef long long ll;
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> last;
	last.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int cur;
		cin >> cur;
		if (last.back() < cur) last.push_back(cur);
		else *lower_bound(last.begin(), last.end(), cur) = cur;
	}
	cout << last.size() - 1 << "\n";
}