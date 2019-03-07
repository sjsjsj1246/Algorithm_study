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

/*
병합정렬같은 느낌으로 합쳐 올라가는 느낌?
토너먼트처럼 구간 최솟값을 계산하면서 쌓아올라가는 느낌
아니조금다르다 연속된 두개의 행렬을 선택하되 모양이 균일?하지 않아도 된다.
구간의 행렬곱 후에 만들어지는 행렬의 크기는 구간의 시작row X 구간의 끝col 이다
int cache[구간시작][구간끝] = 최솟값
탐색할때는 구간을 쪼개면서 계산해간다.
*/

vector<vector<int>> cache(501, vector<int>(501, -1));
vector<pair<int, int>> m; //matrix<row,col>

int pro(pair<int, int>a, pair<int, int>b) //matrix product
{
	return a.first*a.second*b.second;
}

int solve(int s, int e)
{
	int &ret = cache[s][e];
	if (ret != -1) return ret;
	if (s >= e) return ret = 0;
	if (e - s == 1) return ret = pro(m[s], m[e]);
	ret = INF;
	for (int i = 0; i < e - s; i++)
	{
		ret = min(ret,
			pro({ m[s].first,m[s + i].second }, { m[s + i + 1].first, m[e].second })
			+ solve(s, s + i) + solve(s + i + 1, e));
	}
	return ret;
}

int main()
{
	FAST;
	int n;
	cin >> n;
	m = vector<pair<int, int>>(n);
	FOR(i, 0, n) cin >> m[i].first >> m[i].second;
	cout << solve(0, n - 1);
}