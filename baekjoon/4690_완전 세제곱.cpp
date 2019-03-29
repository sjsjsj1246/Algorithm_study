#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
typedef long long ll;
using namespace std;

int main()
{
	FAST;
	for (int i = 2; i <= 100; i++)
	{
		for (int j = 2; j <= 100; j++)
		{
			for (int k = j + 1; k <= 100; k++)
			{
				for (int l = k + 1; l <= 100; l++)
				{
					if (i*i*i == j*j*j + k*k*k + l*l*l)
					{
						cout << "Cube = " << i << ", Triple = (" << j << "," << k << "," << l << ")\n";
					}
				}
			}
		}
	}
}