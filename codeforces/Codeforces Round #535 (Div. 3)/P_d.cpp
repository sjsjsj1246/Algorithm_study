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
using PAIR = std::pair<int, int>;
using PAIRLL = std::pair<ll, ll>;

// input
#define ALL(a) (a).begin(),(a).end()
#define ZERO(a) memset(arr,0,sizeof(arr))
#define MINUS(a) memset(arr,-1,sizeof(arr))
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define INF 987654321
#define SUB(a) cout << arr << "\n";
// output
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
/**
 * 인접한 문자를 다르게 만드는 최소 변경 횟수
 */ 


int main()
{

}