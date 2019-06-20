#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define FOR(ww, aa, nn) for(int ww=(aa);ww<(nn);++ww)
#define ALL(aa) (aa).begin(),(aa).end()
#define CASES(tt) int aa; cin >> aa; for(int tt=1;tt<=aa;tt++)
#define MOD 10007
#define INF 187654321
typedef long long ll;
using namespace std;

struct hi
{
	int x, y, z;
};

int main()
{
	FAST;
	int n;
	cin >> n;
	int adj[21][21];
	int temp[21][21];
	bool check[21][21] = {0};	
	FOR(i, 0, n) FOR(j, 0, n) cin >> adj[i][j], temp[i][j] = adj[i][j];

	FOR(k, 0, n)
	{
		FOR(i, 0, n)
		{
			if (i == k) continue;
			FOR(j, 0, n)
			{
				if (i == j || k == j) continue;
				if (adj[i][j] > adj[i][k] + adj[k][j])
				{
					cout << -1;
					return 0;
				}
				if (adj[i][j] == adj[i][k] + adj[k][j])
					temp[i][j] = 0;
			}
		}
	}
	int sum = 0;
	FOR(i, 0, n) 
		FOR(j, 0, n) 
			if (temp[i][j] != 0 && !check[i][j]) 
				sum += adj[i][j], check[i][j] = 1, check[j][i] = 1;
	cout << sum;
}