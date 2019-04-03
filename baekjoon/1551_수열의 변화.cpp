#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int a; cin >> a; for(int t=1;t<=a;t++)
#define MOD 1000000007
#define INF 987654321
using namespace std;

int main()
{
	FAST;
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	string s;
	cin >> s;
	
	while (s.find(",") != string::npos)
	{
		string temp = s.substr(0, s.find(","));
		arr.push_back(stoi(temp));
		s = s.substr(s.find(",") + 1, s.length());
	}
	arr.push_back(stoi(s));
	
	FOR(i, 0, k)
	{
		FOR(j, 0, n - i - 1)
		{
			arr[j] = arr[j + 1] - arr[j];
		}
	}

	FOR(i, 0, n - k)
	{
		cout << arr[i];
		if (i != n - k - 1) cout << ",";
	}
}