#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <random>
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
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
//----------------------------------------------------------

int main()
{
	FAST;
	vector<int> arr = { 1,0,0 };
	string s; cin >> s;
	for (auto c : s)
	{
		if (c == 'A') swap(arr[0], arr[1]);
		else if (c == 'B') swap(arr[1], arr[2]);
		else if (c == 'C') swap(arr[0], arr[2]);
	}
	cout << distance(arr.begin(), find(ALL(arr), 1))+1;
}