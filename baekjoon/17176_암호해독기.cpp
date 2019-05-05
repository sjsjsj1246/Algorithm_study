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
	string e, s;
	map<char, int> a, b;
	FOR(i, 0, n)
	{
		int temp;
		cin >> temp;
		if (temp == 0) a[' ']++;
		else if (temp >= 1 && temp <= 26) a[temp - 1 + 'A']++;
		else a[temp - 27 + 'a']++;
	}
	getline(cin, s);
	getline(cin, s);

	for (auto c : s) b[c]++;
	if (a==b) cout << 'y';
	else cout << 'n';
}