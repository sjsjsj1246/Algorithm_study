#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <functional>
#include <queue>
#include <algorithm>
#define MOD 1000000
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main() 
{
	fast;
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, cnt = 0;
		cin >> n >> m;
		queue<pair<int,int>> arr;
		vector<int> list(n);
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			list[i] = temp;
			arr.push({ temp,i });
		}
		sort(list.begin(), list.end(), desc);
		while (1)
		{
			pair<int,int> temp = arr.front();
			if (temp.first == list[cnt])
			{
				cnt++;
				if (temp.second == m)
				{
					cout << cnt << "\n";
					break;
				}
				arr.pop();
				continue;
 			}
			arr.pop();
			arr.push(temp);
		}
	}
}