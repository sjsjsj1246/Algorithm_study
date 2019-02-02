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
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0) arr.push_back(i);
	}
	if (arr.size() < k)
	{
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		cnt++;
		if (cnt == k)
		{
			cout << *it; 
			return 0;
		}
	}
}