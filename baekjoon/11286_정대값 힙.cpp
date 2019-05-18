#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (arr).begin(),(arr).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int main(void)
{
	FAST;
	int n;
	cin >> n;
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			if (pq.empty()) cout << 0 << "\n";
			else cout << -pq.top().second << "\n", pq.pop();
		}
		else pq.push({ -abs(temp), -temp });
	}
}