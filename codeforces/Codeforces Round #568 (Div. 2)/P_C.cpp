#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 987654321
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	FOR(i, 0, n) cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		temp.assign(arr.begin(), arr.begin() + i);
		sort(ALL(temp));
		
		int j = 0, sum = arr[i];

		for (j = 0; j < temp.size(); j++)
		{
			sum += temp[j];
			if (sum > m) break;
		}
		cout << temp.size() - j << " ";
	}

}