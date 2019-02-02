#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <string>
using namespace std;
typedef signed long long LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//-------------------------------------------------------

int n, k;
int arr[10001];

int main()
{
	FAST;
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = i ; j <= n; j++)
		{
			if (arr[j] - arr[i - 1] == m) ans++;
		}
	}
	cout << ans;
}

/*
참고 코드
#include<cstdio>
int i;
int sum;
int dap;
int left;
int main()
{
    int n, m, a[10005];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		sum += a[i];
		while (sum > m)
		sum -= a[left++];

		dap += sum == m;
	}
	printf("%d\n", dap);
}
*/