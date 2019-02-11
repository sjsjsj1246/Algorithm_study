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
	int count;

	cin >> count;
	vector<pair<int, int>> a(count);

	for (int i = 0; i<count; i++)
	{
		cin >> a[i].second >> a[i].first;
	}

	sort(a.begin(), a.end());

	for (int i = 0; i<count; i++)
	{
		cout << a[i].second << " " << a[i].first << "\n";
	}

	return 0;
}