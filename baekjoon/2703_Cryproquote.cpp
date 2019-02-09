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

int main() 
{
	FAST;

	int t; cin >> t;
	while (t--) 
	{
		string s, cand; 
		getline(cin, s);
		getline(cin, s);
		cin >> cand;

		for (auto c : s) c != ' ' ? cout << cand[c - 'A'] : cout << " ";
		cout << "\n";
	}
	return 0;
}