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
#define SP std::cout << " "
#define BR std::cout << "\n"
#define SPBR(i, n) std::cout<<(i + 1 == n ? '\n' : ' ');
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
//----------------------------------------------------------
/*
DP top-down
분명히 쪼개는 문제일 것이다.
구간이 주어질때 구간내 비용의 최솟값을 저장하자
*/

int dp[501][501];
int cost[501];
int sum[501];

int solve(int start, int end) 
{
	int& ret = dp[start][end];
	if (ret != INF) return ret;
	if (start == end) return ret= 0;
	if (start + 1 == end) return ret = cost[start] + cost[end];

	for (int mid = start; mid < end; ++mid) 
	{
		ret = min(ret, solve(start, mid) + solve(mid + 1, end));
	}
	return ret += sum[end] - sum[start - 1];
}

int main() 
{
	FAST;
	CASES(t)
	{
		int n;
		cin >> n;
		FOR(i, 0, n + 1) FOR(j, 0, n + 1) dp[i][j] = INF;
		FOR(i, 1, n + 1) cin >> cost[i], sum[i] = sum[i - 1] + cost[i];
		SUB(solve(1,n));
	}
}


//------------------------------------------
//bottom-up

int dp[501][501];
int cost[501];
int sum[501];

int main()
{
	FAST;
	CASES(t)
	{
		int n;
		cin >> n;
		FOR(i, 1, n + 1) cin >> cost[i], sum[i] = sum[i - 1] + cost[i];

		for (int i = 1; i < n; i++)
		{
			for (int start = 1; start + i <= n; start++)
			{
				int end = start + i;
				dp[start][end] = INF;

				for (int mid = start; mid < end; mid++)
					dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]);
			}
		}
		SUB(dp[1][n]);
	}
}