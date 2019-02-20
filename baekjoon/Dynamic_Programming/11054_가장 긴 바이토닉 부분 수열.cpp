#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
#define MOD 1000000000
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;

/*
11054 가장 긴 바이토닉 부분 수열
dp, bottom-up
L[n] R[n] :  왼쪽, 오른쪽에 위치한 n번째 수보다 작은(순차적으로) 수의 개수
ans = max(L[i]+R[i]+1)
*/

int L[1001], R[1001], arr[1001];

int main()
{
	int n, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				if (L[i] < L[j] + 1) L[i] = L[j] + 1;
			}
		}
	}
	for (int i = n-1; i >=0 ; i--)
	{
		for (int j = n-1; j > i; j--)
		{
			if (arr[j] < arr[i])
			{
				if (R[i] < R[j] + 1) R[i] = R[j] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (max < L[i] + R[i] + 1) max = L[i] + R[i] + 1;
	}
	cout << max;
}