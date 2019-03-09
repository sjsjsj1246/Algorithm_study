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

const int MAX = 32000;

int main()
{
	FAST;
	vector<bool> is_prime(MAX, 1);
	vector<int> prime(1, 2);
	for (int i = 4; i<MAX; i += 2)
		is_prime[i] = false;
	for (int i = 3; i<MAX; i += 2) 
	{
		if (!is_prime[i]) continue;
		prime.push_back(i);
		for (int j = i * i; j<MAX; j += i * 2)
			is_prime[j] = false;
	}

	while (1) 
	{
		int n;
		cin >> n;
		if (n == 0) break;
		if (n == 1) 
		{
			SUB(0);
			continue;
		}

		vector<pair<int,int>> f;
		for (int i = 0; i<prime.size() && n>1; i++) 
		{
			int cnt = 0;
			while (n%prime[i] == 0) 
			{
				cnt++;
				n /= prime[i];
			}
			if (cnt > 0) f.push_back(pair<int,int>(prime[i], cnt));
		}
		if (n > 1) f.push_back(pair<int,int>(n, 1));

		int result = 1;
		for (auto &k : f) 
		{
			int a = k.first, b = 1;
			for (int i = 1; i<k.second; i++) 
			{
				b = a;
				a = b * k.first;
			}
			result *= a - b;
		}
		SUB(result);
	}
}