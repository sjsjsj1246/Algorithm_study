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
#define f(x) (x*(x+1))/2

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;

		vector<int> arr;
		for (auto c : s) arr.push_back(c - '0');

		if (next_permutation(ALL(arr)))
		{
			for (auto a : arr) cout << a;
			cout << "\n";
		}
		else
		{
			cout << "BIGGEST\n";
		}
	}
}