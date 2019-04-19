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
	vector<string> arr(n);
	string s = "ACGT";
	map<char, int> map;
	map['A'] = 0;
	map['C'] = 1;
	map['G'] = 2;
	map['T'] = 3;

	int ans = 0;
	FOR(i, 0, n) cin >> arr[i];
	FOR(i, 0, m)
	{
		vector<int> cnt(n);
		FOR(j, 0, n)
		{
			cnt[map[arr[j][i]]]++;
		}
		cout << s[max_element(ALL(cnt))-cnt.begin()];
		ans += n - *max_element(ALL(cnt));
	}
	cout << "\n" << ans;
}