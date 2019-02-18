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

struct TIME
{
	int h, m, s;
	TIME(int h,int m,int s) : h(h), m(m), s(s){}
	void operator - (TIME op)
	{
		this->s -= op.s;
		if (this->s < 0) this->m--, s += 60;
		this->m -= op.m;
		if (this->m < 0) this->h--, m += 60;
		this->h -= op.h;
	}
	void print()
	{
		cout << this->h << " " << this->m << " " << this->s << "\n";
	}
};

int main()
{
	FAST;
	FOR(t, 3)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		TIME x(a, b, c);
		TIME y(d, e, f);
		y - x;
		y.print();
	}
}