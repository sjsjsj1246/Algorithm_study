#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000000
using namespace std;

int main()
{
	int t;
	cin >> t;
	int g[] = { 1,2,3,3,4,10 };
	int s[] = { 1,2,2,2,3,5,10 };
	for (int i = 1; i <= t; i++)
	{
		int gg = 0;
		int ss = 0;
		int temp;
		for (int j = 0; j < 6; j++)
		{
			cin >> temp;
			gg += temp*g[j];
		}
		for (int j = 0; j < 7; j++)
		{
			cin >> temp;
			ss += temp*s[j];
		}
		if (gg > ss)
			printf("Battle %d: Good triumphs over Evil\n", i);
		else if (gg < ss)
			printf("Battle %d: Evil eradicates all trace of Good\n", i);
		else
			printf("Battle %d: No victor on this battle field\n", i);
	}
	return 0;
}