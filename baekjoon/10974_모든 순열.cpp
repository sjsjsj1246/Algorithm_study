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

void print(vector<int> &arr)
{
	ITR(i, arr) cout << *i << " ";
	cout << "\n";
}

int main()
{
	FAST;
	int n;
	cin >> n;
	vector<int> arr(n);
	FOR(i, n) arr[i] = i + 1;
	print(arr);
	while(next_permutation(ALL(arr)))
		print(arr);
}