#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int a;cin>>a;for(int t=1;t<=a;t++)
typedef long long ll;
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	FAST;
	CASES(t)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		ll sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << "\n";
	}
}