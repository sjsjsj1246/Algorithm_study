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

int main()
{
	FAST;
	char board[51][51];
	string s;
	int n, m, min_sum = 987654321;
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> s;
		FOR(j, 0, m)
		{
			board[i][j] = s[j];
		}
	}
	FOR(i, 0, n-7)
	{
		FOR(j, 0, m-7)
		{
			int w_cnt = 0;
			int b_cnt = 0;
			FOR(x, i, i + 8)
			{
				FOR(y, j, j + 8)
				{
					if (x % 2)
					{
						if (y % 2)
						{
							if (board[x][y] == 'W') w_cnt++;
							if (board[x][y] == 'B') b_cnt++;
						}
						else
						{
							if (board[x][y] == 'W') b_cnt++;
							if (board[x][y] == 'B') w_cnt++;
						}
					}
					else
					{
						if (y % 2)
						{
							if (board[x][y] == 'W') b_cnt++;
							if (board[x][y] == 'B') w_cnt++;
						}
						else
						{
							if (board[x][y] == 'W') w_cnt++;
							if (board[x][y] == 'B') b_cnt++;
						}
					}
				}
			}
			min_sum = min(min_sum, min(64 - w_cnt, 64 - b_cnt));
		}
	}
	cout << min_sum;
}