#include <iostream>
#include <cstring>
using namespace std;

int n, d, p, t, target;
double dp[101][51];
bool connect[51][51];
int concount[51];

double memo(int day, int current)
{
	if (day == d)
	{
		if (current == target) return 1;
		else return 0;
	}
	double &ret = dp[day][current];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (connect[current][i])
			ret += (1.0 / concount[current]) * memo(day + 1, i);
	}
	return ret;
}

int main()
{
	int c; cin >> c;
	while (c--)
	{
		for (int i = 0; i < 101; i++)
		{
			for (int j = 0; j < 51; j++)
				dp[i][j] = (double)-1;
		}
		for (int i = 0; i < 51;i++)
		{
			for (int j = 0; j < 51; j++)
				connect[i][j] = 0;
		}
		for (int i = 0; i < 51; i++)
			concount[i] = 0;
		cin >> n >> d >> p;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> connect[i][j];
				if (connect[i][j]) concount[i]++;
			}
		}
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			cin >> target;
			for (int i = 0; i < 101; i++)
			{
				for (int j = 0; j < 51; j++)
					dp[i][j] = (double)-1;
			}
			printf("%.8f ", memo(0, p));
		}
		printf("\n");
	}
}