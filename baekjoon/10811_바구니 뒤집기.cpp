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
#include <ctime>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 45678
//----------------------------------------------------------

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	FOR(i, n) arr[i] = i + 1;
	FOR(i, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		while (a < b)
		{
			swap(arr[a], arr[b]);
			a++;
			b--;
		}
	}
	ITR(it, arr) cout << *it << " ";
}