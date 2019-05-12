#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int main() 
{
	FAST;
	string s;
	cin >> s;
	set<string> Set;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < s.length(); j++)
		{
			Set.insert(s.substr(i, j - i));
		}
	}
	cout << Set.size();
}