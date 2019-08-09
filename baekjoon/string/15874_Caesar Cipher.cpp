#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1999
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	n %= 26;
	string s;
	getline(cin, s);
	getline(cin, s);
	vector<int> arr(m);
	for (int i = 0; i < m; i++) arr[i] = s[i];
	for (int& c : arr)
	{
		if (c >= 'a' && c <= 'z')
		{
			c += n;
			while (c > 'z') c -= 26;
		}
		if (c >= 'A' && c <= 'Z')
		{
			c += n;
			while (c > 'Z') c -= 26;
		}
	}
	for (auto x : arr) cout << (char)x;
}