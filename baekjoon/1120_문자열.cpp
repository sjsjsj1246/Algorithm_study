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

int main() 
{
	string a, b;
	cin >> a >> b;
	int Min = 51;
	int len = b.length() - a.length() + 1;
	for (int i = 0; i < len; i++)
	{
		int sum = 0;
		for (int j = 0; j < a.length(); j++)
		{
			if (a[j] != b[j + i]) sum++;
		}
		if (Min > sum) Min = sum;
	}
	cout << Min;
}