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

bool check[1001];

int main()
{
	int sum = 0;
	string a, b;
	cin >> a >> b;
	
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++)
		{
			if (check[j]) continue;
			if (a[i] == b[j])
			{
				sum++;
				check[j] = 1;
				break;
			}
		}
	}
	for (auto i : check) if (i) sum++;
	cout << a.length() + b.length() - sum;
}