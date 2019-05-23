#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (arr).begin(),(arr).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	vector<int> ans;
	FOR(i, 0, 5)
	{
		string s;
		cin >> s;
		if (s.find("FBI") != string::npos) ans.push_back(i + 1);
	}
	if (ans.empty()) cout << "HE GOT AWAY!";
	else for (auto x : ans) cout << x << " ";
}