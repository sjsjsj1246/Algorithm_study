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
	int n, cnt = 1, temp;
	cin >> n;
	vector<int> arr(n);
	stack<int> s, d;
	FOR(i, 0, n) cin >> arr[i];
	for (auto it = arr.rbegin(); it != arr.rend(); it++) d.push(*it);

	string ans;
	bool flag = 0;
	while (!d.empty())
	{
		if (cnt > n + 1)
		{
			flag = 1;
			break;
		}
		if (s.empty() || s.top() != d.top())
		{
			s.push(cnt);
			ans += '+';
			cnt++;
		}
		else
		{
			s.pop();
			d.pop();
			ans += '-';
		}
	}
	if (flag) cout << "NO";
	else
	{
		for (auto c : ans) cout << c << "\n";
	}
}