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
	int n;
	string s;
	cin >> n >> s;

	vector<string> pattern = { "ABC", "BABC", "CCAABB" };
	vector<string> name = { "Adrian", "Bruno", "Goran" };
	vector<int> res(3, 0);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == pattern[0][i % 3]) res[0]++;
		if (s[i] == pattern[1][i % 4]) res[1]++;
		if (s[i] == pattern[2][i % 6]) res[2]++;
	}

	int Max = 0;
	for (int i = 0; i < 3; i++) Max = max(Max, res[i]);
	cout << Max << "\n";
	for (int i = 0; i < 3; i++) if (res[i] == Max) cout << name[i] << "\n";
}