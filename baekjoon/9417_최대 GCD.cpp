#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int aa; cin >> aa; for(int t=1;t<=aa;t++)
#define MOD 1000000007
#define INF 987654321
typedef long long ll;
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}


int main() 
{
	FAST;
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	while (t--)
	{
		getline(cin, s);
		vector<int> arr;
		while (s.find(' ') != string::npos)
		{
			arr.push_back(stoi((s.substr(0, s.find(' ')))));
			s = s.substr(s.find(' ') + 1, s.length());
		}
		arr.push_back(stoi(s));

		int n = arr.size(), ans = 0;
		FOR(i, 0, n) FOR(j, i + 1, n) ans = max(ans, gcd(arr[i], arr[j]));
		cout << ans << "\n";
	}
}