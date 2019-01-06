#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321, MAXN = 12;
int c, n, k, m, l;//n:전공과목수 k:들어야할과목의수 m:학기의수 l:최대로들을수있는과목의수
int prerequisite[MAXN];
int classes[10];
int cache[10][1 << MAXN];
int bitcount(int n)
{
	if (n == 0)return 0;
	return n % 2 + bitcount(n / 2);
}
int graduate(int semester, int taken)
{
	if (bitcount(taken) >= k)return 0;
	if (semester == m) return INF;
	int &ret = cache[semester][taken];
	if (ret != -1)return ret;
	ret = INF;
	int canTake = (classes[semester] & ~taken);
	for (int i = 0; i < n; i++)
	{
		if ((canTake&(1 << i)) && (taken&prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	}
	for (int take = canTake; take>0; take = ((take - 1)&canTake))
	{
		if (bitcount(take) > l) continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}

int main()
{
	cin >> c;
	while (c--)
	{
		memset(cache, -1, sizeof(cache));
		memset(prerequisite, 0, sizeof(prerequisite));
		memset(classes, 0, sizeof(classes));
		cin >> n >> k >> m >> l;
		for (int i = 0; i < n; i++)
		{
			int r; cin >> r;
			for (int j = 0; j < r; j++)
			{
				int temp; cin >> temp;
				prerequisite[i] |= (1 << temp);
			}
		}
		for (int i = 0; i < m; i++)
		{
			int r; cin >> r;
			for (int j = 0; j < r; j++)
			{
				int temp; cin >> temp;
				classes[i] |= (1 << temp);
			}
		}
		int taken = 0;
		int res = graduate(0, taken);
		if (res == INF) cout << "IMPOSSIBLE\n";
		else cout << res << "\n";
	}
}