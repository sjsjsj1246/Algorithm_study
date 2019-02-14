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
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
//----------------------------------------------------------

int main()
{
	FAST;
	string s, t;
	getline(cin, t);
	int cases = atoi(t.c_str());
	FOR(i, cases)
	{
		bool check[26] = { 0 };
		getline(cin, s);
		for (auto c : s)
		{
			if (c <= 'z'&&c >= 'a')
			{
				check[c - 'a'] = 1;
			}
			if (c <= 'Z'&&c >= 'A')
			{
				check[c - 'A'] = 1;
			}
		}
		bool flag = 1;
		for (auto x : check)
		{
			if (x == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag) cout << "pangram";
		else
		{
			cout << "missing ";
			FOR(i, 26) if (check[i] == 0) cout << (char)(i + 'a');
		}
		cout << "\n";
	}
}