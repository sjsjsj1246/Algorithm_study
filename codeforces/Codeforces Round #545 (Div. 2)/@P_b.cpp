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

// 1차 공연사 선택, 2차는 나머지
// 1차에 c를 공연한 사람의 수와 2차에 a를 공연한 사람의 수가 같아야 한다.

int n;
const int maxn = 100000;
char s[maxn + 10], t[maxn + 10];
vector<int> a, b, c, d;

int main() {
	scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);
	for (int i = 1; i <= n; ++i)
		if (s[i] == '0' && t[i] == '0') a.push_back(i);
		else if (s[i] == '1' && t[i] == '0') b.push_back(i);
		else if (s[i] == '0' && t[i] == '1') c.push_back(i);
		else if (s[i] == '1' && t[i] == '1') d.push_back(i);
	for (int i = 0; i <= (int)b.size(); ++i)
		for (int j = 0; j <= (int)d.size(); ++j) {
			int s = (int)c.size() - i - 2 * j + (int)d.size();
			if (s >= 0 && s <= (int)c.size()) {
				int all = i + s + j;
				int k = n / 2 - all;
				if (k >= 0 && k <= (int)a.size()) {
					for (int p = 0; p < k; ++p) printf("%d ", a[p]);
					for (int p = 0; p < i; ++p) printf("%d ", b[p]);
					for (int p = 0; p < s; ++p) printf("%d ", c[p]);
					for (int p = 0; p < j; ++p) printf("%d ", d[p]);
					return 0;
				}
			}
		}
	printf("-1");
}