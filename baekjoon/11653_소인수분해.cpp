#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef signed long long ll;

#define FOR(x,to) for(x=0;x<(to);x++)
#define ITR(x, arr) for(auto&x : arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

int main()
{
	FAST;
	int n;
	cin >> n;
	if (n == 1) return 0;
	bool flag = 1;
	vector<int> res;
	while (flag)
	{
		flag = 0;
		for (int i = 2; i < n; i++)
		{
			if (n%i == 0)
			{
				n /= i;
				res.push_back(i);
				flag = 1;
				break;
			}
		}
	}
	res.push_back(n);
	sort(ALL(res));
	ITR(x, res) cout << x << "\n";
}