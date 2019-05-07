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
#define ALL(a) (aa).begin(),(aa).end()
#define ZERO(a) memset(aa,0,sizeof(aa))
#define MINUS(a) memset(aa,-1,sizeof(aa))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << aa << "\n";
// output
#define SP << " "
#define BR << "\n"
#define SPBR(i, n) <<(i + 1 == n ? '\n' : ' ');
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWQUEUE(a) {auto tmp(aa);std::cerr << #a << "\t:";while(!tmp.empty()){std::cerr << tmp.front() << " ";tmp.pop();}std::cerr << "\n";}
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

int pre_max_num[3], pre_min_num[3];
int max_sum[3], min_sum[3];

int main()
{
	int n;
	cin >> n;
	FOR(i, 0, 3) cin >> pre_max_num[i], pre_min_num[i] = pre_max_num[i];
	if (n == 1)
	{
		cout << *max_element(pre_max_num, pre_max_num + 3)SP << *min_element(pre_min_num, pre_min_num + 3);
		return 0;
	}
	FOR(i, 0, n - 1)
	{
		FOR(i, 0, 3) cin >> max_sum[i], min_sum[i] = max_sum[i];

		max_sum[0] += max(pre_max_num[0], pre_max_num[1]);
		max_sum[1] += max({ pre_max_num[0], pre_max_num[1], pre_max_num[2] });
		max_sum[2] += max(pre_max_num[1], pre_max_num[2]);

		min_sum[0] += min(pre_min_num[0], pre_min_num[1]);
		min_sum[1] += min({ pre_min_num[0], pre_min_num[1], pre_min_num[2] });
		min_sum[2] += min(pre_min_num[1], pre_min_num[2]);

		FOR(i, 0, 3) pre_max_num[i] = max_sum[i];
		FOR(i, 0, 3) pre_min_num[i] = min_sum[i];
	}
	cout << *max_element(max_sum, max_sum + 3)SP << *min_element(min_sum, min_sum + 3);
}