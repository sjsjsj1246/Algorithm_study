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
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//----------------------------------------------------------

int T[305] = { 0, 1 };

int main()
{
	FAST;
	int n, k;
	cin >> n >> k;

	int t = 5;
	int cnt = n;
	int num = 0;
	while (t>0)
	{
		int temp = 0;

		while (num >= (1 << temp)) temp++;
		if (num != 0) temp--;

		for (int i = temp; i >= 0; i--)
		{
			cnt++;
			int say = (num & (1 << i)) >> i;
			if ((cnt - k) % n == 0) cout << say << " ", t--;
			if (t == 0) return 0;
		}
		num++;
	}
}