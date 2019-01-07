#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 987654321
#define fast ios::sync_with_stdio(false); cin.tie(0);
typedef long long int LL;
using namespace std;

//brute force 재귀함수로 풀어보자 dfs

int Min = 1000000000, Max = -1000000000;
vector<int> arr;

void calc(int n, vector<int> opera, int pos, int ans)
{
	if (pos == n - 1)
	{
		if (Max < ans) Max = ans;
		if (Min > ans) Min = ans;
		return;
	}
	if (opera[0] != 0) { opera[0]--; calc(n, opera, pos + 1, ans + arr[pos + 1]); opera[0]++; }
	if (opera[1] != 0) { opera[1]--; calc(n, opera, pos + 1, ans - arr[pos + 1]); opera[1]++; }
	if (opera[2] != 0) { opera[2]--; calc(n, opera, pos + 1, ans * arr[pos + 1]); opera[2]++; }
	if (opera[3] != 0) { opera[3]--; calc(n, opera, pos + 1, ans / arr[pos + 1]); opera[3]++; }
}

int main()
{
	fast;
	int n;
	cin >> n;
	vector<int> opera(4); // + - * /
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < 4; i++)
	{
		int temp;
		cin >> temp;
		opera[i] = temp;
	}
	calc(n, opera, 0, arr[0]);
	cout << Max << "\n" << Min;
}