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
	vector<int> arr(n);
	FOR(i, 0, n) cin >> arr[i];

	int Min = 987654321, ans = 20000;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			sum += abs(arr[i]-arr[j]);
		}
		if (Min > sum)
		{
			Min = sum;
			ans = arr[i];
		}
		if (Min == sum && ans > arr[i]) ans = arr[i];
	}
	cout << ans;
}