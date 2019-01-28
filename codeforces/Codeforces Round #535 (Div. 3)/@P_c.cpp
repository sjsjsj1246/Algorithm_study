#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
#include <queue>
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int LL;
using namespace std;

bool con(int a, int b) { return a > b; };

vector<int> getD(int x)
{
	vector<int> ret;
	for (int i = 2; i < x; i++)
	{
		if (x%i == 0) 
		{
			ret.push_back(i);
		}
	}
	return ret;
}

void print(vector<int> arr)
{
	for (int x : arr) cout << x <<" ";
	cout << "\n";
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end(), con);
	while (1)
	{
		vector<int> divi = getD(arr[0]);
		for (int x : divi)
		{
			auto it = find(arr.begin(), arr.end(), x);
			if(it!=arr.end()) arr.erase(it);
			if (arr.size() == 4) break;
		}
		if (arr.size() == 4) break;
	}
	cout << arr[0]<<" "<< arr[1];
}