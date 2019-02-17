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

map<int,int> arr;

void printVector(vector<int>& vec)
{
	for (auto x : vec) cout << x << " ";
	cout << "\n";
}

void pick(int n, int m, vector<int>& picked)
{
	if (picked.size() == m)
	{
		printVector(picked);
		return;
	}
	for (auto& x : arr)
	{
		if (picked.empty() || (picked.back() <= x.first && x.second > 0))
		{
			x.second--;
			picked.push_back(x.first);
			pick(n, m, picked);
			picked.pop_back();
			x.second++;
		}
	}
}

int main()
{
	FAST;
	int a, b, temp;
	cin >> a >> b;
	FOR(i, a) cin >> temp, arr[temp]++;
	vector<int> picked;
	pick(a, b, picked);
}