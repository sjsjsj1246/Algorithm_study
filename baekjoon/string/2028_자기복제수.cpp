#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000000
#define INF 987654321
typedef long long ll;
using namespace std;

int main() 
{
	FAST;
	CASES(t)
	{
		int n;
		cin >> n;
		string n1 = to_string(n*n);
		string n2 = to_string(n);
		
		if (n1.substr(n1.length()-n2.length(), n2.length()) == n2) cout << "YES\n";
		else cout << "NO\n";
	}
}