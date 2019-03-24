#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string a, b;
	cin >> a >> b;
	int a_pos, b_pos;
	bool flag = 0;
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++)
		{
			if (a[i] == b[j])
			{
				a_pos = i;
				b_pos = j;
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}

	vector<vector<char>> arr(b.length(), vector<char>(a.length(),'.'));
	for (int i = 0; i < a.length(); i++)
	{
		arr[b_pos][i] = a[i];
	}
	for (int i = 0; i < b.length(); i++)
	{
		arr[i][a_pos] = b[i];
	}

	for (int i = 0; i < b.length(); i++)
	{
		for (int j = 0; j < a.length(); j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
}