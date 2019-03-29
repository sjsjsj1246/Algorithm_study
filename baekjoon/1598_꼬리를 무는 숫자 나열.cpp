#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
#define CASES(t) int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	int a, b;
	cin >> a >> b;
	a--, b--;
	int ax = a / 4;
	int ay = a % 4;
	int bx = b / 4;
	int by = b % 4;

	cout << abs(ax - bx) + abs(ay - by);
}