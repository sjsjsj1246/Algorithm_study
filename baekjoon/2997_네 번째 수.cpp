#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> arr = { a,b,c };
	sort(arr.begin(), arr.end());
	if (arr[2] - arr[1] == arr[1] - arr[0]) cout << arr[2] + arr[1] - arr[0];
	else
	{
		int four = arr[1] + arr[1] - arr[0];
		if (arr[2] - four == arr[1] - arr[0]) cout << four;
		else cout << arr[0] + arr[2] - arr[1];
	}
}