#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//----------------------------------------------------------

int main()
{
	FAST;
	while (1)
	{
		int n, sum = 0;
		set<int> ans;
		cin >> n;
		if (n == -1) return 0;
		for (int i = 1; i < n; i++) if (n%i == 0) sum += i, ans.insert(i);
		if (sum == n)
		{
			cout << n << " = ";
			int cnt = 0;
			ITR(it, ans)
			{
				cout << *it;
				cnt++;
				if (cnt == ans.size())break;
				cout << " + ";
			}
			cout << "\n";
		}
		else
		{
			cout << n << " is NOT perfect.\n";
		}
	}
}