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

struct person
{
	int kor, eng, math;
	string name;
	person(string name, int kor, int eng, int math) : name(name), kor(kor), eng(eng), math(math) {};
	bool operator< (person op)
	{
		if (this->kor > op.kor) return 1;
		else if (this->kor == op.kor)
		{
			if (this->eng < op.eng) return 1;
			else if (this->eng == op.eng)
			{
				if (this->math > op.math) return 1;
				else if (this->math == op.math)
				{
					return this->name < op.name;
				}
				else return 0;
			}
			else return 0;
		}
		else return 0;
	}
};

int main()
{
	FAST;
	int n;
	cin >> n;
	string s;
	int temp1, temp2, temp3;
	vector<person> arr;
	FOR(i, n) cin >> s >> temp1 >> temp2 >> temp3, arr.push_back(person(s, temp1, temp2, temp3));
	sort(ALL(arr));
	for (auto x : arr) cout << x.name << "\n";
}