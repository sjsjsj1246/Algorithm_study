#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <random>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;
typedef long long int LL;

#define FOR(x,to) for(int x=0;x<(to);x++)
#define ITR(x, arr) for(auto x = arr.begin(); x!= arr.end(); x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << a << "\n";
//----------------------------------------------------------

const int MAX = 500000;
int arr[MAX];
int visited[8001];

int main()
{
	FAST;
	int N;
	cin >> N;
	float sum = 0;
	int maxNum = -4000, minNum = 4000;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		visited[arr[i] + 4000]++;
		maxNum = max(maxNum, arr[i]);
		minNum = min(minNum, arr[i]);
	}
	float average = sum / N;
	if (average >= 0)
		cout << int(average + 0.5) << "\n";
	else
		cout << int(average - 0.5) << "\n";
	sort(arr, arr + N);
	cout << arr[N / 2] << "\n";
	int num = -1;
	int cur = 0;
	bool second = false;
	for (int i = 0; i <= 8000; i++)
		if (cur < visited[i])
		{
			cur = visited[i];
			num = i;
			second = false;
		}
		else if (cur == visited[i] && !second)
		{
			num = i;
			second = true;
		}
	cout << num - 4000 << "\n";
	cout << maxNum - minNum << "\n";
}