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
#define SUB(a) cout << a << "\n";
//----------------------------------------------------------

struct person
{
	int score, country, id;
	person(int country, int id, int score) : country(country), score(score), id(id) {}
	bool operator< (const person op)
	{
		return this->score < op.score;
	}
};

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	vector<string> s;
	FOR(i, n)
	{
		string temp, temp2;
		cin >> temp;
		for (auto c : temp) temp2 += c, temp2 += c;
		s.push_back(temp2);
	}
	bool flag = 1;
	FOR(i, n)
	{
		string temp;
		cin >> temp;
		if (s[i] != temp) flag = 0;
	}
	if (flag) cout << "Eyfa";
	else cout << "Not Eyfa";
}