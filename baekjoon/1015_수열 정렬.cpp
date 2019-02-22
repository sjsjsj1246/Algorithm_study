#include <iostream>
#include <cstring>
#include <cstdio>
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

int B[51];

int main()
{
	FAST;
	int n, temp;
	cin >> n;
	vector<pair<int, int>> arr;
	FOR(i, n) cin >> temp, arr.push_back({ temp, i });
	sort(ALL(arr));
	FOR(i, n) B[arr[i].second] = i;
	FOR(i, n) cout << B[i] << " ";
}