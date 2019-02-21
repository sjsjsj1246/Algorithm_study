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
typedef long long int LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (arr.begin()),(arr.end())
#define ZERO(a) memset(arr,0,sizeof(arr))
#define MINUS(a) memset(arr,-1,sizeof(arr))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << arr << "\n";
//----------------------------------------------------------

int main()
{
	FAST;
	int temp, MAX = 0;
	CASES(t)
	{
		int cnt = 0, sum = 0;
		map<int, int> m;
		FOR(i, 3) cin >> temp, m[temp]++;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			cnt++;
			if ((*it).second == 3) { sum += 10000 + (*it).first * 1000; break; }
			if ((*it).second == 2) { sum += 1000 + (*it).first * 100; break; }
			if (cnt == 3) sum += (*it).first * 100;
		}
		if (MAX < sum) MAX = sum;
	}
	cout << MAX;
}
