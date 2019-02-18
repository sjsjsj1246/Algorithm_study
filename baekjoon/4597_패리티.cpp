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
#define SUB(a) cout << a << "\n";
//----------------------------------------------------------

int main()
{
	FAST;
	while (1)
	{
		int cnt = 0;
		string s;
		cin >> s;
		if (s == "#") return 0;
		if (s.back() == 'e')
		{
			s.erase(s.end() - 1);
			for (auto c : s) if (c == '1') cnt++;
			if (cnt%2) s += '1';
			else s += '0';
		}
		else
		{
			s.erase(s.end() - 1);
			for (auto c : s) if (c == '1') cnt++;
			if (cnt % 2) s += '0';
			else s += '1';
		}
		SUB(s);
	}
}