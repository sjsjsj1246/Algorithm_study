#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int a; cin >> a; for(int t=1;t<=a;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	string s;
	cin >> s;
	vector<string> res;

	CASES(t)
	{
		string temp;
		cin >> temp;

		bool flag = 1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '*') continue;
			if (s[i] != temp[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag) res.push_back(temp);
	}

	cout << res.size() << "\n";
	for (auto x : res) cout << x << "\n";
}