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
	int n, m;
	cin >> n >> m;
	for (int start = 1; start < m; start++)
	{
		for (int second = 1; second < m; second++)
		{
			int sum = start;
			vector<int> arr(n);
			arr[0] = start;
			arr[1] = second;
			for (int i = 2; i < n; i++) arr[i] = arr[i - 1] + arr[i - 2];
			if (arr.back() == m)
			{
				cout << start << "\n" << second;
				return 0;
			}
		}
	}
}
