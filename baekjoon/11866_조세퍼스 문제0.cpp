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
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

int main()
{
	int m, n;
	cin >> m >> n;
	vector<int> list(m);
	for (int i = 0; i < m; i++)
		list[i] = i + 1;
	printf("<");
	for (int pos = n - 1; list.size() != 1; )
	{
		printf("%d, ", list[pos]);
		list.erase(list.begin() + pos);
		pos += n - 1; pos %= list.size();
	}
	printf("%d>", list[0]);
}