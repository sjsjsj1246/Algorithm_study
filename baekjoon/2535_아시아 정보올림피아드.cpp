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
	int n;
	cin >> n;
	vector<person> arr;
	vector<int> check(n+1, 0);
	FOR(i, n)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back(person(a, b, c));
	}
	sort(ALL(arr));
	int cnt = 0;
	for (auto it = arr.rbegin(); it != arr.rend(); it++)
	{
		if (cnt == 3) return 0;
		if (check[(*it).country] > 1) continue;
		cout << (*it).country << " " << (*it).id << "\n";
		check[(*it).country]++;
		cnt++;
	}
}