#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

bool prime[1000000] = { 1,1 };

int main()
{
	FAST;

	deque<int> dq;
	int Max = 1;
	CASES(t)
	{
		char input;
		cin >> input;
		if (input == 'A')
		{
			cin >> input;
			if (input == 'L')
			{
				dq.push_front(Max);
				Max++;
			}
			else
			{
				dq.push_back(Max);
				Max++;
			}
		}
		else
		{
			cin >> input;
			if (input == 'L')
			{
				int temp;
				cin >> temp;
				FOR(i, 0, temp) dq.pop_front();
			}
			else
			{
				int temp;
				cin >> temp;
				FOR(i, 0, temp) dq.pop_back();
			}
		}
	}
	for (auto x : dq) cout << x << "\n";
}