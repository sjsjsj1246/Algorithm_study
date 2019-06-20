#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 187654321
typedef long long ll;
using namespace std;

struct point
{
	int x, y, z;
	bool operator==(point op)
	{
		return x == op.x && y == op.y && z == op.z;
	}
};

int main()
{
	FAST;
	point a, c;
	cin >> a.x >> a.y >> a.z;
	cin >> c.x >> c.y >> c.z;
	for (int i = 1; i < 101; i++)
	{
		for (int j = 1; j < 101; j++)
		{
			for (int k = 1; k < 101; k++)
			{
				point temp = { a.z + i,a.y * j,a.x + k };
				if (temp == c)
				{
					cout << i << " " << j << " " << k << "\n";
					return 0;
				}
			}
		}
	}
}