#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int a; cin >> a; for(int t=1;t<=a;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

bool cmp(string a, string b)
{
	if (a.length() < b.length()) return 1;
	else if (a.length() > b.length()) return 0;
	else
	{
		int aa = 0, bb = 0;
		for (auto c : a) if (c >= '0' && c <= '9') aa += c - '0';
		for (auto c : b) if (c >= '0' && c <= '9') bb += c - '0';
		if (!aa&!bb)
		{
			return a < b;
		}
		if (aa < bb) return 1;
		else if (aa > bb) return 0;
		else
		{
			return a < b;
		}
	}
}

int main()
{
	FAST;
	int n;
	cin >> n;
	vector<string> arr(n);
	FOR(i, 0, n) cin >> arr[i];
	sort(ALL(arr), cmp);
	for (auto x : arr) cout << x << "\n";
}