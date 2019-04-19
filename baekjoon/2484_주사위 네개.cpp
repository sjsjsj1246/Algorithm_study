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

	int ans = 0;
	CASES(t)
	{
		vector<int> arr(4);
		map<int, int> Map;
		FOR(i, 0, 4) cin >> arr[i], Map[arr[i]]++;

		int Max_num = 0;
		int Max_cnt = 0;
		int sum = 0;
		for (auto x : Map)
		{
			if (Max_cnt <= x.second)
			{
				Max_cnt = x.second;
				Max_num = x.first;
			}
		}
		if (Map.size() == 4) sum = Max_num * 100;
		else if (Map.size() == 3) sum = 1000 + Max_num * 100;
		else if (Map.size() == 2)
		{
			if(Max_cnt == 3)
				sum = 10000 + Max_num * 1000;
			else
			{
				sum = 2000;
				for (auto x : Map)
				{
					sum += x.first * 500;
				}
			}
		}
		else if (Map.size() == 1) sum = 50000 + Max_num * 5000;
		ans = max(ans, sum);
	}
	cout << ans;
}