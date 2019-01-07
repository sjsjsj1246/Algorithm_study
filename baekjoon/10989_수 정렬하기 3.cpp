#include <iostream>
using namespace std;

int cnt[10001];

int main()
{
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp;
		cnt[temp]++;
	}
	for (int i = 0; i < 10001; i++)
		if (cnt[i])
			for (int j = 0; j < cnt[i]; j++)
				cout << i << "\n";
}