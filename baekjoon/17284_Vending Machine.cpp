#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int arr[] = { 500,800,1000 };
	int ans = 5000;
	string s;
	getline(cin, s);
	while (1)
	{
		string temp;
		auto pos = s.find(" ");
		if (pos == string::npos) break;
		else temp = s.substr(0, pos);
		s = s.substr(pos + 1, s.length());
		ans -= arr[stoi(temp)-1];
	}
	ans -= arr[stoi(s)-1];
	cout << ans;
}