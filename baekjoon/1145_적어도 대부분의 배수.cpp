#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
typedef long long ll;
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	FAST;
	int Min = 987654321;
	vector<int> arr(5);
	for (int i = 0; i < 5; i++) cin >> arr[i];
	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 5; j++)
		{
			for (int k = j+1; k < 5; k++)
			{
				int a, b, c;
				a = arr[i];
				b = arr[j];
				c = arr[k];
				int temp = a * b / gcd(a, b);
				Min = min(Min, temp*c/gcd(temp,c));
			}
		}
	}
	cout << Min;
}