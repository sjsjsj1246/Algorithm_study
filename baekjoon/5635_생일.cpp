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

struct person
{
	string name;
	int y, m, d;
	person(string name ,int y, int m, int d) : name(name), y(y), m(m), d(d) {};
	bool operator < (person op)
	{
		if (this->y < op.y) return 1;
		else if (this->y == op.y)
		{
			if (this->m < op.m) return 1;
			else if (this->m == op.m)
			{
				if (this->d < op.d) return 1;
				else return 0;
			}
		}
		return 0;
	}
};

int main()
{
	FAST;
	string name;
	int y, m, d;
	int t;
	cin >> t;
	vector<person> arr;
	while(t--)
	{
		cin >> name >> d >> m >> y;
		arr.push_back(person(name, y, m, d));
	}
	sort(ALL(arr));
	cout << arr.back().name << "\n" << arr[0].name;
}