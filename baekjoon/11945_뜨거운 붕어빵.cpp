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

int b[11][11];

int main()
{
	int n, m;
	cin >> n >> m;
	string temp;
	FOR(i, n)
	{
		cin >> temp;
		FOR(j, m) b[i][j] = temp[j] - '0';
	}

	FOR(i, n)
	{
		FOR(j, m) 
			cout << b[i][m - j - 1];
		cout << "\n";
	}
}