#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

struct BUS
{
	int a, b, c;
	bool operator <(BUS op)
	{
		return this->a < op.a;
	}
};

int main()
{
	FAST;
	int n, t;
	cin >> n >> t;
	vector<BUS> arr(n);
	FOR(i, 0, n) cin >> arr[i].a >> arr[i].b, arr[i].c = i + 1;

	int pos = 1;
	while (1)
	{
		sort(ALL(arr));
		bool flag = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (t == arr[i].a || (t <= arr[i].a && arr[0].a >= t))
			{
				pos = arr[i].c;
				flag = 1;
				break;
			}
		}
		if (flag) break;

		for (int i = 0; i < arr.size(); i++) arr[i].a += arr[i].b;
	}
	cout << pos;

}