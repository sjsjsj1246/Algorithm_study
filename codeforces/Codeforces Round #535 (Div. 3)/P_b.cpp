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
typedef signed long long ll;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

/*
큰 수의 약수를 전부 제거한 후 나머지 가장 큰 수가 정답
*/

int main()
{
	FAST;
	int n, x;
	multiset<int> m;

	cin >> n;
	FOR(i, n) cin >> x, m.insert(x);

	x = *m.rbegin();
	for (int i = 1; i <= x; i++)
	{
		if (x%i == 0) m.erase(m.find(i));
		ITR(x, m) cout << *x << " ";
		cout << "\n";
	}

	cout << x << " " << *m.rbegin() << "\n";
}