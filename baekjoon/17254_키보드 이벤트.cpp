#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

struct Key
{
	int id, time;
	char c;
	bool operator < (Key op)
	{
		if (time == op.time) return id < op.id;
		else return time < op.time;
	}
};

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	vector<Key> arr(m);
	FOR(i, 0, m) cin >> arr[i].id >> arr[i].time >> arr[i].c;

	sort(ALL(arr));
	for (auto x : arr) cout << x.c;
}