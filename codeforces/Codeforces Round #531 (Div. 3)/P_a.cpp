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

int L[1001], R[1001], arr[1001];

int main()
{
	LL n;
	cin >> n;
	cout << n * (n + 1) / 2 % 2;
}