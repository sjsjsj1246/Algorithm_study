#pragma region preset_for_PS
// need
#include <iostream>
#include <algorithm>
// data structure
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <array>
// stream
#include <istream>
#include <sstream>
#include <ostream>
// etc
#include <cstdlib>
#include <cmath>
#include <functional>
#include <chrono>
#include <random>
#include <cstring>
using namespace std;
typedef long long int ll;
// input
#define ALL(a) (a).begin(),(a).end()
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,-1,sizeof(a))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << a << "\n";
// output
#define SP << " "
#define BR << "\n"
#define SPBR(i, n) <<(i + 1 == n ? '\n' : ' ');
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(a);std::cerr << #a << "\t:";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}
// utility
#define FOR(w, a, n) for(int w=(a);w<(n);++w)
#define RFOR(w, a, n) for(int w=(n)-1;w>=(a);--w)
#define ITR(it, vec) for(auto it = vec.begin(); it!= vec.end(); it++)
#define RITR(it, vec) for(auto it = vec.rbegin(); it!= vec.rend(); it++)
template<typename S, typename T>
std::ostream& operator<<(std::ostream& os, std::pair<S, T> p) {
	os << "(" << p.first << ", " << p.second << ")"; return os;
}
#pragma endregion

const int MINF = -200000;
int n, m;
int dp[1001][1001][3];
int Map[1001][1001];
bool visit[1001][1001];
int dx[] = { 0,0,1 };
int dy[] = { 1,-1,0 };

int solve(int x, int y, int d)
{
	if (x == n - 1 && y == m - 1) return Map[x][y];
	int &ret = dp[x][y][d];
	if (ret != MINF) return ret;
	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny]) continue;

		visit[nx][ny] = 1;
		ret = max(ret, solve(nx, ny, i) + Map[x][y]);
		visit[nx][ny] = 0;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Map[i][j];
			dp[i][j][0] = MINF;
			dp[i][j][1] = MINF;
			dp[i][j][2] = MINF;
		}
	}
	visit[0][0] = 1;
	cout << solve(0, 0, 0);
}

//-----------------------------------
//참고
#include <stdio.h>
#include <algorithm>

#define mval (-100*1000*1002)

using namespace std;

int e[1003][1003];
int dp[1003][1003][2];

int n, m;

int dy(int i, int j, int d) {

	if (i > n)return mval;
	if (i == n && j == m)return e[i][j];
	if (i == n && d == 0)return mval;
	int &ret = dp[i][j][d];
	if (ret != -1)return ret;

	ret = mval;

	if (d) {
		// right
		if (j < m)ret = e[i][j] + dy(i, j + 1, d);
	}
	else {
		// left
		if (j > 1)ret = e[i][j] + dy(i, j - 1, d);
	}

	ret = max(ret, e[i][j] + max(dy(i + 1, j, 0), dy(i + 1, j, 1)));

	return ret;

}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &e[i][j]);
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	printf("%d\n", max(dy(1, 1, 0), dy(1, 1, 1)));

}